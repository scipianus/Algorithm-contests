#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,K,v[3000],sol[5];
char A[5][10100];
bool mat[5][5];
// 1=aabb
// 2=abab
// 3=abba
// 4=aaaa

int main()
{
	int i,j,k,nr;
	cin>>n>>K;
	for(i=1;i<=n;i++)
	{
		memset(A[1],0,sizeof(A[1]));
		memset(A[2],0,sizeof(A[2]));
		memset(A[3],0,sizeof(A[3]));
		memset(A[4],0,sizeof(A[4]));
		for(j=1;j<=4;j++)
		{
			cin>>A[j];
			nr=0;
			for(k=strlen(A[j])-1;k>=0 && nr<K;k--)
			{
				if(A[j][k]=='a' || A[j][k]=='e' || A[j][k]=='i' || A[j][k]=='o' || A[j][k]=='u')
				{
					nr++;
					if(nr==K)
					{
						strcpy(A[j],A[j]+k);
						k=-1;
					}
				}
			}
			if(nr<K)
				memset(A[j],0,sizeof(A[j]));
		}
		for(j=1;j<4;j++)
		{
			for(k=j+1;k<=4;k++)
			{
				if(strlen(A[j])==strlen(A[k]) && strcmp(A[j],A[k])==0)
					mat[j][k]=mat[k][j]=true;
			}
		}
		if(mat[1][2] && mat[1][3] && mat[1][4] && mat[2][3] && mat[3][4] && mat[2][4])
			v[i]=4;
		else
		{
			if(mat[1][3] && mat[2][4])
				v[i]=2;
			else
			{
				if(mat[1][2] && mat[3][4])
					v[i]=1;
				else
				{
					if(mat[1][4] && mat[2][3])
						v[i]=3;
					else
						v[i]=0;
				}
			}
		}
		for(j=1;j<=4;j++)
			for(k=1;k<=4;k++)
				mat[j][k]=false;
	}
	for(i=1;i<=n;i++)
		sol[v[i]]++;
	if(sol[4]==n)
	{
		cout<<"aaaa\n";
		return 0;
	}
	if(sol[1]+sol[4]==n)
	{
		cout<<"aabb\n";
		return 0;
	}
	if(sol[2]+sol[4]==n)
	{
		cout<<"abab\n";
		return 0;
	}
	if(sol[3]+sol[4]==n)
	{
		cout<<"abba\n";
		return 0;
	}
	cout<<"NO\n";
	return 0;
}
