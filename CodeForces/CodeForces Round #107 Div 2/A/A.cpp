#include<iostream>
#include<cstring>
using namespace std;
int n,k,l,c,d,p,nl,np;
int main()
{
	int drink,lime,salt,sol;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	drink=k*l;
	lime=c*d;
	salt=p;
	sol=min(drink/nl,min(lime,salt/np));
	sol=sol/n;
	cout<<sol<<"\n";
	return 0;
}
