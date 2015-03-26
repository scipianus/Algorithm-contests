#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int T, A[100010], n, sol[100010], aux[100010], D, P[100010];
long double a, p, q;

inline void Adunare(int A[], int B[])
{
	int i, t = 0;
	for(i = 1; i <= A[0] || i <= B[0] || t; ++i, t /= 10)
		A[i] = (t += A[i] + B[i]) % 10;
	A[0] = i - 1;
}

inline void Inmultire(int A[], long long B)
{
	int i;
	long long t = 0;
	for(i = 1; i <= A[0] || t; ++i, t /= 10LL)
		A[i] = (t += 1LL * A[i] * B) % 10LL;
	A[0] = i - 1;
}

inline void Memset(int A[])
{
	int i;
	for(i = A[0]; i >= 0; --i)
		A[i] = 0;
}

inline void Copiere(int A[], int B[])
{
	int i;
	Memset(A);
	for(i = 0; i <= B[0]; ++i)
		A[i] = B[i];
}

inline void InmultireMare(int A[], int B[])
{
    int i, j, t;
    Memset(P);
    for(i = 1;i <= A[0]; i++)
    {
        t = 0;
        for(j = 1; j <= B[0] || t; j++, t /= 10)
            P[i + j - 1] = (t += P[i + j - 1] + A[i] * B[j]) % 10;
        if(i + j - 2 > P[0])
            P[0] = i + j - 2;
    }
    Copiere(A, P);
}

int main()
{
	int i, nr;
	long double rez;
	cin >> T;
	while(T--)
	{
		cin >> a >> p >> q >> D;
		/*rez = ( a * q + a * p * (1.0 - a) ) / ((a - 1.0) * (a - 1.0));
		if(D == 5)
			printf("%.5lf\n",rez);
		if(D == 6)
			printf("%.6lf\n",rez);
		if(D == 7)
			printf("%.7lf\n",rez);*/
		Memset(sol);
		Memset(A);
		A[0] = A[1] = 1;
		Inmultire(A, (long long)(a * q * 1000000.0 + 0.000001));
		Adunare(sol, A);
		Memset(A);
		A[0] = A[1] = 1;
		Inmultire(A, (long long)(a * p * (1.0 - a) * 1000000.0 + 0.000001));
		Adunare(sol, A);
		Inmultire(sol, (long long)(1000000.0 / ((1.0 - a) * (1.0 - a)) + 0.000001));
		for(i = sol[0]; i > 12; --i)
			cout << sol[i];
		if(sol[0] <= 12)
			cout << "0";
		cout << ".";
		nr = 0;
		for(i = 12; i > 0 && nr < D; --i, ++nr)
			cout << sol[i];
		while(nr < D)
		{
			cout << "0";
			nr++;
		}
		cout << "\n";
	}
	return 0;
}
