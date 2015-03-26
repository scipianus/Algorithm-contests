#include<iostream>
using namespace std;
int T,ns,best[5010],lgi[5010],lgp[5010];
char s[5010];

int main()
{
	int i,j,st,dr,mij;
	cin>>T;
	while(T--)
	{
		cin>>ns;
		cin>>(s+1);
		for(i=1;i<=ns;i++)
		{
			st=dr=i;
			while(st-1>=1 && dr+1<=ns && s[st-1]==s[dr+1])
			{
				st--;
				dr++;
			}
			lgi[i]=dr-st+1;
			if(i+1<=ns && s[i]==s[i+1])
			{
				st=i;
				dr=i+1;
				while(st-1>=1 && dr+1<=ns && s[st-1]==s[dr+1])
				{
					st--;
					dr++;
				}
				lgp[i]=dr-st+1;
			}
			else
				lgp[i]=0;
		}
		best[1]=1;
		for(i=2;i<=ns;i++)
		{
			best[i]=best[i-1]+1;
			for(j=i-1;j>0;j--)
			{
				if((i-j+1)%2==1)
				{
					mij=(i+j)/2;
					if(j+lgi[mij]-1>=i)
						best[i]=min(best[i],best[j-1]+1);
				}
				else
				{
					mij=(i+j)/2;
					if(j+lgp[mij]-1>=i)
						best[i]=min(best[i],best[j-1]+1);
				}
			}
		}
		cout<<best[ns]<<"\n";
	}
	return 0;
}
