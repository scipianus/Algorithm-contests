#include <iostream>
#include <queue>
using namespace std;
int n, ordin[510];
long long mat[510][510];
queue <int> Q;
long long d[510];
bool bagat[510];
 
inline bool Posibil(int val)
{
    int i, x, nod;
	long long cost;
    while(!Q.empty())
        Q.pop();
    for(i = 1; i <= n; ++i)
    {
        d[i] = 2000000000000000000LL;
        bagat[i] = false;
        ordin[i] = 0;
    }
    for(i = 1; i <= n; ++i)
    {
        if(d[i] == 2000000000000000000LL)
        {
            d[i] = 0;
            Q.push(i);
            bagat[i] = true;
            while(!Q.empty())
            {
                x = Q.front();
                Q.pop();
                bagat[x] = false;
                for(nod = 1; nod <= n; ++nod)
                {
					if(nod == x)
						continue;
                    cost = mat[x][nod] - 1LL * val;
                    if(d[nod] > d[x] + cost)
                    {
                        d[nod] = d[x] + cost;
                        if(!bagat[nod])
                        {
                            if(ordin[nod] > n)
                                return true;
                            else
                            {
                                Q.push(nod);
                                bagat[nod] = true;
                                ordin[nod] = ordin[x] + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
 
inline int CautareBinara()
{
    int st, dr, mij, rez = 1;
    st = 1;
    dr = 2000000010;
    while(st <= dr)
    {
        mij = (dr - st) / 2 + st;
        if(Posibil(mij))
        {
            rez = mij;
            dr = mij - 1;
        }
        else
            st = mij + 1;
    }
    return rez - 1;
}
 
inline int Gcd(int a, int b)
{
	int r;
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
    int i, j, A, B, gcd;
    cin >> n;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
		{
			cin >> mat[i][j];
			mat[i][j] *= 10000000LL;
		}
	A = CautareBinara();
	B = 10000000;
	gcd = Gcd(A, B);
	A /= gcd;
	B /= gcd;
	cout << A << "/" << B << "\n";
    return 0;
}
