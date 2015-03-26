#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;
int T, n, v[10100], bin[10100], sol;
vector <pii> moves;

inline void Reverse(int st,int dr)
{
    sol++;
	moves.push_back(make_pair(st, dr));
    int i, lg = (dr - st + 1) / 2;
    for(i = st; i + lg <= dr; ++i)
    {
        swap(v[i], v[i + lg]);
        swap(bin[i], bin[i + lg]);
    }
}
 
inline void SortareBinara(int st, int dr)
{
    if(st >= dr)
        return;
    int mij = (st + dr) / 2, First[2], Last[2], lg;
    SortareBinara(st, mij);
    SortareBinara(mij + 1, dr);
    int i, j;
    i = mij;
    while(i >= st && bin[i] == 1)
        i--;
    i++;
    if(i > mij)
        return;
    j = mij + 1;
    while(j <= dr && bin[j] == 0)
        j++;
    j--;
    if(j <= mij)
        return;
	// am 1 in intervalul [i, mij] si 0 in intervalul [mij + 1, j]
	First[0] = mij + 1; Last[0] = j;
	First[1] = i; Last[1] = mij;
	while(First[0] <= Last[0] && First[1] <= Last[1])
	{
		if(Last[0] - First[0] + 1 <= Last[1] - First[1] + 1)
		{
			lg = Last[0] - First[0] + 1;
			Reverse(First[0] - lg, Last[0]);
			First[0] -= lg;
			Last[0] -= lg;
			Last[1] -= lg;
		}
		else
		{
			lg = Last[1] - First[1] + 1;
			Reverse(First[1], Last[1] + lg);
			First[1] += lg;
			Last[1] += lg;
			First[0] += lg;
		}
	}
}
 
inline void Sortare(int st, int dr)
{
    if(st >= dr)
        return;
    int mij = (st + dr) / 2;
    for(int i = st;i <= dr; ++i)
    {
        if(v[i] > mij)
            bin[i] = 1;
        else
            bin[i] = 0;
    }
    SortareBinara(st, dr);
    Sortare(st, mij);
    Sortare(mij + 1, dr);
}

int main()
{
	int i;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(i = 1; i <= n; ++i)
			cin >> v[i];
		Sortare(1, n);
		cout << sol << "\n";
		for(i = 0; i < sol; ++i)
			cout << moves[i].first << ' ' << moves[i].second << "\n";
		sol = 0;
		moves.clear();
	}
	return 0;
}
