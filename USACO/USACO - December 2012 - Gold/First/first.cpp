/*
PROB : first
LANG : C++
*/
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;
int n,ns[30100];
string cuv[30100];
vector <string> sol;
bool mat[30][30],ok;
int viz[30];

inline void DFS(int x,int ind)
{
	if(!ok)
		return;
	viz[x]=ind;
	int i;
	for(i=0;i<30;i++)
	{
		if(mat[x][i])
		{
			if(viz[i]==ind)
			{
				ok=false;
				i=30;
			}
			else
				DFS(i,ind);
		}
	}
}

int main()
{
	int i,j,k,l;
	bool egal;
	ifstream fin("first.in");
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>cuv[i];
		ns[i]=cuv[i].size();
	}
	fin.close();
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j==i)
				continue;
			egal=true;
			for(k=0;k<ns[i] && egal;k++)
			{
				if(cuv[i][k]!=cuv[j][k])
					egal=false;
			}
			if(egal && ns[i]>ns[j])
			{
				j=n+1;
				continue;
			}
			for(k=0;k<ns[i];k++)
			{
				if(cuv[i][k]!=cuv[j][k])
				{
					mat[cuv[i][k]-'a'][cuv[j][k]-'a']=true;
					if(mat[cuv[j][k]-'a'][cuv[i][k]-'a'])
					{
						k=ns[i];
						j=n+1;
						continue;
					}
					k=ns[i];
				}
			}
		}
		if(j==n+2)
		{
			for(k=0;k<30;k++)
				for(l=0;l<30;l++)
					mat[k][l]=false;
			continue;
		}
		ok=true;
		for(j=0;j<30;j++)
			DFS(j,j+1);
		if(ok)
			sol.push_back(cuv[i]);
		for(j=0;j<30;j++)
			viz[j]=0;
	}
	n=sol.size();
	
	ofstream fout("first.out");
	fout<<n<<"\n";
	for(i=0;i<n;i++)
		fout<<sol[i]<<"\n";
	fout.close();
	return 0;
}
