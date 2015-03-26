#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int pred[100100][211];
int cif[100100][211],rest[100100],rst[5000];
bool viz[100100][211];
queue <int> Q;

int main()
{
	int i,j,k,r;
	cin>>n;
	rest[0]=1;
	for(i=1;i<=n;i++)
		rest[i]=(rest[i-1]*10)%210;
	for(i=0;i<5000;i++)
		rst[i]=i%210;
	for(i=0;i<10;i++)
	{
		viz[1][i]=true;
		cif[1][i]=i;
		Q.push(i);
	}
	n--;
	for(i=1;i<n;i++)
	{
		while(!Q.empty())
		{
			j=Q.front();
			Q.pop();
			for(k=0;k<10;k++)
			{
				r=rst[j+k*rest[i]];
				if(!viz[i+1][r] || (viz[i+1][r] && cif[i+1][r]>k))
				{
					viz[i+1][r]=true;
					pred[i+1][r]=j;
					cif[i+1][r]=k;
				}
			}
		}
		for(j=0;j<210;j++)
			if(viz[i+1][j])
				Q.push(j);
	}
	n++;
	for(j=0;j<210;j++)
	{
		if(viz[i][j]==true)
		{
			for(k=1;k<10;k++)
			{
				r=rst[j+k*rest[i]];
				if(!viz[i+1][r] || (viz[i+1][r] && cif[i+1][r]>k))
				{
					viz[i+1][r]=true;
					pred[i+1][r]=j;
					cif[i+1][r]=k;
				}
			}
		}
	}
	if(n==1)
	{
		cout<<"-1\n";
		return 0;
	}
	if(!viz[n][0])
		cout<<"-1\n";
	else
	{
		j=0;
		for(i=n;i>0;i--)
		{
			cout<<cif[i][j];
			j=pred[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
