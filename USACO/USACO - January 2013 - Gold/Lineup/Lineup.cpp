/*
PROB: lineup
LANG: C++
*/
#include<fstream>
#include<algorithm>
#include<set>
using namespace std;
int n,K,v[100100],sol;
int vsort[100100],viz[100100];
multiset <int> S;

int main()
{
	int i,st,nrd;
	multiset <int>::iterator it;
	ifstream fin("lineup.in");
	fin>>n>>K;
	for(i=1;i<=n;i++)
	{
		fin>>v[i];
		vsort[i]=v[i];
	}
	fin.close();
	
	sort(vsort+1,vsort+n+1);
	for(i=1;i<=n;i++)
		v[i]=lower_bound(vsort+1,vsort+n+1,v[i])-vsort;
	st=1;
	viz[v[1]]=1;
	sol=1;
	nrd=1;
	S.insert(-1);
	for(i=2;i<=n;i++)
	{
		if(!viz[v[i]])
		{
			viz[v[i]]=1;
			S.insert(-1);
			nrd++;
		}
		else
		{
			it=S.lower_bound(-viz[v[st]]);
			S.erase(it);
			viz[v[i]]++;
			S.insert(-viz[v[i]]);
		}
		if(nrd<=K+1)
		{
			it=S.begin();
			sol=max(sol,-*it);
		}
		else
		{
			while(nrd>K+1)
			{
				if(viz[v[st]]==1)
					nrd--;
				it=S.lower_bound(-viz[v[st]]);
				S.erase(it);
				viz[v[st]]--;
				if(viz[v[st]]>0)
					S.insert(-viz[v[st]]);
				st++;
			}
			it=S.begin();
			sol=max(sol,-*it);
		}
	}
	it=S.begin();
	sol=max(sol,-*it);
	
	ofstream fout("lineup.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
