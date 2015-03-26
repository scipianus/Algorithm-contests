#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int T,nmax,A[1000100];
long long first,last,sol[1010];
struct Query{int n,K,ind;};
Query Q[1010];

inline bool Sortare(Query a,Query b)
{
	return a.n<b.n;
}

inline void Inmultire()
{
	int i,t=0;
	for(i=1;i<=A[0] || t;i++,t/=10)
		A[i]=(t+=A[i]*2)%10;
	A[0]=i-1;
}

int main()
{
	int i,j,t;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>Q[t].n>>Q[t].K;
		Q[t].ind=t;
		nmax=max(nmax,Q[t].n-1);
	}
	sort(Q+1,Q+T+1,Sortare);
	A[0]=A[1]=1;
	t=1;
	while(t<=T && Q[t].n==1)
	{
		sol[Q[t].ind]=2LL;
		t++;
	}
	for(j=1;j<=nmax;j++)
	{
		Inmultire();
		while(t<=T && Q[t].n==j+1)
		{
			first=last=0LL;
			for(i=Q[t].K;i>0;i--)
				first=first*10LL+1LL*A[i];
			for(i=A[0];i>A[0]-Q[t].K;i--)
				last=last*10LL+1LL*A[i];
			sol[Q[t].ind]=first+last;
			t++;
		}
	}
	for(t=1;t<=T;t++)
		cout<<sol[t]<<"\n";
	return 0;
}
