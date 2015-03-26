#include<iostream>
#include<cstring>
using namespace std;
char A[100100],B[100100];
int na,nb,nr1[31],ask,nr2[31],sol;

int main()
{
	int i,st,dr;
	bool ok;
	cin>>(A+1); na=strlen(A+1);
	cin>>(B+1); nb=strlen(B+1);
	if(na<nb)
		cout<<0<<"\n";
	else
	{
		for(i=1;i<=nb;i++)
		{
			nr2[B[i]-'a']++;
		}
		st=1;
		for(dr=1;dr<nb;dr++)
		{
			if(A[dr]=='?')
				ask++;
			else
				nr1[A[dr]-'a']++;
		}
		while(dr<=na)
		{
			if(A[dr]=='?')
				ask++;
			else
				nr1[A[dr]-'a']++;
			ok=true;
			for(i=0;i<30 && ok;i++)
			{
				if(nr1[i]>nr2[i])
					ok=false;
			}
			if(ok)
				sol++;
			if(A[st]=='?')
				ask--;
			else
				nr1[A[st]-'a']--;
			st++;
			dr++;
		}
		cout<<sol<<"\n";
	}
	
	return 0;
}
