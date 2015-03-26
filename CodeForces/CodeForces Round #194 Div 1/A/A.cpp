#include<iostream>
using namespace std;
long long n;
int desc[100],size;

int main()
{
	long long p=1LL;
	int rez=0,ind=0;
	cin>>n;
	while(p<=n)
	{
		ind++;
		p*=3LL;
	}
	ind--;
	p/=3LL;
	size=ind;
	while(n)
	{
		while(n>=p)
		{
			desc[ind]++;
			rez++;
			n-=p;
		}
		while(n<p)
		{
			p/=3LL;
			ind--;
		}
	}
	int i;
	for(i=0;i<=size;i++)
	{
		if(desc[i]>0 && desc[i+1]<2)
		{
			desc[i+1]++;
			rez++;
			while(i>=0)
			{
				rez-=desc[i];
				i--;
			}
			cout<<rez<<"\n";
			return 0;
		}
	}
	return 0;
}
