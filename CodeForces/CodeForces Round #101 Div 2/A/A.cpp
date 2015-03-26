#include<iostream>
#include<cstring>
using namespace std;
char A[110],B[110],C[110];
int na,nb,nc,nr[30];

int main()
{
	int i;
	cin>>A; na=strlen(A);
	cin>>B; nb=strlen(B);
	cin>>C; nc=strlen(C);
	if(na+nb!=nc)
	{
		cout<<"NO\n";
		return 0;
	}
	for(i=0;i<nc;i++)
	{
		nr[C[i]-'A']++;
	}
	for(i=0;i<na;i++)
	{
		if(nr[A[i]-'A']==0)
		{
			cout<<"NO\n";
			return 0;
		}
		nr[A[i]-'A']--;
	}
	for(i=0;i<nb;i++)
	{
		if(nr[B[i]-'A']==0)
		{
			cout<<"NO\n";
			return 0;
		}
		nr[B[i]-'A']--;
	}
	cout<<"YES\n";
	return 0;
}
