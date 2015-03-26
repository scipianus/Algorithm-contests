#include<iostream>
#include<cstring>
using namespace std;
int n,x;

int main()
{
	int i;
	char s[5];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		if(s[1]=='+')
			x++;
		else
			x--;
	}
	cout<<x<<"\n";
	return 0;
}
