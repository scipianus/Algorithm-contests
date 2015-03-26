#include<iostream>
#include<cstring>
using namespace std;
int n,ns[500100];
string s[500100];
int sol,best[500100][30],maxim[30][30];

int main()
{
	int i,c1,c2;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
		ns[i]=s[i].size();
		if(s[i][0]==s[i][ns[i]-1])
			sol=max(sol,ns[i]);
	}
	best[1][s[1][0]-'a']=ns[1];
	maxim[s[1][0]-'a'][s[1][ns[1]-1]-'a']=1;
	for(i=2;i<=n;i++)
	{
		c1=s[i][0]-'a';
		c2=s[i][ns[i]-1]-'a';
		for(c2=0;c2<26;c2++)
		{
			if(maxim[c2][c1]==0)
				continue;
			best[i][c2]=best[maxim[c2][c1]][c2]+ns[i];
			if(best[i][c2]>best[maxim[c2][s[i][ns[i]-1]-'a']][c2])
				maxim[c2][s[i][ns[i]-1]-'a']=i;
		}
		c2=s[i][ns[i]-1]-'a';
		if(best[i][c1]==0)
		{
			best[i][c1]=ns[i];
			if(best[i][c1]>best[maxim[c1][c2]][c1])
				maxim[c1][c2]=i;
		}
		if(best[i][c2]>best[maxim[c2][c2]][c2])
			maxim[c2][c2]=i;
		sol=max(sol,best[i][c2]);
	}
	cout<<sol<<"\n";
	return 0;
}
