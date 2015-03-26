#include <iostream>
#include <algorithm>
using namespace std;
int v[10][4], ord[10][4], sol[10][4];
bool gasit, uz[10][4];

inline long long Dist(int a1, int a2, int a3, int b1, int b2, int b3)
{
	return (1LL * (a1 - b1) * (a1 - b1) + 1LL * (a2 - b2) * (a2 - b2) + 1LL * (a3 - b3) * (a3 - b3));
}

inline void Verif()
{
	long long vd[7], L, d, D;
	int i, j, k;
	for(i = 2; i <= 8; ++i)
		vd[i - 2] = Dist(v[1][ord[1][0]], v[1][ord[1][1]], v[1][ord[1][2]], v[i][ord[i][0]], v[i][ord[i][1]], v[i][ord[i][2]]);
	sort(vd, vd + 7);
	if(vd[0] == 0)
		return;
	if(vd[0] != vd[2])
		return;
	if(vd[2] == vd[3] || vd[3] != vd[5])
		return;
	if(vd[5] == vd[6])
		return;
	L = vd[0];
	d = vd[3];
	D = vd[6];
	for(i = 2; i <= 8; ++i)
	{
		k = 0;
		for(j = 1; j <= 8; ++j)
		{
			if(i != j)
			{
				vd[k] = Dist(v[j][ord[j][0]], v[j][ord[j][1]], v[j][ord[j][2]], v[i][ord[i][0]], v[i][ord[i][1]], v[i][ord[i][2]]);
				k++;
			}
		}
		sort(vd, vd + 7);
		if(vd[0] != vd[2])
			return;
		if(vd[2] == vd[3] || vd[3] != vd[5])
			return;
		if(vd[5] == vd[6])
			return;
		if(vd[0] != L || vd[3] != d || vd[6] != D)
			return;
	}
	gasit = true;
	for(i = 1; i <= 8; ++i)
		for(j = 0; j < 3; ++j)
			sol[i][j] = v[i][ord[i][j]];
}

inline void Back(int pasx, int pasy)
{
	if(gasit)
		return;
	if(pasy == 3)
	{
		Back(pasx + 1, 0);
		return;
	}
	if(pasx == 9)
	{
		Verif();
		return;
	}
	int i;
	for(i = 0; i < 3; ++i)
	{
		if(!uz[pasx][i])
		{
			uz[pasx][i] = true;
			ord[pasx][pasy] = i;
			Back(pasx, pasy + 1);
			uz[pasx][i] = false;
		}
	}
}

int main()
{
	int i;
	std::ios_base::sync_with_stdio(false);
	for(i = 1; i <= 8; ++i)
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	Back(1, 0);
	if(!gasit)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for(i = 1; i <= 8; ++i)
			cout << sol[i][0] << ' ' << sol[i][1] << ' ' << sol[i][2] << "\n";
	}
	return 0;
}
