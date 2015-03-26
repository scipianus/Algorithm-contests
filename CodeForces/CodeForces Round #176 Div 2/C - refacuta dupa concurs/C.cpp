#include<iostream>
#include<algorithm>
using namespace std;
int n,perm[100100];

int main()
{
	int i,j,st,dr,turn;
	cin>>n;
	if(n%4==2 || n%4==3)
		cout<<"-1\n";
	else
	{
		if(n%2==1)
		{
			perm[(n+1)/2]=(n+1)/2;
			turn=1;
			for(i=n,j=1,st=(n+1)/2-1,dr=(n+1)/2+1;st>0;st--,dr++,i--,j++)
			{
				if(turn==1)
				{
					perm[st]=i;
					perm[dr]=j;
				}
				else
				{
					perm[st]=j;
					perm[dr]=i;
				}
				turn=1-turn;
			}
		}
		else
		{
			turn=1;
			for(i=n,j=1,st=n/2,dr=n/2+1;st>0;st--,dr++,i--,j++)
			{
				if(turn==1)
				{
					perm[st]=i;
					perm[dr]=j;
				}
				else
				{
					perm[st]=j;
					perm[dr]=i;
				}
				turn=1-turn;
			}
		}
		for(i=1;i<=n;i++)
			cout<<perm[i]<<' ';
		cout<<"\n";
	}
	return 0;
}
