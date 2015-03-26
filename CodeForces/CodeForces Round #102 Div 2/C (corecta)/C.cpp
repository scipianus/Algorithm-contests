#include<iostream>
#include<cstring>
using namespace std;
long long n,minim=2000000000000000000LL,maxim=0;

int main()
{
	long long x,y,i,lim,dif;
	cin>>n;
	long long A,B,C;
	for(x=1;x<=n/x;x++) //x=A-1
	{
		if(n%x==0)
		{
			int v[]={x,n/x};
			for(i=0;i<2;i++)
			{
				A=v[i]+1;
				lim=n/v[i];
				for(y=1;y<=lim/y;y++) //y=B-2
				{
					if(lim%y==0)
					{
						B=y+2;
						C=(lim/y)+2;
						dif=2*A*B+2*A*C+B*C-4*A-2*B-2*C+4;
						minim=min(minim,dif);
						maxim=max(maxim,dif);
					}
				}
			}
		}
	}
	cout<<minim<<' '<<maxim<<"\n";
	return 0;
}
