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
#define pl 10005
#define mod 1000000009
#define vint vector<int>::iterator
#define vintp vector<pair<int,int> >::iterator

using namespace std;

ifstream fin ("A.in");

int n,k,viz[20010],f[20010],d[20010],next[20010],aib[20010];
vector<int> ans;
struct p
{
    int a,b;
}v[1010];

bool cmp (p a, p b)
{
    return a.b < b.b;
}

int parent (int x)
{
    if (f[x])
    {
        return f[x] = parent(f[x]);
    }
    return x;
}

void unite (int x, int y)
{
    x = parent (x);
    y = parent (y);

    if (x != y)
    {
        if (d[x] < d[y])
        {
            f[x] = y;
            next[y] = min (next[x],next[y]);
        }
        else
        {
            f[y] = x;
            if (d[x] == d[y])
              ++d[x];
            next[x] = min (next[x],next[y]);
        }
    }
}

inline int LSB (int i)
{
    return i&(-i);
}

void update (int i, int val)
{
    for (; i<= v[n].b; i += LSB(i))
    {
        aib[i] += val;
    }
}

int query (int i)
{
    int s= 0;

    for (; i > 0; i -= LSB(i))
    {
        s += aib[i];
    }

    return s;
}

int main ()
{
    cin>>k>>n;

    for (int i=1; i<=n; ++i)
    {
        cin>>v[i].a>>v[i].b;
        v[i].a += pl;
        v[i].b += pl;

        if (v[i].a > v[i].b)
          swap (v[i].a,v[i].b);
    }

    sort (v+1,v+n+1,cmp);

    for (int i=1; i <= v[n].b; ++i)
    {
        next[i] = i-1;
    }

    int total = 0;

    for (int i=1; i<=n; ++i)
    {
        total = query (v[i].b) - query (v[i].a-1);

        int cnt = 0;

        int need = min (k,v[i].b-v[i].a+1) - total;

        if (need > 0)
        {
            int j = v[i].b;

            while (need > 0)
            {
                if (viz[j])
                {
                    j = next[parent(j)];
                }
                else
                {
                    viz[j] = 1;
                    update (j,1);
                    --need;
                    ++total;

                    if (viz[j-1])
                    {
                        unite(j,j-1);
                    }
                    if (viz[j+1])
                    {
                        unite(j,j+1);
                    }

                    j = next[parent(j)];
                }
            }
        }
    }

    total = query (v[n].b);
    cout<<total<<"\n";

    for (int i=1; i<=v[n].b; ++i)
    {
        if (viz[i])
          cout<<i-pl<<"\n";
    }
}
