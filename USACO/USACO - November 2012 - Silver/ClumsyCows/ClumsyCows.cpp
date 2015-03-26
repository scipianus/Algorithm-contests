/*
PROB: clumsy
LANG: C++
*/
#include<fstream>
#include<cstring>
using namespace std;
int n,vf,sol;
char s[100100];

int main()
{
	int i;
	ifstream fin("clumsy.in");
	fin>>(s+1);
	fin.close();
	
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='(')
			vf++;
		else
		{
			if(vf==0)
			{
				sol++;
				vf++;
			}
			else
				vf--;
		}
	}
	if(vf)
		sol+=(vf/2);
	
	ofstream fout("clumsy.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
