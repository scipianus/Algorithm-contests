#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;
int n, vsort[10100], poz[10100], v[10100], bin[10100];
vector <pii> sol;
 
inline void Reverse(int st, int dr)
{
	sol.push_back(make_pair(st, dr));
    int i, j, mij = (st + dr) / 2;
    for(i = st; i <= mij; ++i)
    {
        j = dr - (i - st);
        swap(v[i], v[j]);
        swap(bin[i], bin[j]);
    }
}
 
inline void SortareBinara(int st, int dr)
{
    if(st >= dr)
        return;
    int mij = (st + dr) / 2;
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
    Reverse(i, j);
}
 
inline void Sortare(int st, int dr)
{
    if(st >= dr)
        return;
    int mij = (st + dr) / 2;
    for(int i = st; i <= dr; ++i)
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
	std::ios_base::sync_with_stdio(false);
    int i, pz;
    cin >> n;
    for(i = 1; i <= n; ++i)
    {
        cin >> v[i];
        vsort[i] = v[i];
    }
    sort(vsort + 1, vsort + n + 1);
    for(i = 1; i <= n; ++i)
        poz[i] = i;
    for(i = 1; i <= n; ++i)
    {
        pz = lower_bound(vsort + 1, vsort + n + 1, v[i]) - vsort;
        v[i] = poz[pz];
        poz[pz]++;
    }
    Sortare(1, n);
    cout << sol.size() << "\n";
	for(i = 0; i < sol.size(); ++i)
		cout << sol[i].first << ' ' << sol[i].second << "\n";
    return 0;
}
