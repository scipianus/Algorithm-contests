#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n, m, T, sol[20100], diff;
pair <int, int> v[20100];
map <int, int> nr;
multiset <int> S;
set <int> Sdiff;
vector <int> vsort;

inline int ConvertToSeconds(string s)
{
	int hours, minutes, seconds;
	hours = (s[0] - '0') * 10 + s[1] - '0';
	minutes = (s[3] - '0') * 10 + s[4] - '0';
	seconds = (s[6] - '0') * 10 + s[7] - '0';
	return (hours * 60 * 60 + minutes * 60 + seconds);
}

int main()
{
	int i, j, st, dr, nrs, maxim = 0, now;
	string s;
	std::ios_base::sync_with_stdio(false);
	cin >> n >> m >> T;
	for(i = 1; i <= n; ++i)
	{
		cin >> s;
		nrs = ConvertToSeconds(s);
		v[i] = make_pair(nrs, nrs + T - 1);
	}
	st = 1;
	dr = 1;
	now = 0;
	for(i = 0; i <= 86400; ++i)
	{
		while(dr <= n && v[dr].first == i)
		{
			sol[dr] = -(*(S.begin())) + 1;
			S.insert(-sol[dr]);
			nr[sol[dr]]++;
			now++;
			dr++;
		}
		while(st <= dr && v[st].second < i)
		{
			nr[sol[st]]--;
			if(nr[sol[st]] == 0)
				now--;
			st++;
		}
		if(now > m)
		{
			j = dr - (now - m);
			while(now > m)
			{
				S.erase(S.find(-sol[j]));
				S.insert(-sol[j - 1]);
				nr[sol[j]]--;
				nr[sol[j - 1]]++;
				if(nr[sol[j]] == 0)
					now--;
				sol[j] = sol[j - 1];
				j++;
			}
		}
		maxim = max(maxim, now);
	}
	if(maxim != m)
		cout << "No solution\n";
	else
	{
		for(i = 1; i <= n; ++i)
			Sdiff.insert(sol[i]);
		diff = Sdiff.size();
		set <int>::iterator it;
		for(it = Sdiff.begin(); it != Sdiff.end(); ++it)
			vsort.push_back(*it);
		for(i = 1; i <= n; ++i)
			sol[i] = lower_bound(vsort.begin(), vsort.end(), sol[i]) - vsort.begin() + 1;
		cout << diff << "\n";
		for(i = 1; i <= n; ++i)
			cout << sol[i] << "\n";
	}
	return 0;
}
