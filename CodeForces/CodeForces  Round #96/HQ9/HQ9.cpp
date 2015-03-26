#include<iostream>
#include<cstring>
using namespace std;
char s[200];
int n;

bool Find_HQ9()
{
	int i;
	for(i=0;i<n;i++)
		if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
			return true;
	return false;
}

int main()
{
	cin>>s;
	n=strlen(s);
	bool ok=Find_HQ9();
	if(ok)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
