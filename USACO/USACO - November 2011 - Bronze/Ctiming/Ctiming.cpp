/*
PROB: ctiming
LANG: C++
*/
#include<fstream>
using namespace std;
int main()
{
	int nr1,nr2,D,H,M;
	ifstream fin("ctiming.in");
	fin>>D>>H>>M;
	fin.close();
	ofstream fout("ctiming.out");
	nr1=11*1440+11*60+11;
	nr2=D*1440;
	nr2+=(H*60);
	nr2+=M;
	nr2-=nr1;
	if(nr2<0)
		fout<<"-1\n";
	else
		fout<<nr2<<"\n";
	fout.close();
	return 0;
}
