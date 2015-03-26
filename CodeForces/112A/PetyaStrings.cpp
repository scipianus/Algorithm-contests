#include<iostream>
#include<cstring>
using namespace std;
char A[110],B[110];
int n;

short Compara()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i]<97)
			A[i]+=32;
		if(B[i]<97)
			B[i]+=32;
		if(A[i]<B[i])
			return -1;
		else
			if(A[i]>B[i])
				return 1;
	}
	return 0;
}

int main()
{
	cin>>A;
	cin>>B;
	n=strlen(A);
	cout<<Compara()<<"\n";
	return 0;
}
