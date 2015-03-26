#include<iostream>
using namespace std;
int n,start,finish;
char s[1010];

int main()
{
	int i;
	cin>>n;
	cin>>(s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='R')
		{
			start=i;
			finish=i+1;
			break;
		}
	}
	if(start==0)
	{
		for(i=n;i>0;i--)
		{
			if(s[i]=='L')
			{
				start=i;
				finish=i-1;
				break;
			}
		}
		while(s[finish]=='L')
			finish--;
	}
	else
	{
		while(s[finish]=='R')
			finish++;
	}
	for(i=1;i<n;i++)
	{
		if(s[i+1]=='L')
		{
			finish=i;
			break;
		}
	}
	cout<<start<<' '<<finish<<"\n";
	return 0;
}
