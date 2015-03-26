#include<iostream>
#include<cstring>
using namespace std;
int ns;
char A[100100];

int main()
{
	int i;
	bool gasit=false;
	cin>>(A+1);
	ns=strlen(A+1);
	for(i=1;i<ns;i++)
	{
		if(!gasit && A[i]=='0')
			gasit=true;
		else
			cout<<A[i];
	}
	if(gasit)
		cout<<A[ns]<<"\n";
	return 0;
}
