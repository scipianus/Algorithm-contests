#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
string t[4];
map <string,int> nrt;
int gm[4],gp[4],nrp[4],nrm[4];
bool ok[4];
int ec[4],sol1=2000000000,sol2;

inline bool Sortare(int A,int B)
{
	if(nrp[A]==nrp[B])
	{
		if((gm[A]-gp[A])==(gm[B]-gp[B]))
		{
			if(gm[A]==gm[B])
			{
				if(t[A].compare(t[B])<=0)
					return true;
				return false;
			}
			return gm[A]>gm[B];
		}
		return (gm[A]-gp[A])>(gm[B]-gp[B]);
	}
	return nrp[A]>nrp[B];
}

int main()
{
	int i,j,g1,g2,ind;
	bool gasit;
	string s[2],aux;
	t[0]="BERLAND";
	ok[0]=true;
	for(i=1;i<=5;i++)
	{
		cin>>s[0]>>s[1]>>aux;
		g1=0;
		j=0;
		while(aux[j]!=':')
			g1=g1*10+aux[j++]-'0';
		j++;
		g2=0;
		while(j<aux.size() && '0'<=aux[j] && aux[j]<='9')
			g2=g2*10+aux[j++]-'0';
		gasit=false;
		if(s[0].compare(t[0])==0 && s[0].size()==t[0].size())
		{
			gm[0]+=g1;
			gp[0]+=g2;
			if(g1>g2)
				nrp[0]+=3;
			if(g1==g2)
				nrp[0]++;
			gasit=true;
		}
		if(!gasit)
		{
			if(nrt[s[0]]==0)
			{
				j=1;
				while(ok[j]==true)
					j++;
				nrt[s[0]]=j;
				ok[j]=true;
				t[j]=s[0];
			}
			ind=nrt[s[0]];
			gm[ind]+=g1;
			gp[ind]+=g2;
			nrm[ind]++;
			if(g1>g2)
				nrp[ind]+=3;
			if(g1==g2)
				nrp[ind]++;
			gasit=true;
		}
		gasit=false;
		if(s[1].compare(t[0])==0 && s[1].size()==t[0].size())
		{
			gm[0]+=g2;
			gp[0]+=g1;
			if(g1<g2)
				nrp[0]+=3;
			if(g1==g2)
				nrp[0]++;
			gasit=true;
		}
		if(!gasit)
		{
			if(nrt[s[1]]==0)
			{
				j=1;
				while(ok[j]==true)
					j++;
				nrt[s[1]]=j;
				ok[j]=true;
				t[j]=s[1];
			}
			ind=nrt[s[1]];
			gm[ind]+=g2;
			gp[ind]+=g1;
			nrm[ind]++;
			if(g1<g2)
				nrp[ind]+=3;
			if(g1==g2)
				nrp[ind]++;
			gasit=true;
		}
		s[0].clear();
		s[1].clear();
		aux.clear();
	}
	for(i=1;i<4;i++)
	{
		if(nrm[i]==2)
			ind=i;
	}
	nrp[0]+=3;
	for(i=0;i<4;i++)
		ec[i]=i;
	for(g1=0;g1<100;g1++)
	{
		for(g2=0;g2<g1;g2++)
		{
			gm[0]+=g1;
			gp[0]+=g2;
			gm[ind]+=g2;
			gp[ind]+=g1;
			sort(ec,ec+4,Sortare);
			if(ec[0]==0 || ec[1]==0)
			{
				if((g1-g2)<(sol1-sol2))
				{
					sol1=g1;
					sol2=g2;
				}
				else
				{
					if((g1-g2)==(sol1-sol2))
					{
						if(g2<sol2)
						{
							sol1=g1;
							sol2=g2;
						}
					}
				}
			}
			gm[0]-=g1;
			gp[0]-=g2;
			gm[ind]-=g2;
			gp[ind]-=g1;
		}
	}
	if(sol1==2000000000)
		cout<<"IMPOSSIBLE\n";
	else
		cout<<sol1<<":"<<sol2<<"\n";
	return 0;
}
