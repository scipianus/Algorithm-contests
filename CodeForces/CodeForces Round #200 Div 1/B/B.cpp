#include<iostream>
#include<cstring>
using namespace std;
int n,vf;
char s[100100],St[100100];

int main()
{
	int i;
	cin>>(s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if(vf && St[vf]==s[i])
			vf--;
		else
			St[++vf]=s[i];
	}
	if(vf==0)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}
