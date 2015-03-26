#include<iostream>
#include<cmath>
using namespace std;
struct Punct{double x,y;};
Punct A,B,C;

int main()
{
	double p1,p2;
	cin>>A.x>>A.y;
	cin>>B.x>>B.y;
	cin>>C.x>>C.y;
	
	if(A.x==B.x && B.x==C.x)
	{
		cout<<"TOWARDS\n";
		return 0;
	}
	if(A.x==B.x && B.y==C.y)
	{
		if((C.x<=A.x && C.y>=A.y) || (C.x>=A.x && C.y<=A.y))
		{
			cout<<"LEFT\n";
			return 0;
		}
		cout<<"RIGHT\n";
		return 0;
	}
	p1=(double)(A.y-B.y);
	p1/=(double)(A.x-B.x);
	if(A.x==C.x)
	{
		if((B.x<=A.x && C.y>=A.y) || (B.x>=A.x && C.y<=A.y))
		{
			cout<<"RIGHT\n";
			return 0;
		}
		cout<<"LEFT\n";
		return 0;
	}
	p2=(double)(A.y-C.y);
	p2/=(double)(A.x-C.x);
	if(fabs(p1-p2)<0.000001)
	{
		cout<<"TOWARDS\n";
		return 0;
	}
	if(A.x<=B.x)
	{
		if(C.y>=B.y)
		{
			cout<<"LEFT\n";
			return 0;
		}
		cout<<"RIGHT\n";
		return 0;
	}
	if(A.x>=B.x)
	{
		if(C.y>=B.y)
		{
			cout<<"RIGHT\n";
			return 0;
		}
		cout<<"LEFT\n";
		return 0;
	}
	return 0;
}
