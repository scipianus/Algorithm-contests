#include<iostream>
#include<cstring>
using namespace std;
int ns,nr[26];
char s[100100];

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
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
