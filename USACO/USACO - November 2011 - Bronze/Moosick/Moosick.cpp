/*
PROB: moosick
LANG: C++
*/
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
short n,N,k,A[20010],C[15],dif[15];
vector <short> v,sol;

void Citire()
{
	int i;
	ifstream fin("moosick.in");
	fin>>n;
	for(i=1;i<=n;i++)
		fin>>A[i];
	fin>>k;
	for(i=0;i<k;i++)
		fin>>C[i];
	fin.close();
	N=n-k+1;
}

inline void Verificare(short pas)
{
	short i,ok=1;
	for(i=0;i<k;i++)
		dif[i]=C[i]-v[i];
	for(i=0;i<k-1 && ok;i++)
		if(dif[i]!=dif[i+1])
			ok=0;
	if(ok)
		sol.push_back(pas);
}

void Rezolvare()
{
	short i;
	sort(C,C+k);
	if(k>n)
		return;
	for(i=1;i<=k;i++)
		v.push_back(A[i]);
	sort(v.begin(),v.end());
	Verificare(1);
	for(i=2;i<=N;i++)
	{
		v.erase(lower_bound(v.begin(),v.end(),A[i-1]));
		v.push_back(A[i+k-1]);
		sort(v.begin(),v.end());
		Verificare(i);
	}
}

void Afisare()
{
	short i,lim;
	lim=sol.size();
	ofstream fout("moosick.out");
	fout<<lim<<"\n";
	for(i=0;i<lim;i++)
		fout<<sol[i]<<"\n";
	fout.close();
}

int main()
{
	Citire();
	Rezolvare();
	Afisare();
	return 0;
}
