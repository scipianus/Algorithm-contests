#include<iostream>
#include<cstring>
using namespace std;
char A[15],B[15],s[15];
int n,sol1,sol2;

int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		if(sol1==0)
		{
			strcpy(A,s);
			sol1++;
		}
		else
		{
			if(strlen(A)==strlen(s) && strcmp(A,s)==0)
				sol1++;
			else
			{
				if(sol2==0)
				{
					strcpy(B,s);
					sol2++;
				}
				else
					sol2++;
			}
		}
	}
	if(sol1>sol2)
		cout<<A<<"\n";
	else
		cout<<B<<"\n";
	return 0;
}
