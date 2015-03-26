#include<fstream>
using namespace std;
int n,m;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>n>>m;
	while(n>0 && m>0)
	{
		if(n>m)
			fout<<"BG";
		else
			fout<<"GB";
		n--;
		m--;
	}
	while(n>0)
	{
		fout<<"B";
		n--;
	}
	while(m>0)
	{
		fout<<"G";
		m--;
	}
	fout<<"\n";
	
	fin.close();
	fout.close();
	return 0;
}
