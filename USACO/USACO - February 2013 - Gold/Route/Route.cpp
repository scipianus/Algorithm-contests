/*
PROB : route
LANG : C++
*/
#include<fstream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n,na,nb,m,val[2][40010],best[2][40010],sol;
vector <int> st[40010],dr[40010];

int main()
{
	int i,x,y,aux;
	vector <int>::iterator it;
	ifstream fin("route.in");
	fin>>na>>nb>>m;
	n=max(na,nb);
	for(i=1;i<=na;i++)
		fin>>val[0][i];
	for(i=1;i<=nb;i++)
		fin>>val[1][i];
	for(i=1;i<=m;i++)
	{
		fin>>x>>y;
		dr[x].push_back(y);
		st[y].push_back(x);
	}
	fin.close();
	
	for(i=1;i<=na;i++)
		sort(dr[i].begin(),dr[i].end());
	for(i=1;i<=nb;i++)
		sort(st[i].begin(),st[i].end());
	best[0][1]=val[0][1];
	best[1][1]=val[1][1];
	it=dr[1].begin();
	if(it!=dr[1].end() && *it==1)
	{
		best[0][1]+=val[1][1];
		best[1][1]+=val[0][1];
	}
	sol=max(best[0][1],best[1][1]);
	for(i=2;i<=n;i++)
	{
		if(i<=na)
		{
			for(it=dr[i].begin();it!=dr[i].end();it++)
			{
				if(*it>=i)
				{
					it=dr[i].end()-1;
					continue;
				}
				best[0][i]=max(best[0][i],best[1][*it]);
			}
			best[0][i]+=val[0][i];
			sol=max(sol,best[0][i]);
		}
		if(i<=nb)
		{
			for(it=st[i].begin();it!=st[i].end();it++)
			{
				if(*it>=i)
				{
					if(*it==i)
					{
						aux=max(best[0][i],best[1][i]+val[1][i]+val[0][i]);
						best[1][i]=max(best[1][i],best[0][i]);
						best[0][i]=aux;
					}
					it=st[i].end()-1;
					continue;
				}
				best[1][i]=max(best[1][i],best[0][*it]);
			}
			best[1][i]+=val[1][i];
			sol=max(sol,best[1][i]);
		}
	}
	
	ofstream fout("route.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
