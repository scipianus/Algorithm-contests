/*
PROB : gangs
LANG : C++
*/
#include<fstream>
#include<algorithm>
#define pii pair<int,int>
using namespace std;
int n,m,v[110],sol;
pii afisare[110];

int main()
{
	int i,j,now,team;
	ifstream fin("gangs.in");
	fin>>n>>m;
	for(i=1;i<=m;i++)
		fin>>v[i];
	fin.close();
	
	ofstream fout("gangs.out");
	if(m==1)
	{
		fout<<"YES\n";
		fout<<n<<"\n";
		for(i=1;i<=n;i++)
			fout<<"1\n";
		fout.close();
		return 0;
	}
	now=v[2];
	for(i=3;i<=m;i++)
	{
		if(now>=v[i])
			now-=v[i];
		else
			now=v[i]-now;
	}
	if(now>=v[1])
	{
		fout<<"NO\n";
		fout.close();
		return 0;
	}
	sol=v[1]-now;
	fout<<"YES\n";
	fout<<sol<<"\n";
	now=v[2];
	team=2;
	j=0;
	for(i=3;i<=m;i++)
	{
		while(now && v[i])
		{
			afisare[++j]=make_pair(team,i);
			now--;
			v[i]--;
		}
		if(now==0)
		{
			if(v[i]!=0)
			{
				now=v[i];
				team=i;
			}
			else
			{
				now=v[i+1];
				team=i+1;
				i++;
			}
		}
	}
	while(now)
	{
		afisare[++j]=make_pair(1,team);
		now--;
		v[1]--;
	}
	sort(afisare+1,afisare+j+1);
	for(i=1;i<=j;i++)
		fout<<afisare[i].first<<"\n"<<afisare[i].second<<"\n";
	while(v[1])
	{
		fout<<"1\n";
		v[1]--;
	}
	fout.close();
	return 0;
}
