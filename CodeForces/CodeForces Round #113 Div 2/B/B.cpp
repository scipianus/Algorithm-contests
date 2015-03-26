#include<iostream>
using namespace std;
int n,m;
struct Punct{int x,y;};
Punct P[100100],P2[25000];
int maxL=-2000000000,minL=2000000000,maxC=-2000000000,minC=2000000000;
Punct A[2],B[2],C[2],D[2];

inline int Semn(Punct A,Punct B,Punct C)
{
	int rez=(A.y-B.y)*(C.x-B.x)-(A.x-B.x)*(C.y-B.y);
	if(rez==0)
		return 0;
	if(rez>0)
		return 1;
	return -1;
}

inline bool Verificare(Punct A)
{
	int i,rez=Semn(A,P[1],P[2]),rez2;
	if(rez>-1)
		return false;
	for(i=2;i<n;i++)
	{
		rez2=Semn(A,P[i],P[i+1]);
		if(rez2!=rez)
			return false;
	}
	rez2=Semn(A,P[n],P[1]);
	if(rez2!=rez)
		return false;
	return true;
}

int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>P[i].x>>P[i].y;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		cin>>P2[i].x>>P2[i].y;
		maxL=max(maxL,P2[i].x);
		maxC=max(maxC,P2[i].y);
		minL=min(minL,P2[i].x);
		minC=min(minC,P2[i].y);
	}
	A[0].y=B[0].y=C[0].x=D[0].x=2000000000;
	A[1].y=B[1].y=C[1].x=D[1].x=-2000000000;
	for(i=1;i<=m;i++)
	{
		if(P2[i].x==maxL)
		{
			if(P2[i].y<A[0].y)
				A[0]=P2[i];
			if(P2[i].y>A[1].y)
				A[1]=P2[i];
		}
		if(P2[i].x==minL)
		{
			if(P2[i].y<B[0].y)
				B[0]=P2[i];
			if(P2[i].y>B[1].y)
				B[1]=P2[i];
		}
		if(P2[i].y==maxC)
		{
			if(P2[i].x<C[0].x)
				C[0]=P2[i];
			if(P2[i].x>C[1].x)
				C[1]=P2[i];
		}
		if(P2[i].y==minC)
		{
			if(P2[i].x<D[0].x)
				D[0]=P2[i];
			if(P2[i].x>D[1].x)
				D[1]=P2[i];
		}
	}
	bool ok=true;
	for(i=0;i<2 && ok;i++)
	{
		if(Verificare(A[i]) && Verificare(B[i]) && Verificare(C[i]) && Verificare(D[i]))
			ok=true;
		else
			ok=false;
	}
	if(ok)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
