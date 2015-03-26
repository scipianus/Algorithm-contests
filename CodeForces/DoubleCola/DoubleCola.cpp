#include<iostream>
using namespace std;
char v[5][10]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int n;

int Persoana()
{
	int poz=0,put=1;
	while(n>put)
	{
		n-=put;
		poz++;
		if(poz==5)
		{
			poz=0;
			put=put*2;
		}
	}
	return poz;
}

int main()
{
	cin>>n;
	cout<<v[Persoana()]<<"\n";
	return 0;
}
