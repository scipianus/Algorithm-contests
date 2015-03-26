#include <fstream>
#include <ctime>
#include <algorithm>
using namespace std;

int main()
{
	int i, j;
	srand(time(NULL));
	ofstream fout("B.in");
	fout << "100 20 1000000000\n";
	j = 1;
	for(i = 1; i <= 100; ++i)
	{
		fout << "1000000000 " << (rand() % 1000000000 + 1) << " 1\n";
		fout << j << "\n";
		j++;
		if(j == 21)
			j = 1;
	}
	fout.close();
	return 0;
}
