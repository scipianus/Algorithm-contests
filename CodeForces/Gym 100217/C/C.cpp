#include <fstream>
#include <vector>
using namespace std;
int n, m, S[2], D[2], pred[2010][2010];
vector <int> G[2010], drum[2];
// starea (i,j) = am ajuns din S[0] pana in i si din S[1] pana in j
// pred[i][j] <= n => (i,j) provine din (pred[i][j], j)
// pred[i][j] > n => (i,j) provine din (i, pred[i][j] - n)

inline void Citire()
{
	int i, x, y;
	ifstream fin("express.in");
	fin >> n >> m;
	fin >> S[0] >> D[0] >> S[1] >> D[1];
	if(S[0] > D[0])
		swap(S[0], D[0]);
	if(S[1] > D[1])
		swap(S[1], D[1]);
	for(i = 1; i <= m; ++i)
	{
		fin >> x >> y;
		G[x].push_back(y);
	}
	fin.close();
	
	// creez destinatii fictive pentru a evita tratarea
	// separata a unui caz particular S[0]<D[0]<S[1]<D[1]
	G[D[0]].push_back(n + 1);
	G[D[1]].push_back(n + 2);
	D[0] = n + 1;
	D[1] = n + 2;
	n += 2;
}

inline void Rezolvare()
{
	int i, j;
	vector <int>::iterator it;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			pred[i][j] = -1;
	pred[S[0]][S[1]] = 0;
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			if(pred[i][j] >= 0)
			{
				if(i < j)
				{
					for(it = G[i].begin(); it != G[i].end(); ++it)
						if(*it != j)
							pred[*it][j] = i;
				}
				else
				{
					for(it = G[j].begin(); it != G[j].end(); ++it)
						if(*it != i)
							pred[i][*it] = j + n;
				}
			}
		}
	}
}

inline void Afisare()
{
	int i, j;
	ofstream fout("express.out");
	if(pred[D[0]][D[1]] == -1)
		fout << "NO\n";
	else
	{
		fout << "YES\n";
		i = D[0];
		j = D[1];
		while(pred[i][j] > 0)
		{
			if(pred[i][j] <= n)
			{
				i = pred[i][j];
				drum[0].push_back(i);
			}
			else
			{
				j = pred[i][j] - n;
				drum[1].push_back(j);
			}
		}
		for(i = drum[0].size() - 1; i >= 0; --i)
			fout << drum[0][i] << ' ';
		fout << "\n";
		for(i = drum[1].size() - 1; i >= 0; --i)
			fout << drum[1][i] << ' ';
		fout << "\n";
	}
	fout.close();
}

int main()
{
	Citire();
	Rezolvare();
	Afisare();
	return 0;
}
