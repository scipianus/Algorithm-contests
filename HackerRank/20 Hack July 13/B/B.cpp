#include<iostream>
#include<cstring>
#define MOD 1000000007
using namespace std;
int ns,nr[26],fact[50050];
char s[100100];
long long sol;

inline int InversModular(int x)
{
	int put=MOD-2,rez=1;
	while(put)
	{
		if(put%2==1)
		{
			rez=(1LL*rez*x)%MOD;
			put--;
		}
		x=(1LL*x*x)%MOD;
		put/=2;
	}
	return rez;
}

int main()
{
	int i,nri=0;
	cin>>(s+1);
	ns=strlen(s+1);
	for(i=1;i<=ns;i++)
		nr[s[i]-'a']++;
	for(i=0;i<26;i++)
		if(nr[i]%2==1)
			nri++;
	if((ns%2==0 && nri==0) || (ns%2==1 && nri==1))
	{
		fact[0]=1;
		for(i=1;2*i<=ns;i++)
			fact[i]=(1LL*fact[i-1]*i)%MOD;
		sol=fact[ns/2];
		for(i=0;i<26;i++)
		{
			if(nr[i]>0)
			{
				sol*=1LL*InversModular(fact[nr[i]/2]);
				sol%=MOD;
			}
		}
		cout<<sol<<"\n";
	}
	else
		cout<<"0\n";
	return 0;
}
