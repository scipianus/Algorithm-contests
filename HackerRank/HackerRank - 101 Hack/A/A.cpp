#include<iostream>
#include<cstring>
using namespace std;
int n,LCS[5010][5010];
char A[5010],B[5010];

int main()
{
	cin>>(A+1);
	cin>>(B+1);
	n=strlen(A+1);
	int i,j,gasit;
    gasit=0;
    for(i=n;i>0;i--)
    {
        if(gasit==1)
            LCS[i][n]=1;
        else
        {
            if(A[i]==B[n])
            {
                gasit=1;
                LCS[i][n]=1;
            }
            else
                LCS[i][n]=0;
        }
    }
    gasit=0;
    for(j=n;j>0;j--)
    {
        if(gasit==1)
            LCS[n][j]=1;
        else
        {
            if(A[n]==B[j])
            {
                gasit=1;
                LCS[n][j]=1;
            }
            else
                LCS[n][j]=0;
        }
    }
    for(i=n-1;i>0;i--)
    {
        for(j=n-1;j>0;j--)
        {
            if(A[i]!=B[j])
                LCS[i][j]=max(LCS[i+1][j],LCS[i][j+1]);
            else
                LCS[i][j]=max(1+LCS[i+1][j+1],max(LCS[i+1][j],LCS[i][j+1]));
        }
    }
	cout<<LCS[1][1]<<"\n";
	return 0;
}
