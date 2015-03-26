#include<iostream>
#include<map>
#include<cstring>
using namespace std;
char s[150];
int n,sol;
map <char,short> M;

int main()
{
	M['>']=8;
	M['<']=9;
	M['+']=10;
	M['-']=11;
	M['.']=12;
	M[',']=13;
	M['[']=14;
	M[']']=15;
	
	int i;
	cin>>s;
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		sol+=M[s[i]];
		if(i!=n-1)
			sol*=16;
		sol%=1000003;
	}
	cout<<sol<<"\n";
	return 0;
}
