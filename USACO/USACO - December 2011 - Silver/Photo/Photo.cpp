/*
PROB: photo
LANG: C++
*/
#include<fstream>
#include<vector>
#include<map>
using namespace std;
int n,v[5][20010],id[20010],per[20010],grad[20010];
vector <short> G[20010];
map <int,short> M;

void Citire()
{
	int i,j;
	ifstream fin("photo.in");
	fin>>n;
	for(i=1;i<=5;i++)
		for(j=1;j<=n;j++)
			fin>>v[i][j];
	fin.close();
}

void Rezolvare()
{
	int j,k,vec[5],val[5],maxim,inc;
	short i;
	bool gasit;
	for(i=1;i<=n;i++)
	{
		id[i]=v[1][i];
		M[v[1][i]]=i;
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<n;j++)
		{
			G[M[v[i][j]]].push_back(M[v[i][j+1]]);
		}
	}
	vector <short>::iterator it;
	for(i=1;i<n;i++)
	{
		for(j=0;j<5;j++)
			vec[j]=val[j]=0;
		for(it=G[i].begin();it!=G[i].end();it++)
		{
			gasit=false;
			for(k=0;k<5 && !gasit;k++)
			{
				if(vec[k]==0)
				{
					vec[k]=*it;
					val[k]=1;
					gasit=true;
				}
				else
					if(*it==vec[k])
					{
						val[k]++;
						gasit=true;
					}
			}
		}
		maxim=0;
		for(j=1;j<5;j++)
			if(val[j]>val[maxim])
				maxim=j;
		per[i]=vec[maxim];
		grad[vec[maxim]]++;
	}
	inc=0;
	for(i=1;i<=n && inc==0;i++)
	{
		if(grad[i]==0)
			inc=i;
	}
	if(inc==0)
	{
		inc=n;
		i=n;
		for(j=0;j<5;j++)
			vec[j]=val[j]=0;
		for(it=G[i].begin();it!=G[i].end();it++)
		{
			gasit=false;
			for(k=0;k<5 && !gasit;k++)
			{
				if(vec[k]==0)
				{
					vec[k]=*it;
					val[k]=1;
					gasit=true;
				}
				else
					if(*it==vec[k])
					{
						val[k]++;
						gasit=true;
					}
			}
		}
		maxim=0;
		for(j=1;j<5;j++)
			if(val[j]>val[maxim])
				maxim=j;
		per[i]=vec[maxim];
		grad[vec[maxim]]++;
	}
	ofstream fout("photo.out");
	for(i=1;i<=n;i++)
	{
		fout<<id[inc]<<"\n";
		inc=per[inc];
	}
	fout.close();
}

int main()
{
	Citire();
	Rezolvare();
	return 0;
}
