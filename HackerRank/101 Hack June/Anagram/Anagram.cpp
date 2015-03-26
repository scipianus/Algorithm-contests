#include<iostream>
#include<cstring>
using namespace std;
int T,ns,a,nr[30],sol;
char s[10100];

int main()
{
	int i;
	cin>>T;
	while(T--)
	{
		cin>>(s+1);
		ns=strlen(s+1);
		if(ns%2==1)
		{
			cout<<"-1\n";
			continue;
		}
		a=ns/2;
		for(i=1;i<=a;i++)
			nr[s[i]-'a']++;
		sol=a;
		for(i=a+1;i<=ns;i++)
		{
			if(nr[s[i]-'a']>0)
				sol--;
			nr[s[i]-'a']--;
		}
		cout<<sol<<"\n";
		for(i=0;i<30;i++)
			nr[i]=0;
	}
	return 0;
}
