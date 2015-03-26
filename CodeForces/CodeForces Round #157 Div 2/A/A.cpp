#include<iostream>
using namespace std;
int main()
{
	int i,j;
	char s[10];
	for(i=1;i<=8;i++)
	{
		cin>>(s+1);
		for(j=2;j<=8;j++)
		{
			if(s[j-1]==s[j])
			{
				cout<<"NO\n";
				return 0;
			}
		}
		if(s[8]==s[1])
		{
			cout<<"NO\n";
			return 0;
		}	
	}
	cout<<"YES\n";
	return 0;
}
