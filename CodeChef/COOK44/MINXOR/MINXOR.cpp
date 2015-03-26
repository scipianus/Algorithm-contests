#include <iostream>
using namespace std;
int n, Q, v[255000], tip, L, R, K;
struct Nod{int minim, lazy;};
Nod A[1100000];

inline void Build(int nod, int st, int dr)
{
	if(st == dr)
	{
		A[nod].minim = v[st];
		return;
	}
	int mij = (st + dr) / 2;
	Build(2 * nod, st, mij);
	Build(2 * nod + 1, mij + 1, dr);
	A[nod].minim = min(A[2 * nod].minim, A[2 * nod + 1].minim);
}

inline void Update(int nod, int st, int dr)
{
	
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int i;
	cin >> n >> Q;
	for(i = 1; i <= n; ++i)
		cin >> v[i];
	Build(1, 1, n);
	while(Q--)
	{
		cin >> tip >> L >> R;
		if(tip == 1)
		{
		}
		else
		{
			cin >> K;
			Update(1, 1, n);
		}
	}
	return 0;
}
