#include <fstream>
#include <cstring>
#include <set>
#define H 31
#define MOD 123457
#define H2 47
#define MOD2 234571
#define pii pair<int, int>
using namespace std;
int n,sol;
char A[5010];
set <pii> soli[2510],solp[2510];

int main()
{
	int i, lg, now, now2;
	ifstream fin("palindromes.in");
	fin >> (A + 1);
	fin.close();
	
	n = strlen(A + 1);
	for( i = 1; i <= n; ++i)
	{
		// lungime impara
		now = A[i];
		now2 = A[i];
		soli[0].insert(make_pair(now, now2));
		lg=0;
		while(i + lg + 1 <= n && i - lg - 1 > 0 && A[i + lg + 1] == A[i - lg - 1])
		{
			lg++;
			now = (now * H + A[i + lg]) % MOD;
			now2 = (now2 * H2 + A[i + lg]) % MOD2;
			soli[lg].insert(make_pair(now, now2));
		}
		// lungime para
		if( i + 1 <= n && A[i] == A[i + 1])
		{
			now = A[i + 1];
			now2 = A[i + 1];
			solp[0].insert(make_pair(now, now2));
			lg = 0;
			while(i + lg + 2 <= n && i - lg - 1 > 0 && A[i + lg + 2] == A[i - lg - 1])
			{
				lg++;
				now = (now * H + A[i + lg + 1]) % MOD;
				now2 = (now2 * H2 + A[i + lg +1]) % MOD2;
				solp[lg].insert(make_pair(now, now2));
			}
		}
	}
	for( i = 0; i <= n/2 + 1; ++i)
		sol += soli[i].size() + solp[i].size();
	
	ofstream fout("palindromes.out");
	fout << sol << "\n";
	fout.close();
	return 0;
}
