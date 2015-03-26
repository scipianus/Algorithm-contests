#include<iostream>
#include<cmath>
using namespace std;
int A,B,C,s1,s2,s3,sol;

int main()
{
	cin>>s1>>s2>>s3;
	B=s1*s2;
	B/=s3;
	B=(int)sqrt((double)B);
	A=s1/B;
	C=s2/B;
	sol=4*(A+B+C);
	cout<<sol<<"\n";
	return 0;
}
