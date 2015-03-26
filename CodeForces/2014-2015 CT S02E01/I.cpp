#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
#include <map>

#define ll long long
#define inf (1<<29)
#define mod 1000000009
#define vint vector<int>::iterator
#define vintp vector<pair<int,int> >::iterator

using namespace std;

ifstream fin ("A.in");

int m,n,d[120][120],viz[120],cn,test,a,b,t;
long long cnt[120][120];
string s,s1,s2;
map<string,int> M;
int fr[52],to[52],cost[52];
double prob[60];

void reset ()
{
    M.clear();
    cn = 0;

     for (int i=1; i<=110; ++i)
      {
          for (int j=1; j<=110; ++j)
           d[i][j] = inf, cnt[i][j] = 0;
          d[i][i] = 0;
      }
     for (int i=1; i<=50; ++i)
      prob[i] = 0;
}

int main()
{
	cin>>test;

	for (int k=1;k<=test; ++k)
	{
	    reset ();

	    cin>>m>>s;
	    M[s] = 1;
	    n = 1;

	    for (int i=1; i<=m; ++i)
	    {
	        cin>>s1>>s2>>t;

	        map<string,int>::iterator it = M.find(s1);

	        if (it == M.end())
	        {
	            ++n;
	            M[s1] = n;
	            a = n;
	        }
	        else a = it->second;

	        it = M.find(s2);

	        if (it == M.end())
	        {
	            ++n;
	            M[s2] = n;
	            b = n;
	        }
	        else b = it->second;

	        fr[i] = a;
	        to[i] = b;
	        cost[i] = t;

	        if (t < d[a][b])
	        {
	            d[a][b] = t;
	            cnt[a][b] = 1;
	        }
	        else if (t == d[a][b])
	        {
	            cnt[a][b]++;
	        }
	    }

	    for (int k=1; k<=n; ++k)
	    {
	        for (int i=1; i<=n; ++i)
	        {
	            for (int j=1; j<=n; ++j)
	            {
	                if (d[i][j] == d[i][k] + d[k][j])
	                {
	                    cnt[i][j] += cnt[i][k]*cnt[k][j];
	                }
	                else if (d[i][j] > d[i][k] + d[k][j])
	                {
	                    d[i][j] = d[i][k] + d[k][j];
	                    cnt[i][j] = cnt[i][k]*cnt[k][j];
	                }
	            }
	        }
	    }

	    for (int i=2; i<=n; ++i)
	    {
	        if (d[1][i] != inf)
	         ++cn;
	    }

	    for (int i=1; i<=n; ++i)
	      cnt[i][i] = 1;

	    for (int i=1; i<=m; ++i)
	    {
	        int a = fr[i], b= to[i];

	        for (int j=2; j<=n; ++j)
	        {
	            if (d[1][j] != inf)
	            {
	                if (d[1][a] + d[b][j] + cost[i] == d[1][j])
	                {
	                    prob[i] += 1.0/cn*cnt[1][a]*cnt[b][j]/cnt[1][j];
	                }
	            }
	        }
	    }

	       cout<<"Case #"<<k<<": ";
	       for (int i=1; i<=m; ++i)
	        cout<<fixed<<setprecision(7)<<prob[i]<<" ";
          cout<<"\n";
	}
}
