#include<iostream>
#include<cmath>
#include<algorithm>
#define MOD 1000000009
using namespace std;
int T,n,sol,lg;
int A[100100],mount[100100];
struct Element
{
    int nr[2],poz;
     
    inline bool operator < (const Element &A) const {
        if (nr[0] == A.nr[0])
            return nr[1] < A.nr[1];
        return nr[0] < A.nr[0];
    }
  
    inline bool operator == (const Element &A) const {
        return (nr[0] == A.nr[0] && nr[1] == A.nr[1]);
    }
};
Element v[100100];
int Poz[19][100100],arrays[100100];
 
inline int PrefixComun(int x,int y)
{
    if(x==y)
        return n-x;
    int k=lg,rez=0;
    while(k>=0 && x<n && y<n)
    {
        if(Poz[k][x]==Poz[k][y])
        {
            x+=(1<<k);
            y+=(1<<k);
            rez+=(1<<k);
        }
        k--;
    }
    return rez;
}
 
int main()
{
    int i,k;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>A[i];
		if(n==1)
		{
			cout<<"0\n";
			continue;
		}
		if(n==2)
		{
			cout<<"1\n";
			continue;
		}
		n--;
		for(i=0;i<n;i++)
			Poz[0][i]=A[i]-A[i+1]+1000100;
		lg=0;
		while((1<<lg)<n)
			lg++;
		for(i=0;i<n;i++)
			v[i].poz=i;
		for(k=1;k<=lg;k++) 
		{
			for(i=0;i<n;i++)
			{
				v[i].nr[0]=Poz[k-1][v[i].poz];
				if(v[i].poz+(1<<(k-1))<n)
					v[i].nr[1]=Poz[k-1][v[i].poz+(1<<(k-1))];
				else
					v[i].nr[1]=-1;
			}
			sort(v,v+n);
			Poz[k][v[0].poz]=0;
			for(i=1;i<n;i++)
			{
				if(v[i]==v[i-1])
					Poz[k][v[i].poz]=Poz[k][v[i-1].poz];
				else
					Poz[k][v[i].poz]=i;
			}
		}
		for(i=0;i<n;i++)
			arrays[Poz[lg][i]]=i;
		for(i=0;i+1<n;i++)
		{
			sol+=(n-arrays[i])-PrefixComun(arrays[i],arrays[i+1]);
			if(sol>=MOD)
				sol-=MOD;
		}
		sol+=(n-arrays[n-1]);
		if(sol>=MOD)
			sol-=MOD;
		cout<<sol<<"\n";
		sol=0;
		for(k=0;k<=lg;k++)
			for(i=0;i<n;i++)
				Poz[k][i]=0;
		for(i=0;i<n;i++)
			v[i].poz=v[i].nr[0]=v[i].nr[1]=0;
	}
    return 0;
}
