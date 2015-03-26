#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,P,K;
struct Element{int a,b,ind,inds;};
Element v[100100];
bool ales[100100];

inline bool Sortare(Element A,Element B)
{
	if(A.b==B.b)
		return A.a<B.a;
	return A.b>B.b;
}

inline bool Sortare2(Element A,Element B)
{
	if(A.a==B.a)
		return A.inds<B.inds;
	return A.a>B.a;
}

int main()
{
	int i,dif,maxim=0;
	cin>>n>>P>>K;
	for(i=1;i<=n;i++)
	{
		cin>>v[i].a>>v[i].b;
		v[i].ind=i;
	}
	
	sort(v+1,v+n+1,Sortare);
	for(i=1;i<=n;i++)
		v[i].inds=i;
	dif=P-K;
	sort(v+1,v+n-dif+1,Sortare2);
	for(i=1;i<=K;i++)
	{
		ales[v[i].ind]=true;
		maxim=max(maxim,v[i].inds);
	}
	sort(v+1,v+n+1,Sortare);
	for(i=maxim+1;i<maxim+1+dif;i++)
		ales[v[i].ind]=true;
	
	for(i=1;i<=n;i++)
		if(ales[i])
			cout<<i<<' ';
	cout<<"\n";
	return 0;
}
