#include<iostream>
#include<cstring>
using namespace std;
int ns,nr;
char s[500000];
int L[500000];

int main()
{
	cin>>(s+1);
	ns=strlen(s+1);
	int lg=0,i,poz;
	i=1;
	while(i<ns && s[i]!='.')
		i++;
	i--;
	if(i==0 || i>8 || i==ns-1)
	{
		cout<<"NO\n";
		return 0;
	}
	i++;
	while(i<=ns)
	{
		lg=0;
		while(i<ns && s[i+1]!='.')
		{
			i++;
			lg++;
		}
		if((i==ns && lg>3) || (i==ns-1 && s[i+1]=='.'))
		{
			cout<<"NO\n";
			return 0;
		}
		if(i<ns-1 && (lg<2 || lg>11))
		{
			cout<<"NO\n";
			return 0;
		}
		L[++nr]=lg;
		i++;
	}
	cout<<"YES\n";
	i=1;
	while(i<=ns && s[i]!='.')
	{
		cout<<s[i];
		i++;
	}
	cout<<".";
	i++;
	poz=1;
	while(i<=ns)
	{
		if(poz==nr)
		{
			while(i<=ns)
			{
				cout<<s[i];
				i++;
			}
			cout<<"\n";
			continue;
		}
		if(L[poz]-1<=8)
		{
			cout<<s[i]<<"\n";
			i++;
		}
		else
		{
			if(L[poz]-2<=8)
			{
				cout<<s[i]<<s[i+1]<<"\n";
				i+=2;
			}
			else
			{
				cout<<s[i]<<s[i+1]<<s[i+2]<<"\n";
				i+=3;
			}
		}
		while(i<=ns && s[i]!='.')
		{
			cout<<s[i];
			i++;
		}
		cout<<".";
		poz++;
		i++;
	}
	return 0;
}
