#include<iostream>
#include<cstring>
using namespace std;
int n,T,sol[12],nr[110];
char s[110];
bool eliminat[110];

int main()
{
	int i,st,dr,poz,dir;
	int last;
	cin>>n>>T;
	cin>>(s+1);
	while(T--)
	{
		for(i=1;i<=n;i++)
		{
			if('0'<=s[i] && s[i]<='9')
				nr[i]=s[i]-'0';
		}
		cin>>st>>dr;
		poz=st;
		dir=1;
		last=0;
		while(st<=poz && poz<=dr)
		{
			if(eliminat[poz])
			{
				poz+=dir;
				continue;
			}
			if('0'<=s[poz] && s[poz]<='9')
			{
				last=0;
				sol[nr[poz]]++;
				nr[poz]--;
				if(nr[poz]<0)
					eliminat[poz]=true;
				poz+=dir;
				continue;
			}
			if(s[poz]=='<')
			{
				if(last)
					eliminat[last]=true;
				dir=-1;
				last=poz;
				poz+=dir;
			}
			else
			{
				if(last)
					eliminat[last]=true;
				dir=1;
				last=poz;
				poz+=dir;
			}
		}
		for(i=0;i<=9;i++)
		{
			cout<<sol[i]<<' ';
			sol[i]=0;
		}
		cout<<"\n";
		for(i=1;i<=n;i++)
			eliminat[i]=false;
	}
	return 0;
}
