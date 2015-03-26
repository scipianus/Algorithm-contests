#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int n,T,R;
vector <int> G[100100];
int aib[200100];
bool notrad[100100];
long long sol;

inline void Aduna(int poz,int val)
{
	while(poz<=2*n)
	{
		aib[poz]+=val;
		poz+=(poz & -poz);
	}
}

inline int Suma(int poz)
{
	int sum=0;
	while(poz>0)
	{
		sum+=aib[poz];
		poz-=(poz & -poz);
	}
	return sum;
}

inline void DFS(int x)
{
	vector <int>::iterator it;
	sol+=1LL*(Suma(x+T)-Suma(x-T-1));
	Aduna(x,1);
	for(it=G[x].begin();it!=G[x].end();it++)
		DFS(*it);
	Aduna(x,-1);
}

int main()
{
	int i,x,y;
	cin>>n>>T;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		G[x].push_back(y);
		notrad[y]=true;
	}
	for(i=1;i<=n;i++)
		if(!notrad[i])
			R=i;
	DFS(R);
	cout<<sol<<"\n";
	return 0;
}
