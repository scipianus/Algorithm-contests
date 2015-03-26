#include<iostream>
using namespace std;
int a,b,c,A[100],B[100],C[100];

int main()
{
	int i,put=1,poz=1,aux,maxpoz=0;
	cin>>a>>c;
	//transform pe a
	while(put<a)
	{
		put=put*3;
		poz++;
	}
	if(put>a)
	{
		put=put/3;
		poz--;
	}
	maxpoz=poz;
	aux=a;
	while(aux)
	{
		while(aux>=put)
		{
			aux-=put;
			A[poz]++;
		}
		poz--;
		put=put/3;
	}
	//transform pe c
	put=1;
	poz=1;
	while(put<c)
	{
		put=put*3;
		poz++;
	}
	if(put>c)
	{
		put=put/3;
		poz--;
	}
	maxpoz=max(maxpoz,poz);
	aux=c;
	while(aux)
	{
		while(aux>=put)
		{
			aux-=put;
			C[poz]++;
		}
		poz--;
		put=put/3;
	}
	put=1;
	for(i=1;i<=maxpoz;i++)
	{
		B[i]=C[i]-A[i];
		while(B[i]<0)
			B[i]+=3;
		b=b+B[i]*put;
		put*=3;
	}
	cout<<b<<"\n";
	return 0;
}
