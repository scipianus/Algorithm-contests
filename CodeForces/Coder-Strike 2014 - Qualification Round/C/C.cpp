#include <iostream>
using namespace std;
int att[5], def[5], Att[2], Def[2];

inline int Rez()
{
	if(Att[0] > Def[1] && Def[0] > Att[1])
		return 1;
	if(Att[1] > Def[0] && Def[1] > Att[0])
		return -1;
	return 0;
}

int main()
{
	int i, rez[2];
	for(i = 1; i <= 4; ++i)
		cin >> att[i] >> def[i];
	// caut victoria mea mai intai
	// primul mod
	Att[0] = att[1];
	Def[0] = def[2];
	// 1 - 3
	Att[1] = att[3];
	Def[1] = def[4];
	rez[0] = Rez();
	// 1 - 4
	Att[1] = att[4];
	Def[1] = def[3];
	rez[1] = Rez();
	// verific
	if(rez[0] == 1 && rez[1] == 1)
	{
		cout << "Team 1\n";
		return 0;
	}
	// al doilea mod
	Att[0] = att[2];
	Def[0] = def[1];
	// 2 - 3
	Att[1] = att[3];
	Def[1] = def[4];
	rez[0] = Rez();
	// 2 - 4
	Att[1] = att[4];
	Def[1] = def[3];
	rez[1] = Rez();
	// verific
	if(rez[0] == 1 && rez[1] == 1)
	{
		cout << "Team 1\n";
		return 0;
	}
	// caut altfel remiza
	// primul mod
	Att[0] = att[1];
	Def[0] = def[2];
	// 1 - 3
	Att[1] = att[3];
	Def[1] = def[4];
	rez[0] = Rez();
	// 1 - 4
	Att[1] = att[4];
	Def[1] = def[3];
	rez[1] = Rez();
	// verific
	if(rez[0] >= 0 && rez[1] >= 0)
	{
		cout << "Draw\n";
		return 0;
	}
	// al doilea mod
	Att[0] = att[2];
	Def[0] = def[1];
	// 2 - 3
	Att[1] = att[3];
	Def[1] = def[4];
	rez[0] = Rez();
	// 2 - 4
	Att[1] = att[4];
	Def[1] = def[3];
	rez[1] = Rez();
	// verific
	if(rez[0] >= 0 && rez[1] >= 0)
	{
		cout << "Draw\n";
		return 0;
	}
	// altfel inseamna ca pierd
	cout << "Team 2\n";
	return 0;
}
