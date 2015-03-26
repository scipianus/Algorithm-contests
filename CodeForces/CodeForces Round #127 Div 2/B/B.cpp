#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,ns[12],inv[12],ind[6];
string cuv[6],prob[12][22];
bool uz[6];

inline void Search()
{
	int i,j,inv_now=0,gasit;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(ind[i]>ind[j])
				inv_now++;
		}
	}
	for(i=1;i<=m;i++)
	{
		gasit=1;
		for(j=1;j<=ns[i];j++)
		{
			if(gasit>n)
				continue;
			if(prob[i][j]==cuv[ind[gasit]])
				gasit++;
		}
		if(gasit==n+1)
			inv[i]=min(inv[i],inv_now);
	}
}

inline void Back(int k)
{
	if(k==n+1)
		Search();
	else
	{
		int i;
		for(i=1;i<=n;i++)
		{
			if(!uz[i])
			{
				ind[k]=i;
				uz[i]=true;
				Back(k+1);
				uz[i]=false;
			}
		}
	}
}

int main()
{
	int i,j,invmin=2000000000,P;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>cuv[i];
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>ns[i];
		for(j=1;j<=ns[i];j++)
			cin>>prob[i][j];
	}
	for(i=1;i<=m;i++)
		inv[i]=2000000000;
	
	Back(1);
	
	for(i=1;i<=m;i++)
		invmin=min(invmin,inv[i]);
	if(invmin==2000000000)
		cout<<"Brand new problem!\n";
	else
	{
		P=n*(n-1);
		P/=2;
		P=P-invmin+1;
		for(i=1;i<=m;i++)
		{
			if(inv[i]==invmin)
			{
				cout<<i<<"\n";
				break;
			}
		}
		cout<<"[:";
		for(i=1;i<=P;i++)
			cout<<"|";
		cout<<":]\n";
	}
	return 0;
}
