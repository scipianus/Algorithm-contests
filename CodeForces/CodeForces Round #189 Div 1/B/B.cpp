#include<iostream>
using namespace std;
int n,A[100100],poz[100100],life[100100],sol,temp[100100];
int aib[100100],killer[100100];
bool killed[100100];

inline void Aduna(int poz,int val)
{
	while(poz<=n)
	{
		aib[poz]+=val;
		poz+=(poz & -poz);
	}
}

inline int Suma(int poz)
{
	int sum=0;
	while(poz>0)
	{
		sum+=aib[poz];
		poz-=(poz & -poz);
	}
	return sum;
}

inline int CautareBinara(int ind)
{
	int st,dr,mij,sum,S,rez=n;
	sum=Suma(A[ind]);
	st=A[ind]+1;
	dr=n;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		S=Suma(mij)-sum;
		if(S==1)
		{
			rez=min(rez,mij);
			dr=mij-1;
		}
		if(S==0)
			st=mij+1;
		if(S>1)
			dr=mij-1;
	}
	return rez;
}

int main()
{
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>A[i];
		poz[A[i]]=i;
	}
	for(i=1;i<=n;i++)
		if(A[i]!=i)
			i=n+1;
	if(i!=n+1)
	{
		Aduna(poz[n],1);
		for(i=n-1;i>0;i--)
		{
			if(Suma(poz[i]-1)>0)
				killed[i]=true;
			Aduna(poz[i],1);
		}
		for(i=1;i<=n;i++)
			aib[i]=0;
		for(i=1;i<=n;i++)
		{
			if(killed[A[i]])
				killer[A[i]]=CautareBinara(i);
			Aduna(A[i],1);
		}
		for(i=1;i<n;i++)
		{
			life[i]=1;
			for(j=0;j<poz[i];j++)
				temp[j]=0;
			temp[poz[i]]=1;
			for(j=poz[i]-1;j>poz[killer[i]];j--)
			{
				if(A[j]>A[i])
					continue;
				for(k=j+1;k<=poz[i];k++)
				{
					if(A[j]<A[k])
						temp[j]=max(temp[j],temp[k]+1);
				}
				life[i]=max(life[i],temp[j]);
			}
			if(killed[i])
				sol=max(sol,life[i]);
		}
	}
	cout<<sol<<"\n";
	return 0;
}
