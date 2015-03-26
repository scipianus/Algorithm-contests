#include<iostream>
using namespace std;
struct Punct{int x,y;};
Punct P[210];
int n,sol;

int main()
{
	int i,j;
	bool N,E,S,V;
	Punct A;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>P[i].x>>P[i].y;
	for(i=1;i<=n;i++)
	{
		A=P[i];
		N=E=S=V=false;
		for(j=1;j<=n;j++)
		{
			if(j!=i)
			{
				if(P[j].x>A.x && P[j].y==A.y)
					E=true;
				if(P[j].x<A.x && P[j].y==A.y)
					V=true;
				if(P[j].x==A.x && P[j].y<A.y)
					S=true;
				if(P[j].x==A.x && P[j].y>A.y)
					N=true;
			}
		}
		if(N && E && S && V)
			sol++;
	}
	cout<<sol<<"\n";
	return 0;
}
