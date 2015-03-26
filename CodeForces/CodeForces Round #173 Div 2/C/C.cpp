#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int na,nb;
char A[1000100],B[1000100];

int main()
{
	int i,nr1[2];
	cin>>(A+1);
	cin>>(B+1);
	na=strlen(A+1);
	nb=strlen(B+1);
	if(na!=nb)
		cout<<"NO\n";
	else
	{
		nr1[0]=nr1[1]=0;
		for(i=1;i<=na;i++)
		{
			if(A[i]=='1')
				nr1[0]++;
			if(B[i]=='1')
				nr1[1]++;
		}
		if(nr1[0]==0)
		{
			if(nr1[1]==0)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
		{
			if(nr1[1]!=0)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}
