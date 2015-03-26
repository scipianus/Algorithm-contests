#include<iostream>
using namespace std;
int mat[5][5];

int main()
{
	int i,j,x,sum,s;
	bool ok;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			cin>>mat[i][j];
	for(x=100000;x>=0;x--)
	{
		ok=true;
		mat[1][1]=x;
		sum=x+mat[1][2]+mat[1][3];
		mat[2][2]=sum-mat[2][1]-mat[2][3];
		mat[3][3]=sum-mat[3][1]-mat[3][2];
		for(i=1;i<=3;i++)
		{
			s=mat[i][1]+mat[i][2]+mat[i][3];
			if(s!=sum)
				ok=false;
			s=mat[1][i]+mat[2][i]+mat[3][i];
			if(s!=sum)
				ok=false;
		}
		s=mat[1][3]+mat[2][2]+mat[3][1];
		if(s!=sum)
			ok=false;
		s=mat[1][1]+mat[2][2]+mat[3][3];
		if(s!=sum)
			ok=false;
		if(ok)
		{
			for(i=1;i<=3;i++)
			{
				for(j=1;j<=3;j++)
					cout<<mat[i][j]<<' ';
				cout<<"\n";
			}
			return 0;
		}
	}
	return 0;
}
