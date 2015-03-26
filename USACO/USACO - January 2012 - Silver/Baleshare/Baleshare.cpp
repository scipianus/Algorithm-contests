/*
PROB: baleshare
LANG: C++
*/
#include<fstream>
#include<cmath>
using namespace std;
short n,a[25],sol=30000,v[25];

void Citire()
{
	int i;
	ifstream fin("baleshare.in");
	fin>>n;
	for(i=1;i<=n;i++)
		fin>>a[i];
	fin.close();
}

inline short Max(short a,short b)
{
	if(b>a)
		return b;
	return a;
}

inline void Prelucrare()
{
	short i,g[3],x;
	g[0]=g[1]=g[2]=0;
	for(i=1;i<=n;i++)
	{
		g[v[i]]+=a[i];
	}
	x=Max(g[0],Max(g[1],g[2]));
	if(sol>x)
		sol=x;
}

inline void Back(short k)
{
	if(k==n+1)
		Prelucrare();
	else
	{
		v[k]=0;
		Back(k+1);
		v[k]=1;
		Back(k+1);
		v[k]=2;
		Back(k+1);
	}
}

void Afisare()
{
	ofstream fout("baleshare.out");
	fout<<sol<<"\n";
	fout.close();
}

int main()
{
	Citire();
	Back(1);
	Afisare();
	return 0;
}
