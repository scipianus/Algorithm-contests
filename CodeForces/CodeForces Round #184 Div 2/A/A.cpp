#include<iostream>
#include<vector>
using namespace std;
int n,v[110],cod[110];
int best[110][8];
vector <int> ales[110][8];

int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>v[i];
		if(v[i]%10!=0)
			cod[i]+=1;
		if((v[i]/10)%10!=0)
			cod[i]+=2;
		if((v[i]/100)%10!=0)
			cod[i]+=4;
	}
	best[1][cod[1]]=1;
	ales[1][cod[1]].push_back(v[1]);
	for(i=2;i<=n;i++)
	{
		best[i][cod[i]]=1;
		ales[i][cod[i]].push_back(v[i]);
		for(j=0;j<8;j++)
		{
			if(best[i-1][j]!=0 && (j&cod[i])==0 && best[i][(j|cod[i])]<best[i-1][j]+1)
			{
				best[i][(j|cod[i])]=best[i-1][j]+1;
				ales[i][(j|cod[i])]=ales[i-1][j];
				ales[i][(j|cod[i])].push_back(v[i]);
			}
		}
		for(j=0;j<8;j++)
		{
			if(best[i][j]<best[i-1][j])
			{
				best[i][j]=best[i-1][j];
				ales[i][j]=ales[i-1][j];
			}
		}
	}
	j=0;
	for(i=1;i<8;i++)
		if(best[n][i]>best[n][j])
			j=i;
	cout<<best[n][j]<<"\n";
	for(i=0;i<best[n][j];i++)
		cout<<ales[n][j][i]<<' ';
	cout<<"\n";
	return 0;
}
