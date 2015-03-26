#include<cstdio>
#include<iostream>
#define EPS 0.000000001
using namespace std;
double Y1,Y2,YT,XB,YB,R;
double sol;

int main()
{
	double mij;
	cin>>Y1>>Y2>>YT>>XB>>YB>>R;
	Y1+=R;
	Y2-=R;
	YT-=R;
	mij=(Y1+Y2)/2.0;
	sol=XB*(YT-mij);
	sol=sol/(2.0*YT-YB-mij);
	if(sol<=EPS || sol-R<-EPS|| Y2-Y1<-EPS || YT<=EPS)
		printf("-1\n");
	else
		printf("%.9lf\n",sol);
	return 0;
}
