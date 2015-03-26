#include <iostream>
#define pii pair<int, int>
#include <set>
using namespace std;
int n, K, banc[5010], Q, needed, rez;
set <pii> posibil;

int main()
{
	int i, sum, now;
	set <pii>::iterator it, jt;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> K;
	posibil.insert(make_pair(0, 0));
	for(i = 1; i <= n; ++i)
	{
		cin >> banc[i];
		sum = banc[i];
		now = 1;
		while(now <= K)
		{
			posibil.insert(make_pair(sum, now));
			sum += banc[i];
			now++;
		}
	}
	cin >> Q;
	while(Q--)
	{
		cin >> needed;
		rez = K + 1;
		for(it = posibil.begin(); it != posibil.end(); ++it)
		{
			if((*it).first > needed)
				break;
			jt = posibil.lower_bound(make_pair(needed - (*it).first, 0));
			if(jt == posibil.end())
				continue;
			if((*jt).first + (*it).first != needed)
				continue;
			rez = min(rez, (*it).second + (*jt).second);
		}
		if(rez == K + 1)
			rez = -1;
		cout << rez << "\n";
	}
	return 0;
}
