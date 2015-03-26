/*
PROB : taxi
LANG : C++
*/
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,maxdr,minst;
long long sol;
struct Interval{int st,dr;};
Interval v[100100];

inline bool Sortare(Interval A,Interval B)
{
	return A.st<B.st;
}

inline long long Intersectie(Interval A,Interval B)
{
	int st,dr;
	st=max(A.st,B.st);
	dr=min(A.dr,B.dr);
	return 1LL*(dr-st);
}

int main()
{
	int i,j;
	ifstream fin("taxi.in");
	fin>>n>>m;
	minst=m;
	maxdr=0;
	for(i=1;i<=n;i++)
	{
		fin>>v[i].st>>v[i].dr;
		if(v[i].st>v[i].dr)
			swap(v[i].st,v[i].dr);
		maxdr=max(maxdr,v[i].dr);
		minst=min(minst,v[i].st);
	}
	fin.close();
	
	sol=1LL*minst+1LL*(m-maxdr);
	sort(v+1,v+n+1,Sortare);
	for(i=1;i<=n;i++)
	{
		sol+=1LL*(v[i].dr-v[i].st);
		for(j=i+1;j<=n;j++)
		{
			if(v[j].st<v[i].dr)
				sol+=Intersectie(v[i],v[j]);
			else
				j=n+1;
		}
	}
	
	ofstream fout("taxi.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
