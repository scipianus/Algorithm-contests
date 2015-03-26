#include <iostream>
#include <vector>
using namespace std;
int n, m, K, W, dist[1010][1010], sol, ord[1010], tip[1010], nrord, best[1010], indbest[1010];
char mat[1010][12][12];
bool uz[1010];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i, j, ii, jj, now, ales;
	cin >> n >> m >> K >> W;
	for(i = 1; i <= K; ++i)
		for(j = 1; j <= n; ++j)
			cin >> (mat[i][j] + 1);
	for(i = 1; i <= K; ++i)
	{
		for(j = i + 1; j <= K; ++j)
		{
			now = 0;
			for(ii = 1; ii <= n; ++ii)
				for(jj = 1; jj <= m; ++jj)
					if(mat[i][ii][jj] != mat[j][ii][jj])
						now++;
			dist[i][j] = dist[j][i] = now;
		}
	}
	
	ord[1] = 1;
	tip[1] = 0;
	uz[1] = true;
	sol = n * m;
	for(i = 1; i <= K; ++i)
	{
		best[i] = dist[1][i];
		indbest[i] = 1;
	}
	for(i = 2; i <= K; ++i)
	{
		ales = 0;
		for(j = 1; j <= K; ++j)
		{
			if(!uz[j])
			{
				if(!ales || (best[j] < best[ales]))
				{
					ales = j;
				}
			}
		}
		ord[i] = ales;
		uz[ales] = true;
		if(best[ales] * W < n * m)
		{
			tip[i] = indbest[ales];
			sol += best[ales] * W;
		}
		else
		{
			tip[i] = 0;
			sol += n * m;
		}
		for(j = 1; j <= K; ++j)
		{
			if(!uz[j])
			{
				if(best[j] > dist[ales][j])
				{
					best[j] = dist[ales][j];
					indbest[j] = ales;
				}
			}
		}
	}
	cout << sol << "\n";
	for(i = 1; i <= K; ++i)
		cout << ord[i] << ' ' << tip[i] << "\n";
	return 0;
}
