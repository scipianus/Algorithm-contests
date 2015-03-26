#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,sol=2000000000;
double v[100100];

inline int CautareBinara(int poz)
{
	int st,dr,mij,rez=0;
	st=poz;
	dr=n;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		if(v[mij]<=2*v[poz])
		{
			rez=max(rez,mij);
			st=mij+1;
		}
		else
			dr=mij-1;
	}
	return rez;
}

int main()
{
	int i,st,dr;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>n;
	for(i=1;i<=n;i++)
		fin>>v[i];
	sort(v+1,v+n+1);
	for(st=1;st<=n;st++)
	{
		dr=CautareBinara(st);
		if(dr)
			sol=min(sol,st-1+n-dr);
	}
	fout<<sol<<"\n";
	
	fin.close();
	fout.close();
	return 0;
}
