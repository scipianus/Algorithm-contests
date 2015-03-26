/*
PROB: planting
LANG: C++
*/
#include<fstream>
#include<vector>
#define MOD 666013
#define MAX 100000000
using namespace std;
int n;
long long sol;
struct Interval{int st,dr;};
struct Element{int lin; vector <Interval> v;};
vector <Element> Hash[666013];

inline bool Sortare(Interval A,Interval B)
{
	if(A.st==B.st)
		return A.dr>B.dr;
	return A.st<B.st;
}

void Rezolvare()
{
	int poz,k,i,st,dr;
	long long lg;
	vector <Interval> A;
	for(poz=0;poz<666013;poz++)
	{
		if(Hash[poz].size()==0)
			continue;
		for(k=0;k<Hash[poz].size();k++)
		{
			A=Hash[poz][k].v;
			sort(A.begin(),A.end(),Sortare);
			st=A[0].st;
			dr=A[0].dr;
			for(i=1;i<A.size();i++)
			{
				if(A[i].st<=dr)
					dr=max(A[i].dr,dr);
				else
				{
					lg=(long long)(dr-st+1);
					sol+=lg;
					st=A[i].st;
					dr=A[i].dr;
				}
			}
			lg=(long long)(dr-st+1);
			sol+=lg;
		}
	}
}

int main()
{
	int i,j,k,x1,x2,y1,y2,poz;
	Interval aux;
	Element aux2;
	bool gasit;
	ifstream fin("planting.in");
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>x1>>y1>>x2>>y2;
		x1+=MAX;
		x2+=MAX;
		y1+=MAX;
		y2+=MAX;
		aux.st=y2;
		aux.dr=y1-1;
		for(j=x1;j<x2;j++)
		{
			poz=j%MOD;
			gasit=false;
			for(k=0;k<Hash[poz].size() && !gasit;k++)
			{
				aux2=Hash[poz][k];
				if(aux2.lin==j)
				{
					gasit=true;
					Hash[poz][k].v.push_back(aux);
				}
			}
			if(!gasit)
			{
				aux2.lin=j;
				aux2.v.clear();
				aux2.v.push_back(aux);
				Hash[poz].push_back(aux2);
			}
		}
	}
	fin.close();
	
	Rezolvare();
	
	ofstream fout("planting.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
