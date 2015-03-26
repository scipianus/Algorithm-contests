#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[12];
int ns;
bool viz[12];
string sol;

inline void Verif()
{
	int i,j;
	bool ok;
	string aux;
	aux.clear();
	for(i=1;i<=ns;i++)
	{
		if(viz[i]==true)
			aux+=s[i];
	}
	ok=true;
	for(i=0,j=aux.size()-1;ok && i<=j;i++,j--)
	{
		if(aux[i]!=aux[j])
			ok=false;
	}
	if(ok && lexicographical_compare(sol.begin(),sol.end(),aux.begin(),aux.end()))
		sol=aux;
}

inline void Back(int k)
{
	if(k==ns+1)
		Verif();
	else
	{
		viz[k]=true;
		Back(k+1);
		viz[k]=false;
		Back(k+1);
	}
}

int main()
{
	cin>>(s+1);
	ns=strlen(s+1);
	Back(1);
	cout<<sol<<"\n";
	return 0;
}
