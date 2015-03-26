/*
PROB : runaway
LANG : C++
*/
#include<fstream>
#include<vector>
#include<algorithm>
#define pil pair<int,long long>
using namespace std;
int n,sol[200100];
long long L,total;
vector <pil> G[200100];

inline int DFS(int x)
{
	int nod,nr=1;
	long long lg;
	vector <pil>::iterator it;
	for(it=G[x].begin();it!=G[x].end();it++)
	{
		nod=(*it).first;
		lg=(*it).second;
		if(total+lg<=L)
		{
			total+=lg;
			nr+=DFS(nod);
			total-=lg;
		}
	}
	return nr;
}

int main()
{
	int i,tata;
	long long lg;
	ifstream fin("runaway.in");
	fin>>n>>L;
	for(i=2;i<=n;i++)
	{
		fin>>tata>>lg;
		G[tata].push_back(make_pair(i,lg));
	}
	fin.close();
	
	for(i=1;i<=n;i++)
	{
		total=0LL;
		sol[i]=DFS(i);
	}
	
	ofstream fout("runaway.out");
	for(i=1;i<=n;i++)
		fout<<sol[i]<<"\n";
	fout.close();
	return 0;
}
