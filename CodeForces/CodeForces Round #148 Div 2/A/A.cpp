#include<iostream>
using namespace std;
int Y,K,N;
int main()
{
	int i,lim;
	bool gasit=false;
	cin>>Y>>K>>N;
	lim=N/K;
	for(i=1;i<=lim;i++)
	{
		if(i*K-Y>=1)
		{
			gasit=true;
			cout<<(i*K-Y)<<' ';
		}
	}
	if(!gasit)
		cout<<"-1\n";
	else
		cout<<"\n";
	return 0;
}
