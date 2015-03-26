#include <iostream>
#include <vector>
using namespace std;
int n, m;
struct Punct{long long x, y;};
Punct P[100100];
int St[100100], vf;
vector <int> G[100100];
bool viz[100100];
int euler[200100], adancime[200100], poz[200100];
int rmq[19][200100], minpoz[19][200100], loga[200100];

inline long long Intoarcere(Punct A, Punct B, Punct C)
{
	return (A.x * B.y + B.x * C.y + C.x * A.y - A.y * B.x - B.y * C.x - C.y * A.x);
}

inline void DFS(int x, int level)
{
	viz[x] = true;
	vector <int>::iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
	{
		if(!viz[*it])
		{
			vf++;
			euler[vf] = x;
			adancime[vf] = level;
			DFS(*it, level + 1);
		}
	}
	vf++;
	euler[vf] = x;
	adancime[vf] = level;
	poz[x] = vf;
}

inline void RMQ()
{
	int i, k;
	for(i = 1; i <= vf; ++i)
	{
		rmq[0][i] = adancime[i];
		minpoz[0][i] = i;
	}
	for(k = 1; (1 << k) <= vf; ++k)
	{
		for(i = 1; i + (1 << k) <= vf + 1; ++i)
		{
			if(rmq[k - 1][i] < rmq[k - 1][i + (1 << (k - 1))])
			{
				rmq[k][i] = rmq[k - 1][i];
				minpoz[k][i] = minpoz[k - 1][i];
			}
			else
			{
				rmq[k][i] = rmq[k - 1][i + (1 << (k - 1))];
				minpoz[k][i] = minpoz[k - 1][i + (1 << (k - 1))];
			}
		}
	}
	loga[1] = 0;
	for(i = 2; i <= vf; ++i)
		loga[i] = loga[i / 2] + 1;
}

inline int LCA(int x, int y)
{
	int st, dr, lg, k, dif;
	st = poz[x];
	dr = poz[y];
	if(st > dr)
		swap(st, dr);
	lg = dr - st + 1;
	k = loga[lg];
	dif = lg - (1 << k);
	if(rmq[k][st] < rmq[k][st + dif])
		return euler[minpoz[k][st]];
	return euler[minpoz[k][st + dif]];
}

int main()
{
	int i, x, y;
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++i)
		cin >> P[i].x >> P[i].y;
	
	St[++vf] = n;
	for(i = n - 1; i > 0; --i)
	{
		while(vf >= 2 && Intoarcere(P[i], P[St[vf]], P[St[vf - 1]]) > 0LL)
			vf--;
		G[i].push_back(St[vf]);
		G[St[vf]].push_back(i);
		St[++vf] = i;
	}
	vf = 0;
	DFS(n, 1);
	RMQ();
	
	cin >> m;
	while(m--)
	{
		cin >> x >> y;
		cout << LCA(x, y) << ' ';
	}
	cout << "\n";
	return 0;
}
