#include<iostream>
#include<cstring>
using namespace std;
char s[150];
int n,sol[150];

int Next(int x)
{
	int put=128,rez=0;
	while(x)
	{
		if(x>=put)
		{
			x-=put;
			rez+=(128/put);
		}
		put/=2;
	}
	return rez;
}

int main()
{
	int i,pred=0,c,next,rez;
	cin.getline(s,150);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		c=(int)s[i];
		next=Next(c);
		rez=pred-next;
		if(rez<0)
			rez+=256;
		sol[i]=rez;
		pred=next;
	}
	for(i=0;i<n;i++)
		cout<<sol[i]<<"\n";
	return 0;
}
