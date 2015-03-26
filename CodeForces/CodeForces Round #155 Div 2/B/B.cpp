#include<fstream>
#include<algorithm>
using namespace std;
int n,sol,now;
struct Olimp{int m,d,p,t,an;};
Olimp v[110];
int zile[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int liber[2][13][32];

inline bool Sortare(Olimp A,Olimp B)
{
	if(A.an==B.an)
	{
		if(A.m==B.m)
		{
			if(A.d==B.d)
				return A.t<B.t;
			return A.d<B.d;
		}
		return A.m<B.m;
	}
	return A.an<B.an;
}

int main()
{
	int i,j,k,x,a,b,p,an;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>v[i].m>>v[i].d>>v[i].p>>v[i].t;
		x=v[i].t;
		a=v[i].m;
		b=v[i].d;
		v[i].an=1;
		while(x)
		{
			if(b>1)
				b--;
			else
			{
				if(a>1)
					a--;
				else
				{
					a=12;
					v[i].an=0;
				}
				b=zile[a];
			}
			x--;
		}
		v[i].m=a;
		v[i].d=b;
	}
	sort(v+1,v+n+1,Sortare);
	
	k=1;
	for(an=0;an<2;an++)
	{
		for(i=1;i<=12;i++)
		{
			for(j=1;j<=zile[i];j++)
			{
				now+=liber[an][i][j];
				while(k<=n && v[k].an==an && v[k].m==i && v[k].d==j)
				{
					if(now>=v[k].p)
						now-=v[k].p;
					else
					{
						sol-=(now-v[k].p);
						now=0;
					}
					a=i;
					b=j;
					x=v[k].t;
					p=an;
					while(x)
					{
						if(b<zile[a])
							b++;
						else
						{
							if(a<12)
								a++;
							else
							{
								a=1;
								p=1;
							}
							b=1;
						}
						x--;
					}
					liber[p][a][b]+=v[k].p;
					k++;
				}
			}
		}
	}
	fout<<sol<<"\n";
	
	fin.close();
	fout.close();
	return 0;
}
