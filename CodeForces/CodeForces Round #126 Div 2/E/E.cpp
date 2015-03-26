#include<iostream>
#include<cmath>
using namespace std;
int n,S,c3,c4,c5,k3,k4,k5;
int sol3,sol4,sol5,valmin=2000000000;

int Euclid_extins(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int aux,d,q=a/b;
	d=Euclid_extins(b,a%b,x,y);
	aux=x;
	x=y;
	y=aux-y*q;
	return d;
}

inline int Modul(int a)
{
	if(a<0)
		return (-a);
	return a;
}

int Functie(int k3,int k4,int k5)
{
	return Modul(c3*k3-c4*k4)+Modul(c4*k4-c5*k5);
}

int main()
{
	int i,x,aux,q1,q2;
	cin>>n>>S;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x==3)
			c3++;
		if(x==4)
			c4++;
		if(x==5)
			c5++;
	}
	for(k3=0;c3*k3<=S && k3<=S;k3++)
	{
		S-=c3*k3;
		k4=k5=0;
		aux=Euclid_extins(c4,c5,k4,k5);
		if(S%aux!=0)
		{
			S+=c3*k3;
			continue;
		}
		k4*=S/aux;
		k5*=S/aux;
		q1=c5/aux;
		q2=c4/aux;
		while(k4>=k3)
		{
			k4-=q1;
			k5+=q2;
		}
		k4+=q1;
		k5-=q2;
		while(k3<=k4 && k4<=k5)
		{
			if(Functie(k3,k4,k5)<valmin)
			{
				valmin=Functie(k3,k4,k5);
				sol3=k3;
				sol4=k4;
				sol5=k5;
			}
			k4+=q1;
			k5-=q2;
		}
		S+=c3*k3;
	}
	if(valmin==2000000000)
		cout<<"-1\n";
	else
		cout<<sol3<<' '<<sol4<<' '<<sol5<<"\n";
	return 0;
}
