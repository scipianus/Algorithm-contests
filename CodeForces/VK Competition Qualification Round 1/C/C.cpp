#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n,ns;
char path[100000];

int main()
{
	int i,j;
	char s[2500];
	cin>>n;
	path[0]='/';
	ns=0;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		if(s[0]=='p')
			cout<<path<<"\n";
		else
		{
			cin>>s;
			if(s[0]=='/')
			{
				for(j=0;j<=ns;j++)
					path[j]=0;
				for(j=0;j<strlen(s);j++)
					path[j]=s[j];
				if(strlen(s)>1)
				{
					path[j]='/';
					ns=j;
				}
				else
					ns=j-1;
			}
			else
			{
				j=0;
				while(j<strlen(s))
				{
					if(s[j]=='.')
					{
						j+=3;
						path[ns]=0;
						ns--;
						while(path[ns]!='/')
						{
							path[ns]=0;
							ns--;
						}
					}
					else
						if('a'<=s[j] && s[j]<='z')
						{
							while(j<strlen(s) && 'a'<=s[j] && s[j]<='z')
							{
								path[++ns]=s[j];
								j++;
							}
							path[++ns]='/';
						}
						else
							j++;
				}
			}
		}
	}
	return 0;
}
