/*
PROB: empty 
LANG: C++
*/
#include <fstream>
using namespace std;
int n, K, nr[3000100];
bool ocupat[3000100];

inline int Mod(int x)
{
	while(x >= n)
		x -= n;
	return x;
}

int main()
{
	int i, j, x, y, a, b, poz, rest;
	bool exista = false;
	ifstream fin("empty.in");
	fin >> n >> K;
	while(K--)
	{
		fin >> x >> y >> a >> b;
		for(i = 1; i <= y; ++i)
		{
			poz = (1LL * a * i + 1LL * b) % n;
			nr[poz] += x;
		}
	}
	fin.close();
	
	for(i = 0; i < n; ++i)
	{
		if(nr[i])
		{
			ocupat[i] = true;
			nr[i]--;
			if(nr[i])
				exista = true;
		}
	}
	if(exista)
	{
		j = 0;
		while(ocupat[j])
			j++;
		for(i = 0; i < n; ++i)
		{
			if(nr[i])
			{
				if(j < i)
				{
					j = i;
					while(ocupat[Mod(j)])
						j++;
				}
				rest = nr[i];
				while(rest)
				{
					while(ocupat[Mod(j)])
						j++;
					ocupat[Mod(j)] = true;
					rest--;
					j++;
				}
			}
		}
	}
	
	ofstream fout("empty.out");
	for(i = 0; i < n; ++i)
	{
		if(!ocupat[i])
		{
			fout << i << "\n";
			i = n;
		}
	}
	fout.close();
	return 0;
}
