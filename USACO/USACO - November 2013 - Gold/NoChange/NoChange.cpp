/*
PROB: nochange
LANG: C++
*/
#include <fstream>
#include <set>
#include <map>
using namespace std;
int n, K, coin[20], v[100100], sum[100100], val[66000], sol = -1;
struct Stare
{
	int poz, conf;
	Stare()
	{
		poz = conf = 0;
	}
	Stare(int ppoz, int cconf)
	{
		poz = ppoz;
		conf = cconf;
	}
	bool operator < (const Stare &A) const
	{
		return val[conf] > val[A.conf];
	}
};
set <Stare> Q;
map <Stare, bool> viz;

int main()
{
	int i, conf, poz, sz;
	Stare now, urm;
	ifstream fin("nochange.in");
	fin >> K >> n;
	for(i = 0; i < K; ++i)
		fin >> coin[i];
	for(i = 1; i <= n; ++i)
	{
		fin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}
	fin.close();
	
	for(conf = 0; conf < (1 << K); conf++)
		for(i = 0; i < K; ++i)
			if(conf & (1 << i))
				val[conf] += coin[i];
	Q.insert(Stare(0,(1 << K) - 1));
	sz = 1;
	while(sz && sol < 0)
	{
		now = *Q.begin();
		Q.erase(now);
		sz--;
		if(now.poz == n)
		{
			sol = val[now.conf];
			continue;
		}
		for(i = 0; i < K; ++i)
		{
			if(now.conf & (1 << i))
			{
				poz = upper_bound(sum + now.poz, sum + n + 1, sum[now.poz] + coin[i]) - sum - 1;
				urm = Stare(poz, now.conf - (1 << i));
				if(poz != now.poz && !viz.count(urm))
				{
					Q.insert(urm);
					sz++;
					viz[urm] = true;
				}
			}
		}
	}
	
	ofstream fout("nochange.out");
	fout << sol << "\n";
	fout.close();
	return 0;
}
