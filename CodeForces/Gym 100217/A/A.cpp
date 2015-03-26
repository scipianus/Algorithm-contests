#include <fstream>
#include <map>
using namespace std;
int m;
map <pair<int, int>, int > cod;
// m * 2^m stari de forma (conf, i)
// insemnand ca am ajuns la linia i, coloana j, completand liniile 1...i-1
// considerand coloanele j-1,j,j+1 atunci arata asa
// bit 0 pe pozitie inainte de i inseamna .X.
// bit 0 pe pozitie dupa i inseamna X..
// bit 1 pe pozitie inainte de i inseamna .XX
// bit 1 pe pozitie dupa i inseamna XX.
// starea m * 2^m + 1 este starea imposibila, care duce doar in ea insasi
// starea (0, 1) este si initiala si finala

int main()
{
	int i, conf, nr = 0, imposibil;
	ifstream fin("automata.in");
	fin >> m;
	fin.close();
	
	// numerotez starile
	for(conf = 0; conf < (1 << m); ++conf)
		for(i = 1; i <= m; ++i)
			cod[make_pair(conf, i)] = ++nr;
	imposibil = ++nr;
	
	ofstream fout("automata.out");
	fout << nr << ' ' << cod[make_pair(0, 1)] << "\n";
	fout << 1 << ' ' << cod[make_pair(0, 1)] << "\n";
	for(conf = 0; conf < (1 << m); ++conf)
	{
		for(i = 1; i <= m; ++i)
		{
			// H - pun pe orizontala
			if(conf & (1 << (i - 1))) // e ocupata casuta
				fout << imposibil << ' ';
			else
			{
				if(i < m)
					fout << cod[make_pair(conf + (1 << (i - 1)), i + 1)] << ' ';
				else
					fout << cod[make_pair(conf + (1 << (i - 1)), 1)] << ' ';
			}
			// V - pun pe verticala
			if(i == m || (conf & (1 << (i - 1))) || (conf & (1 << i))) // ori sunt pe ultima linie, ori e ocupata una din cele doua casute
				fout << imposibil << ' ';
			else
			{
				fout << cod[make_pair(conf + (1 << i), i + 1)] << ' ';
			}
			// S - trec mai departe
			if(!(conf & (1 << (i - 1)))) // nu e ocupata casuta curenta si ar ramane goala deci
				fout << imposibil << "\n";
			else
			{
				if(i < m)
					fout << cod[make_pair(conf - (1 << (i - 1)), i + 1)] << "\n";
				else
					fout << cod[make_pair(conf - (1 << (i - 1)), 1)] << "\n";
			}
		}
	}
	// afisez si starea imposibila care duce doar in ea insasi
	fout << imposibil << ' ';
	fout << imposibil << ' ';
	fout << imposibil << "\n";
	fout.close();
	return 0;
}
