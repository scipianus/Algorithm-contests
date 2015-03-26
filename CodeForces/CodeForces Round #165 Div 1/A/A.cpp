#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,K,sol,nr,total;
struct Cutie{int k,nr;};
Cutie v[100100];

inline bool Sortare(Cutie A,Cutie B)
{
	return A.k<B.k;
}

int main()
{
	int i,now;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>v[i].k>>v[i].nr;
	sort(v+1,v+n+1,Sortare);
	K=v[n].k;
	for(i=1;i<=n;i++)
	{
		now=v[i].k;
		nr=v[i].nr;
		while(now<K && nr>1)
		{
			if(nr%4==0)
				nr/=4;
			else
				nr=nr/4+1;
			now++;
		}
		total=max(total,nr);
	}
	nr=total;
	sol=K;
	if(nr==1)
		sol++;
	while(nr>1)
	{
		if(nr%4==0)
			nr/=4;
		else
			nr=nr/4+1;
		sol++;
	}
	cout<<sol<<"\n";
	return 0;
}
