#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char N[100100],A[100100],B[100100];
int n,nr1[10],nr2[10];
int main()
{
	int i,j,k,x;
	bool gasit=false;
	cin>>(N+1);
	n=strlen(N+1);
	for(i=1;i<=n;i++)
	{
		nr1[N[i]-'0']++;
		nr2[N[i]-'0']++;
	}
	j=0;
	for(i=n;i>0;i--)
	{
		gasit=false;
		if(nr1[0]>=nr2[0])
		{
			for(k=0;k<10 && !gasit;k++)
			{
				if(nr1[k])
				{
					x=k+j;
					if(x==0 && nr2[0])
					{
						gasit=true;
						A[i]='0';
						B[i]='0';
						nr1[0]--;
						nr2[0]--;
						j=0;
					}
					else
					{
						if(x<=10 && nr2[10-x])
						{
							gasit=true;
							A[i]=k+'0';
							B[i]=10-x+'0';
							nr1[k]--;
							nr2[10-x]--;
							j=1;
						}
						else
							if(x>10 && nr2[20-x])
							{
								gasit=true;
								A[i]=k+'0';
								B[i]=20-x+'0';
								nr1[k]--;
								nr2[20-x]--;
								j=2;
							}
					}
				}
			}
		}
		else
		{
			for(k=0;k<10 && !gasit;k++)
			{
				if(nr2[k])
				{
					x=k+j;
					if(x==0 && nr1[0])
					{
						gasit=true;
						B[i]='0';
						A[i]='0';
						nr2[0]--;
						nr1[0]--;
						j=0;
					}
					else
					{
						if(x<=10 && nr1[10-x])
						{
							gasit=true;
							B[i]=k+'0';
							A[i]=10-x+'0';
							nr2[k]--;
							nr1[10-x]--;
							j=1;
						}
						else
							if(x>10 && nr1[20-x])
							{
								gasit=true;
								B[i]=k+'0';
								A[i]=20-x+'0';
								nr2[k]--;
								nr1[20-x]--;
								j=2;
							}
					}
				}
			}
		}
		if(!gasit)
			break;
	}
	while(i>0)
	{
		gasit=false;
		for(k=0;k<10 && !gasit;k++)
		{
			if(nr1[k])
			{
				A[i]=k+'0';
				nr1[k]--;
				gasit=true;
			}
		}
		gasit=false;
		for(k=0;k<10 && !gasit;k++)
		{
			if(nr2[k])
			{
				B[i]=k+'0';
				nr2[k]--;
				gasit=true;
			}
		}
		i--;
	}
	cout<<(A+1)<<"\n";
	cout<<(B+1)<<"\n";
	return 0;
}
