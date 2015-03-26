#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n, tata[100100], K, key[100100];
vector <int> G[100100];
map <vector <int>, int> M;

inline void DFS(int x)
{
	bool frunza = true;
	vector <int> v;
	vector <int>::iterator it;
	v.clear();
	for( it = G[x].begin(); it != G[x].end(); ++it)
	{
		frunza=false;
		DFS(*it);
		v.push_back(key[*it]);
	}
	sort(v.begin(),v.end());
	if(frunza)
		key[x]=1;
	else
	{
		if(M.count(v)==0)
		{
			K++;
			M[v]=K;
			key[x]=K;
		}
		else
			key[x]=M[v];
	}
}

int main()
{
	int i;
	ifstream fin("tree.in");
	fin >> n;
	for( i = 2; i <= n; ++i)
	{
		fin >> tata[i];
		G[tata[i]].push_back(i);
	}
	fin.close();
	
	K = 1;
	DFS(1);
	
	ofstream fout("tree.out");
	for( i = 1; i <= n; ++i)
		fout << (K - key[i] + 1) << " ";
	fout << "\n";
	fout.close();
	return 0;
}
