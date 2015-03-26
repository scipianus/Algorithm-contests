#include<iostream>
using namespace std;
int A,B,C,D,n,sol;
bool v[100100];

int main()
{
	int i;
	cin>>A>>B>>C>>D>>n;
	for(i=A;i<=n;i+=A)
		v[i]=true;
	for(i=B;i<=n;i+=B)
		v[i]=true;
	for(i=C;i<=n;i+=C)
		v[i]=true;
	for(i=D;i<=n;i+=D)
		v[i]=true;
	for(i=1;i<=n;i++)
	{
		if(v[i]==true)
			sol++;
	}
	cout<<sol<<"\n";
	return 0;
}
