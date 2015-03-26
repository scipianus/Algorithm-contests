#include<iostream>
#include<fstream>
using namespace std;
int nr1,n,mat[20][20],nr1_now;
bool solutie;

inline void Verif()
{
	if(nr1_now!=nr1)
		return;
	solutie=true;
}

inline void Back(int x,int y)
{
	if(nr1_now>nr1)
		return;
	if(solutie==true)
		return;
	if(x>n-x+1)
		Verif();
	else
	{
		if(nr1_now<nr1 && !(x+1==n-x+1 || y+1==n-y+1) && mat[x-1][y]==0 && mat[x][y-1]==0 && mat[n-x][y]==0 && mat[n-x+1][y-1]==0 && mat[x-1][n-y+1]==0 && mat[x][n-y]==0 && mat[n-x][n-y+1]==0 && mat[n-x+1][n-y]==0)
		{
			if(mat[x][y]==0)
			{
				mat[x][y]=1;
				nr1_now++;
			}
			if(mat[n-x+1][y]==0)
			{
				mat[n-x+1][y]=1;
				nr1_now++;
			}
			if(mat[x][n-y+1]==0)
			{
				mat[x][n-y+1]=1;
				nr1_now++;
			}
			if(mat[n-x+1][n-y+1]==0)
			{
				mat[n-x+1][n-y+1]=1;
				nr1_now++;
			}
			if(y+1>n-y+1)
				Back(x+1,1);
			else
				Back(x,y+1);
			if(mat[x][y]==1)
			{
				mat[x][y]=0;
				nr1_now--;
			}
			if(mat[n-x+1][y]==1)
			{
				mat[n-x+1][y]=0;
				nr1_now--;
			}
			if(mat[x][n-y+1]==1)
			{
				mat[x][n-y+1]=0;
				nr1_now--;
			}
			if(mat[n-x+1][n-y+1]==1)
			{
				mat[n-x+1][n-y+1]=0;
				nr1_now--;
			}
		}
		mat[x][y]=mat[n-x+1][y]=mat[x][n-y+1]=mat[n-x+1][n-y+1]=0;
		if(y+1>n-y+1)
			Back(x+1,1);
		else
			Back(x,y+1);
	}
}

int main()
{
	ofstream fout("rez.out");
	for(nr1=1;nr1<=80;nr1++)
	{
		n=0;
		solutie=false;
		while(nr1>n*n)
			n++;
		while(1)
		{
			nr1_now=0;
			Back(1,1);
			if(solutie==true)
			{
				fout<<n<<",";
				break;
			}
			n++;
		}
	}
	fout.close();
	return 0;
}
