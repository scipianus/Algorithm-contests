#include<iostream>
#include<algorithm>
using namespace std;
int n,v[100100];
int bit[100100],aib[100100];
long long sol;
 
void Citire()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
}
 
void Aduna(int poz,int x)
{
    while(poz<=n)
    {
        aib[poz]+=x;
        poz+=(poz & -poz);
    }
}
 
int Suma(int poz)
{
    int sum=0;
    while(poz>0)
    {
        sum+=aib[poz];
		poz-=(poz & -poz);
    }
    return sum;
}
 
void Rezolvare()
{
    int i;
    Aduna(v[1],1);
    for(i=2;i<=n;i++)
    {
        sol=sol+1LL*(i-1-Suma(v[i]));
        Aduna(v[i],1);
    }
}
 
void Afisare()
{
    if(sol)
		cout<<(2*sol-1)<<"\n";
	else
		cout<<"0\n";
}
 
int main()
{
    Citire();
    Rezolvare();
    Afisare();
    return 0;
}
