#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
long long grad[1000100];
long long sum,N;

int main()
{
	int i,x,y;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		grad[x]++;
		grad[y]++;
	}
	//pentru fiecare pereche de muchii din primul graf adaugam 2/6 la suma
	//pentru fiecare pereche de muchii din al doilea graf adaugam 2/6 la suma
	//pentru fiecare pereche o muchie din primul graf si o muchie din al doilea adaugam -1/6 la suma
	//se observa ca astfel ca un triunghi format din 3 muchii din primul graf
	//sau 3 muchii din al doilea graf va adauga 1 la suma
	//iar un triunghi cu 2 muchii dintr-un graf si 1 din celalalt va adauga 0 la suma
	N=(long long)n;
	for(i=1;i<=n;i++)
	{
		//muchiile din primul graf sunt Comb(grad[i],2)
		sum+=2LL*(grad[i]*(grad[i]-1LL)/2LL);
		//muchiile din al doilea graf sunt Comb(n-1-grad[i],2)
		sum+=2LL*((N-grad[i]-1LL)*(N-grad[i]-2LL)/2LL);
		//muchiile din al doilea graf sunt grad[i]*(n-1-grad[i])
		sum-=1LL*(grad[i]*(N-grad[i]-1LL));
	}
	sum/=6LL;
	cout<<sum<<"\n";
	return 0;
}
