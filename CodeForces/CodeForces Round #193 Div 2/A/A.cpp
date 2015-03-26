#include<iostream>
#include<cstring>
using namespace std;
int n,m,sol;
char moves[4000100];

int main()
{
	int i;
	cin>>n;
	cin>>(moves+1);
	m=strlen(moves+1);
	for(i=4;i<=m;i++)
		if(i%n==1 && moves[i-1]==moves[i-2] && moves[i-2]==moves[i-3])
			sol++;
	cout<<sol<<"\n";
	return 0;
}
