#include<fstream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
char A[100100],B[100100],C[100100];
int n,nra[30],nrb[30],sterg[30],sol;
vector <int> adaug;

inline int Modul(int x)
{
	if(x<0)
		return -x;
	return x;
}

int main()
{
	int i,j,k,st,dr;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>(A+1);
	fin>>(B+1);
	n=strlen(A+1);
	for(i=1;i<=n;i++)
	{
		nra[A[i]-'A']++;
		C[i]=A[i];
		nrb[B[i]-'A']++;
	}
	for(i=0;i<30;i++)
	{
		sol+=Modul(nra[i]-nrb[i]);
		if(nra[i]<nrb[i])
		{
			for(j=1;j<=nrb[i]-nra[i];j++)
				adaug.push_back(i);
		}
		if(nra[i]>nrb[i])
			sterg[i]+=(nra[i]-nrb[i]);
	}
	sol/=2;
	sort(adaug.begin(),adaug.end());
	for(j=0,i=29;i>=0;i--)
	{
		if(sterg[i])
		{
			st=1;
			dr=n;
			while(sterg[i])
			{
				if(i>adaug[j])
				{
					if(A[st]==(char)(i+'A'))
					{
						C[st]=(char)(adaug[j]+'A');
						j++;
						sterg[i]--;
					}
					st++;
				}
				else
				{
					if(A[dr]==(char)(i+'A'))
					{
						C[dr]=(char)(adaug[j]+'A');
						j++;
						sterg[i]--;
					}
					dr--;
				}
			}
		}
	}
	fout<<sol<<"\n";
	fout<<(C+1)<<"\n";
	
	fin.close();
	fout.close();
	return 0;
}
