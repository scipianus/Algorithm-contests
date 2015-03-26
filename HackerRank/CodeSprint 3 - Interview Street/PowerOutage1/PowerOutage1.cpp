#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int T,n,m,K;
struct Muchie{int x,y; long long cost;};
Muchie M[4000100];
int H[4000100];
long long sol;
int c[2010],h[2010];

struct Sortare{
	bool operator () (int A,int B)
	{
		return M[A].cost<M[B].cost;
	}
};

inline int Find(int x)
{
	int r=x;
	while(c[r])
		r=c[r];
	int y=x,aux;
	while(y!=r)
	{
		aux=c[y];
		c[y]=r;
		y=aux;
	}
	return r;
}

inline void Union(int x,int y)
{
	if(h[x]>h[y])
		c[y]=x;
	else
	{
		c[x]=y;
		if(h[x]==h[y])
			h[y]++;
	}
}

int main()
{
	int i,nrc,A,B;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&K);
		for(i=1;i<=m;i++)
		{
			scanf("%d %d %lld",&M[i].x,&M[i].y,&M[i].cost);
			H[i]=i;
		}
		if(K>=n)
		{
			printf("0\n");
			continue;
		}
		sort(H+1,H+m+1,Sortare());
		nrc=n;
		sol=0LL;
		i=1;
		while(nrc>K && i<=m)
		{
			A=Find(M[H[i]].x);
			B=Find(M[H[i]].y);
			
			if(A!=B)
			{
				sol+=M[H[i]].cost;
				Union(A,B);
				nrc--;
			}
			i++;
		}
		if(nrc==K)
			printf("%lld\n",sol);
		else
			printf("Impossible!\n");
		for(i=1;i<=n;i++)
			c[i]=h[i]=0;
	}
	return 0;
}
