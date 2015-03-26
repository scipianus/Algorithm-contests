#include<iostream>
#include<algorithm>
using namespace std;
int n,K,sol;
struct Echipa{int p,t;};
Echipa Team[55];

inline bool Sortare(Echipa A,Echipa B)
{
	if(A.p==B.p)
		return A.t<B.t;
	return A.p>B.p;
}

int main()
{
	int i,p,t,st,dr;
	cin>>n>>K;
	for(i=1;i<=n;i++)
	{
		cin>>Team[i].p>>Team[i].t;
	}
	sort(Team+1,Team+n+1,Sortare);
	p=Team[K].p;
	t=Team[K].t;
	st=dr=K;
	while(st>1 && Team[st-1].p==p && Team[st-1].t==t)
		st--;
	while(dr<n && Team[dr+1].p==p && Team[dr+1].t==t)
		dr++;
	sol=dr-st+1;
	cout<<sol<<"\n";
	return 0;
}
