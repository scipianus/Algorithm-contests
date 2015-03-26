#include<iostream>
#define INF 4000000000000000000LL
using namespace std;
int n,sol;
long long best[5010][5010],h[5010];
//best[i][j]=inaltimea minima a ultimului turn,grupand primele i turnuri in cel putin j turnuri

int main()
{
	int i,j,k;
	long long sum;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>h[i];
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			best[i][j]=INF;
	best[0][0]=0;
	for(i=1;i<=n;i++)
	{
		k=0;
		sum=0;
		for(j=i;j<=n;j++)
		{
			sum+=h[j];
			while(k<=n && best[i-1][k]<=sum)
				k++;
			k--;
			if(k>=0)
				best[j][k+1]=min(best[j][k+1],sum);
		}
		for(j=n-1;j>=0;j--)
			best[i][j]=min(best[i][j],best[i][j+1]);
	}
	for(j=n;j>=0;j--)
	{
		if(best[n][j]!=INF)
		{
			sol=n-j;
			break;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
