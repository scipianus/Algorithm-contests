/*
PROB: cowids
LANG: C++
*/
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
int N,K,C[30][12];

void Citire()
{
	ifstream fin("cowids.in");
	fin>>N>>K;
	fin.close();
}

void Precalculare_Combinari()
{
	int i,j,lim;
	C[0][0]=1;
	C[1][0]=C[1][1]=1;
	for(i=2;i<=28;i++)
	{
		C[i][0]=1;
		if(i<=K)
			C[i][i]=1;
		lim=min(i-1,K);
		for(j=1;j<=lim;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
}

void Rezolvare()
{
	int nr0,nr1;
	Precalculare_Combinari();
	nr0=0;
	nr1=K-1;
	while(N>C[nr0+nr1][nr1])
	{
		N-=C[nr0+nr1][nr1];
		nr0++;
	}
	ofstream fout("cowids.out");
	fout<<1;
	while(nr0 || nr1)
	{
		if(N<=C[nr0+nr1-1][nr1])
		{
			fout<<0;
			nr0--;
		}
		else
		{
			fout<<1;
			N-=C[nr0+nr1-1][nr1];
			nr1--;
		}
	}
	fout<<"\n";
	fout.close();
}

int main()
{
	Citire();
	Rezolvare();
	return 0;
}
