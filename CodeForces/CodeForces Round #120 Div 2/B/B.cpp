#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double R,r;
struct Punct{double x,y;};
Punct A,B;

inline double Dist(Punct A,Punct B)
{
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

int main()
{
	double d;
	cin>>A.x>>A.y>>R;
	cin>>B.x>>B.y>>r;
	d=Dist(A,B);
	if(R>=r)
	{
		if(d+r<=R)
		{
			d=R-d-r;
			d/=2.0;
		}
		else
		{
			if(d<=R+r)
				d=0.0;
			else
			{
				d=d-R-r;
				d/=2.0;
			}
		}
	}
	else
	{
		if(d+R<=r)
		{
			d=r-d-R;
			d/=2.0;
		}
		else
		{
			if(d<=R+r)
				d=0.0;
			else
			{
				d=d-R-r;
				d/=2.0;
			}
		}
	}
	printf("%.6lf\n",d);
	return 0;
}
