#include<iostream>
using namespace std;
char mat[5][5];

int main()
{
	int i,j,nr1,nr2;
	for(i=1;i<=4;i++)
		cin>>(mat[i]+1);
	for(i=2;i<=4;i++)
	{
		for(j=2;j<=4;j++)
		{
			nr1=nr2=0;
			if(mat[i][j]=='.')
				nr1++;
			else
				nr2++;
			if(mat[i-1][j]=='.')
				nr1++;
			else
				nr2++;
			if(mat[i][j-1]=='.')
				nr1++;
			else
				nr2++;
			if(mat[i-1][j-1]=='.')
				nr1++;
			else
				nr2++;
			if(nr1>=3 || nr2>=3)
			{
				cout<<"YES\n";
				return 0;
			}
		}
	}
	cout<<"NO\n";
	return 0;
}
