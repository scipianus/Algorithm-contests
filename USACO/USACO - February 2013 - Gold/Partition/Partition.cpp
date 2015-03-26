/*
PROB : partition
LANG : C++
*/
#include<fstream>
#include<cmath>
using namespace std;
int n,K,mat[20][20],now,sol=2000000000,size[20];
bool A[20],B[20];

inline void Procesare()
{
	int i,j,k,maxim=0;
	for(i=1;i<=n;i++)
		size[i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1,k=1;j<=n;j++)
		{
			size[k]+=mat[i][j];
			if(A[j]==true)
				k++;
			maxim=max(maxim,size[k]);
		}
		if(B[i]==true)
		{
			for(j=1;j<=n;j++)
				size[j]=0;
		}
	}
	sol=min(sol,maxim);
}

inline void Back2(int k)
{
	if(now==K)
		Procesare();
	else
	{
		if(k==n)
			return;
		B[k]=true;
		now++;
		Back2(k+1);
		now--;
		B[k]=false;
		Back2(k+1);
	}
}

inline void Back(int k)
{
	if(k==n || now==K)
	{
		if(now>=n)
			return;
		Back2(1);
	}
	else
	{
		A[k]=true;
		now++;
		Back(k+1);
		now--;
		A[k]=false;
		Back(k+1);
	}
}

int main()
{
	int i,j;
	ifstream fin("partition.in");
	fin>>n>>K;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			fin>>mat[i][j];
	fin.close();
	
	Back(1);
	
	ofstream fout("partition.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
