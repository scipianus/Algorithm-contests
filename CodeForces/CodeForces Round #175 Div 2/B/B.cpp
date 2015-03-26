#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,start,finish,p[100100],sol;
bool viz[100100];

int main()
{
	int i;
	cin>>n>>start>>finish;
	for(i=1;i<=n;i++)
		cin>>p[i];
	if(start==finish)
		cout<<"0\n";
	else
	{
		viz[start]=true;
		while(start!=finish)
		{
			sol++;
			start=p[start];
			if(viz[start])
			{
				cout<<"-1\n";
				return 0;
			}
			viz[start]=true;
		}
		cout<<sol<<"\n";
	}
	return 0;
}
