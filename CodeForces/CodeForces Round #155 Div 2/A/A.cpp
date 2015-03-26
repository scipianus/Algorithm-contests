#include<fstream>
#include<algorithm>
using namespace std;
int n,nr[5010];
struct Carte{int val,ind;};
Carte v[600100];

inline bool Sortare(Carte A,Carte B)
{
	return A.val<B.val;
}

int main()
{
	int i;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>n;
	for(i=1;i<=2*n;i++)
	{
		fin>>v[i].val;
		nr[v[i].val]++;
		v[i].ind=i;
	}
	sort(v+1,v+2*n+1,Sortare);
	for(i=1;i<=5000;i++)
	{
		if(nr[i]%2==1)
		{
			fout<<"-1\n";
			fout.close();
			return 0;
		}
	}
	for(i=1;i<=2*n;i++)
	{
		fout<<v[i].ind<<' '<<v[i+1].ind<<"\n";
		i++;
	}
	
	
	fin.close();
	fout.close();
	return 0;
}
