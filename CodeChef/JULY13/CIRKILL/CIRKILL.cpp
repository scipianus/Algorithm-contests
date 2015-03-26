#include<iostream>
#include<cstdio>
#include<cmath>
#define EPS 0.00000001
using namespace std;
int T,n;
struct Punct{double x,y;};
Punct P[35];
double sol;

inline double Det(Punct A,Punct B,Punct C)
{
	return A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
}

inline double Dist(Punct A,Punct B)
{
	return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}

inline void Solve(Punct A,Punct B,Punct C)
{
	if(fabs(Det(A,B,C))<=EPS) //sunt coliniare, deci nu determina un cerc unic
		return;
	int i,nr=0;
	double m1,m2,a1,b1,c1,a2,b2,c2,R;
	Punct M1,M2,inter; //M1,M2 mijloace de laturi ale triunghiului
	if(fabs(A.y-B.y)>EPS)
	{
		M1.x=(A.x+B.x)/2.0;
		M1.y=(A.y+B.y)/2.0;
		m1=(A.x-B.x)/(B.y-A.y);
		if(fabs(A.y-C.y)>EPS)
		{
			M2.x=(A.x+C.x)/2.0;
			M2.y=(A.y+C.y)/2.0;
			m2=(A.x-C.x)/(C.y-A.y);
		}
		else
		{
			M2.x=(B.x+C.x)/2.0;
			M2.y=(B.y+C.y)/2.0;
			m2=(B.x-C.x)/(C.y-B.y);
		}
	}
	else
	{
		M1.x=(A.x+C.x)/2.0;
		M1.y=(A.y+C.y)/2.0;
		m1=(A.x-C.x)/(C.y-A.y);
		M2.x=(B.x+C.x)/2.0;
		M2.y=(B.y+C.y)/2.0;
		m2=(B.x-C.x)/(C.y-B.y);
	}
	//prima mediatoare
	a1=m1;
	b1=-1;
	c1=M1.y-m1*M1.x;
	//a doua mediatoare
	a2=m2;
	b2=-1;
	c2=M2.y-m2*M2.x;
	//centrul cercului circumscris
	inter.x=(c2*b1-c1*b2)/(a1*b2-a2*b1);
	inter.y=(-c1-a1*inter.x)/b1;
	//raza cercului circumscris
	R=Dist(A,inter);
	//rezolvarea in sine
	for(i=1;i<=n;i++)
		if(fabs(Dist(P[i],inter))<=R+EPS)
			nr++;
	nr-=3;
	sol+=(1.0*nr);
}

int main()
{
	int i,j,k;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>P[i].x>>P[i].y;
		for(i=1;i<=n;i++) //T1
			for(j=i+1;j<=n;j++)//T2
				for(k=j+1;k<=n;k++)//T3
						Solve(P[i],P[j],P[k]);
		sol*=6.0;
		sol/=(1.0*n*(n-1)*(n-2)*(n-3));
		printf("%.7lf\n",sol);
		sol=0.0;
	}
	return 0;
}
