#include<iostream>
#include<cstring>
using namespace std;
int n,K,K1,nr[30];
char s[1010];

int main()
{
	int i,j,k,sum=0;
	cin>>K;
	cin>>s;
	n=strlen(s);
	for(i=0;i<n;i++)
		nr[s[i]-'a']++;
	if(n%K!=0)
	{
		cout<<"-1\n";
		return 0;
	}
	for(i=0;i<30;i++)
	{
		if(nr[i]%K!=0)
		{
			cout<<"-1\n";
			return 0;
		}
		nr[i]/=K;
		sum+=nr[i];
	}
	if(sum!=(n/K))
	{
		cout<<"-1\n";
		return 0;
	}
	for(i=1;i<=K;i++)
	{
		for(j=0;j<30;j++)
		{
			for(k=1;k<=nr[j];k++)
				cout<<(char)(j+'a');
		}
	}
	cout<<"\n";
	return 0;
}
