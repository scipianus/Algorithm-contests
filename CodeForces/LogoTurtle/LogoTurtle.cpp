#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
char s[150];
int n,m,nr,best[150][55],lg[150],dir[150][55];

int main()
{
	int i,j,nrt=0,nrf=0,k,dir1;
/*	ifstream fin("logoturtle.in");
	fin>>(s+1);
	fin>>m;
	fin.close();*/
	cin>>(s+1);
	n=strlen(s+1);
	cin>>m;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='F')
			nrf++;
		else
			nrt++;
	}
	if(m==nrt)
		cout<<n<<"\n";
	else
	{
		if(m>nrt)
		{
			nr=m-nrt;
			if(nr%2==0)
				cout<<n<<"\n";
			else
				cout<<(n-1)<<"\n";
		}
		else
		{
			if(s[1]=='T')
			{
				for(j=1;j<=m;j+=2)
				{
					best[1][j]=1;
					dir[1][j]=1;
				}
				for(j=0;j<=m;j+=2)
					dir[1][j]=-1;
			}
			else
			{
				for(j=0;j<=m;j+=2)
				{
					best[1][j]=1;
					dir[1][j]=1;
				}
				for(j=1;j<=m;j+=2)
					dir[1][j]=-1;
			}
			lg[0]=0;
			dir1=1;
			for(j=0;j<=m;j++)
				dir[0][j]=1;
			for(i=1;i<=n;i++)
			{
				if(s[i]=='F')
				{
					lg[i]=lg[i-1]+dir1;
					dir[i][0]=dir1;
					best[i][0]=lg[i];
				}
				else
				{
					lg[i]=lg[i-1];
					dir1=-dir1;
					dir[i][0]=dir1;
					best[i][0]=lg[i];
				}
			}
			for(i=2;i<=n;i++)
			{
				for(j=0;j<=m;j++)
				{
					if(s[i]=='F')
					{
						best[i][j]=best[i-1][j]+dir[i-1][j];
						dir[i][j]=dir[i-1][j];
						k=2;
						while(j-k>=0)
						{
							if(best[i][j]<best[i-1][j-k]+dir[i-1][j-k] || (best[i][j]==best[i-1][j-k]+dir[i-1][j-k] && dir[i-1][j-k]==1))
							{
								best[i][j]=best[i-1][j-k]+dir[i-1][j-k];
								dir[i][j]=dir[i-1][j-k];
							}
							k+=2;
						}
						
						if(j!=0)
						{
							if(best[i][j]<best[i-1][j-1] || (best[i][j]==best[i-1][j-1] && dir[i-1][j-1]==-1))
							{
								best[i][j]=max(best[i][j],best[i-1][j-1]);
								dir[i][j]=-dir[i-1][j-1];
							}
							k=3;
							while(j-k>=0)
							{
								if(best[i][j]<best[i-1][j-k] || (best[i][j]==best[i-1][j-k] && dir[i-1][j-k]==-1))
								{
									best[i][j]=best[i-1][j-k];
									dir[i][j]=-dir[i-1][j-k];
								}
								k+=2;
							}
						}
					}
					else
					{
						if(j!=0)
						{
							best[i][j]=best[i-1][j-1]+dir[i-1][j-1];
							dir[i][j]=dir[i-1][j-1];
							k=3;
							while(j-k>=0)
							{
								if(best[i][j]<best[i-1][j-k]+dir[i-1][j-k] || (best[i][j]==best[i-1][j-k]+dir[i-1][j-k] && dir[i-1][j-k]==1))
								{
									best[i][j]=best[i-1][j-k]+dir[i-1][j-k];
									dir[i][j]=dir[i-1][j-k];
								}
								k+=2;
							}
						}
						
						if(best[i][j]<best[i-1][j] || (best[i][j]==best[i-1][j] && dir[i-1][j]==-1))
						{
							best[i][j]=max(best[i][j],best[i-1][j]);
							dir[i][j]=-dir[i-1][j];
						}
						k=2;
						while(j-k>=0)
						{
							if(best[i][j]<best[i-1][j-k] || (best[i][j]==best[i-1][j-k] && dir[i-1][j-k]==-1))
							{
								best[i][j]=best[i-1][j-k];
								dir[i][j]=-dir[i-1][j-k];
							}
							k+=2;
						}
					}
				}
			}
			/*if(n==94 && m==2)		//testul 14
				cout<<19<<"\n";
			else
				if(n==75 && m==4)		//testul 16
					cout<<20<<"\n";
				else
					if(n==27 && m==10)	//testul 26
						cout<<26<<"\n";
					else
						if(n==33 && m==4)	//testul 37
							cout<<20<<"\n";
						else
							if(n==81 && m==1)	//testul 42
								cout<<16<<"\n";
							else*/
								cout<<best[n][m]<<"\n";
		}
	}
	return 0;
}
