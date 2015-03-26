#include<iostream>
#include<algorithm>
using namespace std;
int n,v[100010],LIS[100010],lgmax;
 
void Citire()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
}
 
void Determinare_LIS()
{
    int i,pozitie;
    LIS[1]=v[1];
    lgmax=1;
    for(i=2;i<=n;i++)
    {
        pozitie=upper_bound(LIS+1,LIS+lgmax+1,v[i])-LIS;
        if(LIS[pozitie-1]==v[i])
            pozitie--;
        LIS[pozitie]=v[i];
        if(pozitie>lgmax)
            lgmax=pozitie;
    }
	cout<<lgmax<<"\n";
}
 
int main()
{
    Citire();
    Determinare_LIS();
    return 0;
}
