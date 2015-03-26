#include<iostream>
#define pii pair<int,int>
using namespace std;
int n;
pii start,finish,now,next;
char move[100100];

int main()
{
	int i;
	cin>>n>>start.first>>start.second>>finish.first>>finish.second;
	cin>>(move+1);
	for(i=1;i<=n;i++)
	{
		if(move[i]=='E' && start.first<finish.first)
			start.first++;
		if(move[i]=='S' && start.second>finish.second)
			start.second--;
		if(move[i]=='W' && start.first>finish.first)
			start.first--;
		if(move[i]=='N' && start.second<finish.second)
			start.second++;
		if(start.first==finish.first && start.second==finish.second)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}
