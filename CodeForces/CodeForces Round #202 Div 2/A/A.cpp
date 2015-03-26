#include<iostream>
using namespace std;
int n,nr[110];

int main()
{
	int i,now;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>now;
		if(now==25)
			nr[25]++;
		else
		{
			if(now==50)
			{
				if(nr[25])
				{
					nr[25]--;
					nr[50]++;
				}
				else
				{
					cout<<"NO\n";
					return 0;
				}
			}
			else
			{
				if(nr[25] && nr[50])
				{
					nr[25]--;
					nr[50]--;
					nr[100]++;
					continue;
				}
				if(nr[25]>=3)
				{
					nr[25]-=3;
					nr[100]++;
					continue;
				}
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	return 0;
}
