#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
int n;
struct Punct{int x,y;};
Punct P[310];
int sol;

inline int Det(Punct A,Punct B,Punct C)
{
	return (A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x);
}

int main()
{
	int i,j,k,d;
	int max1,max2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d %d",&P[i].x,&P[i].y);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			max1=max2=0;
			for(k=1;k<=n;k++)
			{
				if(k==i || k==j)
					continue;
				d=Det(P[i],P[j],P[k]);
				if(d<0)
					max1=max(max1,-d);
			}
			for(k=1;k<=n;k++)
			{
				if(k==i || k==j)
					continue;
				d=Det(P[i],P[j],P[k]);
				if(d>0)
					max2=max(max2,d);
			}
			if(max1 && max2)
				sol=max(sol,max1+max2);
		}
	}
	printf("%.10lf\n",(1.0*sol)/(2.0));
	return 0;
}
