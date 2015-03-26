#include<iostream>
#include<vector>
using namespace std;
int n,A[100100],B[100100],st[100100],dr[100100],sol;
bool viz[100100];
vector <int> G[100100];

inline bool CoPrime(int a,int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	if(a==1)
		return true;
	return false;
}

inline void Citire()
{
    int i,j;
    cin>>n;
	for(i=1;i<=n;i++)
		cin>>A[i];
	for(i=1;i<=n;i++)
	{
		cin>>B[i];
		for(j=1;j<=n;j++)
		{
			if(!CoPrime(A[j],B[i]))
				G[j].push_back(i);
		}
	}
}
 
inline bool Hopcroft_Karp(int nod)
{
    if(viz[nod]==true)
        return false;
    viz[nod]=true;
     
    vector <int>::iterator it;
    for(it=G[nod].begin();it!=G[nod].end();it++)
    {
        if(!st[*it])
        {
            st[*it]=nod;
            dr[nod]=*it;
            return true;
        }
    }
    for(it=G[nod].begin();it!=G[nod].end();it++)
    {
        if(Hopcroft_Karp(st[*it])==true)
        {
            st[*it]=nod;
            dr[nod]=*it;
            return true;
        }
    }
    return false;
}
 
inline void Rezolvare()
{
    int i;
    bool modificare=true;
    while(modificare)
    {
        modificare=false;
        for(i=1;i<=n;i++)
        {
            if(!dr[i])
            {
                if(Hopcroft_Karp(i)==true)
                    modificare=true;
            }
        }
        for(i=1;i<=n;i++)
            viz[i]=false;
    }
	for(i=1;i<=n;i++)
		if(dr[i])
			sol++;
	cout<<sol<<"\n";
}
 
int main()
{
    Citire();
    Rezolvare();
    return 0;
}
