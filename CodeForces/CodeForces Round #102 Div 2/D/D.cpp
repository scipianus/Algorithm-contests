#include<iostream>
#include<cstring>
using namespace std;
int n,m,max1,max2;

int main()
{
	int i,j,aux;
	cin>>n>>m;
	if(n==1)
	{
		cout<<m<<"\n";
		return 0;
	}
	if(m==1)
	{
		cout<<n<<"\n";
		return 0;
	}
	if(n==2 && m==2)
	{
		cout<<4<<"\n";
		return 0;
	}
	if(n==2 && m==3)
	{
		cout<<4<<"\n";
		return 0;
	}
	if(n==2)
	{
		aux=m/4;
		aux*=4;
		if(m%4==1)
			aux+=2;
		if(m%4==2)
			aux+=4;
		cout<<aux<<"\n";
		return 0;
	}
	if(m==2)
	{
		aux=n/4;
		aux*=4;
		if(n%4==1)
			aux+=2;
		if(n%4==2)
			aux+=4;
		cout<<aux<<"\n";
		return 0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if((i+j)%2==0)
				max1++;
			else
				max2++;
		}
	cout<<max(max1,max2)<<"\n";
	return 0;
}
