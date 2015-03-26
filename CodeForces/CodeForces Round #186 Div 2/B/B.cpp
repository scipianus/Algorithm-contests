#include<iostream>
#include<cstring>
using namespace std;
int n,m;
char s[100100];
int sum[100100];

int main()
{
	int i,st,dr;
	cin>>(s+1);
	n=strlen(s+1);
	for(i=1;i<n;i++)
	{
		if(s[i]==s[i+1])
			sum[i]=sum[i-1]+1;
		else
			sum[i]=sum[i-1];
	}
	cin>>m;
	while(m--)
	{
		cin>>st>>dr;
		cout<<(sum[dr-1]-sum[st-1])<<"\n";
	}
	return 0;
}
