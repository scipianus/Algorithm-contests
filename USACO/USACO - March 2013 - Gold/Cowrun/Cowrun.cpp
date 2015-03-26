/*
PROB : cowrun
LANG : C++
*/
#include<fstream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,N,v[1010],poz;
long long sol,timp;

int main()
{
	int i,j,ind;
	ifstream fin("cowrun.in");
	fin>>n;
	for(i=1;i<=n;i++)
		fin>>v[i];
	fin.close();
	
	N=n;
	for(i=1;i<=n;i++)
	{
		ind=1;
		for(j=2;j<=N;j++)
		{
			if(abs(v[j]-poz)<abs(v[ind]-poz))
				ind=j;
		}
		timp+=1LL*abs(v[ind]-poz);
		sol+=timp;
		poz=v[ind];
		swap(v[ind],v[N]);
		N--;
	}
	
	ofstream fout("cowrun.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
