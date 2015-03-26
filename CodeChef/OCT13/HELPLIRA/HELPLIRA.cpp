#include<iostream>
#include<cmath>
#include<cstdlib>
#define INF 1000000000
using namespace std;
int n,sol[2],ind[2];
struct Punct{int x,y;};
Punct A,B,C;

inline int Arie(Punct A,Punct B,Punct C)
{
	return abs(A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x);
}

int main()
{
	int i,S;
	cin>>n;
	sol[0]=-INF;
	sol[1]=INF;
	for(i=1;i<=n;i++)
	{
		cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
		S=Arie(A,B,C);
		if(S>=sol[0])
		{
			sol[0]=S;
			ind[0]=i;
		}
		if(S<=sol[1])
		{
			sol[1]=S;
			ind[1]=i;
		}
	}
	cout<<ind[1]<<' '<<ind[0]<<"\n";
	return 0;
}
