#include <fstream>
#include <cstring>
using namespace std;
int n, v[210], moves, nr[210][2010];

inline void Merge(int st, int dr)
{
	moves += dr - st;
	if(dr - st + 1 <= 2)
		return;
	int i, mij = (st + dr) / 2, aux;
	aux = v[dr - 1];
	for(i = dr - 1; i > mij; --i)
		v[i] = v[i - 1];
	v[mij] = aux;
	Merge(st, mij);
	Merge(mij + 1, dr);
}

inline void Copiere(int A[], int B[])
{
	for(int i = 0; i <= B[0]; ++i)
		A[i] = B[i];
}

inline void Impartire(int A[], int B)
{
    int i, t = 0;
    for(i = A[0]; i > 0; --i, t %= B)
    {
        t = t * 10 + A[i];
        A[i] = t / B;
    }
    while(A[0] > 1 && A[A[0]] == 0)
        A[0]--;
}

inline void Inmultire(int A[], int B)
{
	int i, t = 0;
	for(i = 1; i <= A[0] || t; ++i, t /= 10)
		A[i] = (t += A[i] * B) % 10;
	A[0] = i - 1;
}

inline void InmultireMare(int A[], int B[])
{
    int i, j, t, P[2010];
    memset(P, 0, sizeof(P));
    for(i = 1; i <= A[0]; ++i)
    {
        t = 0;
        for(j = 1; j <= B[0] || t; ++j, t /= 10)
            P[i + j - 1] = (t += P[i + j - 1] + A[i] * B[j]) % 10;
        if(i + j - 2 > P[0])
            P[0] = i + j - 2;
    }
	memset(A, 0, sizeof(A));
	Copiere(A, P);
}

inline void Count()
{
	int i, j, comb[2010];
	nr[1][0] = nr[1][1] = 1;
	for(i = 2; i <= n; ++i)
	{
		// nr[n] = 2 * nr[n/2] * nr[n-n/2] * Comb(n-2,n/2-1);
		Copiere(nr[i], nr[i / 2]);
		InmultireMare(nr[i], nr[i - i / 2]);
		Inmultire(nr[i], 2);
		
		memset(comb, 0, sizeof(comb));
		comb[1] = comb[0] = 1;
		for(j = (i - 2) - (i / 2 - 1) + 1; j <= i - 2; ++j)
			Inmultire(comb, j);
		for(j = 2; j <= i / 2 - 1; ++j)
			Impartire(comb, j); 
		
		InmultireMare(nr[i], comb);
	}
}

int main()
{
	int i;
	ifstream fin("merge.in");
	fin >> n;
	fin.close();
	for(i = 1; i <= n; ++i)
		v[i] = i;
	
	Merge(1, n);
	Count();
	
	ofstream fout("merge.out");
	fout << moves << "\n";
	for(i = 1; i <= n; ++i)
		fout << v[i] << ' ';
	fout << "\n";
	for(i = nr[n][0]; i > 0; i--)
		fout << nr[n][i];
	fout << "\n";
	fout.close();
	return 0;
}
