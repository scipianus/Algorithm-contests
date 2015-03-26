#include<iostream>
#include<cmath>
using namespace std;
long long A,B,sol=3000000000000000000LL,r1,r2;

int main()
{
	cin>>A>>B;
	if(A%B==0)
		sol=A/B;
	else
	{
		for(r1=1,r2=B-1;r1*r2<=A && r1<=r2;r1++,r2--)
		{
			if((A-r1*r2)%B==0)
				sol=min(sol,(A-r1*r2)/B+B);
		}
	}
	cout<<sol<<"\n";
	return 0;
}
