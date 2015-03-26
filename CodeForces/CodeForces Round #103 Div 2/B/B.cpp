#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct Punct{short x,y;};
Punct A,B,C,D;
struct Radiator{Punct R; short r;};
Radiator v[1010];
int n,sol;

inline double Dist(Punct A,Punct B)
{
	return sqrt((double)((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)));
}

int main()
{
	int i,k;
	double d;
	bool gasit;
	Punct aux;
	cin>>D.x>>D.y>>B.x>>B.y;
	if(D.x>B.x)
	{
		aux=D;
		D=B;
		B=aux;
	}
	if(D.y<B.y)
	{
		A=D;
		C=B;
		D.x=A.x;
		D.y=C.y;
		B.x=C.x;
		B.y=A.y;
	}
	else
	{
		A.x=D.x;
		A.y=B.y;
		C.x=B.x;
		C.y=D.y;
	}
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>v[i].R.x>>v[i].R.y>>v[i].r;
	aux.x=A.x;
	aux.y=A.y;
	while(aux.x<=B.x)
	{
		gasit=false;
		for(k=1;k<=n && !gasit;k++)
		{
			d=Dist(aux,v[k].R);
			if(d<=v[k].r || v[k].r-d>=0)
				gasit=true;
		}
		if(!gasit)
			sol++;
		aux.x++;
	}
	aux.x=B.x;
	aux.y=B.y+1;
	while(aux.y<=C.y)
	{
		gasit=false;
		for(k=1;k<=n && !gasit;k++)
		{
			d=Dist(aux,v[k].R);
			if(d<=v[k].r || v[k].r-d>=0)
				gasit=true;
		}
		if(!gasit)
			sol++;
		aux.y++;
	}
	aux.x=C.x-1;
	aux.y=C.y;
	while(aux.x>=D.x)
	{
		gasit=false;
		for(k=1;k<=n && !gasit;k++)
		{
			d=Dist(aux,v[k].R);
			if(d<=v[k].r || v[k].r-d>=0)
				gasit=true;
		}
		if(!gasit)
			sol++;
		aux.x--;
	}
	aux.x=D.x;
	aux.y=D.y-1;
	while(aux.y>=A.y)
	{
		gasit=false;
		for(k=1;k<=n && !gasit;k++)
		{
			d=Dist(aux,v[k].R);
			if(d<=v[k].r || v[k].r-d>=0)
				gasit=true;
		}
		if(!gasit)
			sol++;
		aux.y--;
	}
	cout<<sol<<"\n";
	return 0;
}
