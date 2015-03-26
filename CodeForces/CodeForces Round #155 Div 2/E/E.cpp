#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,val,a[410];
struct Prieten{int st,dr,f,ind;};
Prieten v[410];
int best[410][810],sol;
int pre[410][810];
vector <int> pred[410][810];
vector <int> H,H2,vec,zi[410];

inline bool Sortare(Prieten A,Prieten B)
{
	return A.st<B.st;
}

inline bool Mancare(int a,int b)
{
	return v[a].f<v[b].f;
}

int main()
{
	int i,j,k,now,p,next,lim,x;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>n>>val;
	for(i=1;i<=n;i++)
		fin>>a[i];
	fin>>m;
	for(i=1;i<=m;i++)
	{
		fin>>v[i].st>>v[i].dr>>v[i].f;
		v[i].ind=i;
	}
	sort(v+1,v+m+1,Sortare);
	
	for(i=1;i<=n;i++)
		for(j=0;j<810;j++)
			best[i][j]=-2000000000;
	best[1][0]=0;
	k=1;
	for(i=1;i<=n;i++)
	{
		while(k<=m && v[k].st==i)
		{
			H2.push_back(k);
			k++;
		}
		for(j=H.size()-1;j>=0;j--)
		{
			if(v[H[j]].dr>=i)
				H2.push_back(H[j]);
		}
		H.clear();
		for(j=H2.size()-1;j>=0;j--)
			H.push_back(H2[j]);
		H2.clear();
		sort(H.begin(),H.end(),Mancare);
		lim=H.size();
		for(j=0;j<810;j++)
		{
			if(best[i][j]>=0)
			{
				now=j+a[i];
				now-=val;
				if(now<0)
				{
					best[i][j]=0;
					continue;
				}
				if(now>=a[i])
					next=a[i];
				else
					next=now;
				if(best[i+1][next]<best[i][j])
				{
					best[i+1][next]=best[i][j];
					pred[i+1][next].clear();
					pre[i+1][next]=j;
				}
				vec.clear();
				for(p=0;p<lim && now;p++)
				{
					if(v[H[p]].f<=now)
					{
						now-=v[H[p]].f;
						if(now>=a[i])
							next=a[i];
						else
							next=now;
						vec.push_back(v[H[p]].ind);
						if(best[i+1][next]<best[i][j]+p+1)
						{
							best[i+1][next]=best[i][j]+p+1;
							pred[i+1][next]=vec;
							pre[i+1][next]=j;
						}
					}
					else
						now=0;
				}
			}
		}
	}
	for(i=0;i<810;i++)
	{
		if(best[n+1][i]>sol)
		{
			sol=best[n+1][i];
			x=i;
		}
	}
	if(sol)
	{
		for(i=n+1;i>1;i--)
		{
			zi[i-1]=pred[i][x];
			x=pre[i][x];
		}
		fout<<sol<<"\n";
		for(i=1;i<=n;i++)
		{
			lim=zi[i].size();
			fout<<lim<<' ';
			for(j=0;j<lim;j++)
				fout<<zi[i][j]<<' ';
			fout<<"\n";
		}
	}
	else
	{
		fout<<0<<"\n";
		for(i=1;i<=n;i++)
			fout<<0<<"\n";
	}
	
	fin.close();
	fout.close();
	return 0;
}
