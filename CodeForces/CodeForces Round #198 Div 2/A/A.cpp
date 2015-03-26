#include<iostream>
using namespace std;
int X,Y,Z,A,B;

inline int Solve(int C)
{
	return (C/Z);
}

inline int Cmmdc(int a,int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	cin>>X>>Y>>A>>B;
	int c=Cmmdc(X,Y);
	Z=(X*Y)/c;
	cout<<(Solve(B)-Solve(A-1))<<"\n";
	return 0;
}
