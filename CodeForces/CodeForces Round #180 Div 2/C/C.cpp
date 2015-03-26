#include<iostream>
#include<cstring>
#include<deque>
#include<map>
#define MOD 1000000007
using namespace std;
int na,nb;
char A[1010],B[1010];
deque <int> D;
map <pair<int,pair<int,int> >,bool> viz;

int main()
{
	int i,nr=0,val;
	bool ok;
	deque <int>::iterator it;
	cin>>(A+1);
	cin>>(B+1);
	na=strlen(A+1);
	nb=strlen(B+1);
	for(i=1;i<=nb;i++)
	{
		D.push_back(B[i]-'0');
		if(B[i]=='1' && i<nb)
			nr++;
	}
	if(nb<=na)
	{
		ok=true;
		i=na;
		for(it=D.end()-1;it>=D.begin() && ok;it--)
		{
			if(A[i]-'0'!=*it)
				ok=false;
			i--;
		}
		if(ok)
		{
			cout<<"YES\n";
			return 0;
		}
	}
	val=0;
	for(it=D.begin();it!=D.end();it++)
	{
		val=2*val+*it;
		while(val>=MOD)
			val-=MOD;
	}
	viz[make_pair(val,make_pair(nr,nb))]=true;
	while(nb>0)
	{
		if(nr%2==0)
		{
			if(D.back()==0)
			{
				D.pop_back();
				nb--;
				if(!D.empty() && D.back()==1)
					nr--;
			}
			else
			{
				D.push_front(1);
				nr++;
				nb++;
			}
		}
		else
		{
			if(D.back()==1)
			{
				D.pop_back();
				if(!D.empty() && D.back()==1)
					nr--;
				nb--;
			}
			else
			{
				D.push_front(1);
				nr++;
				nb++;
			}
		}
		if(nb<=na)
		{
			ok=true;
			i=na;
			for(it=D.end()-1;it>=D.begin() && ok;it--)
			{
				if(A[i]-'0'!=*it)
					ok=false;
				i--;
			}
			if(ok)
			{
				cout<<"YES\n";
				return 0;
			}
		}
		val=0;
		for(it=D.begin();it!=D.end();it++)
		{
			val=2*val+*it;
			while(val>=MOD)
				val-=MOD;
		}
		if(viz[make_pair(val,make_pair(nr,nb))]==true)
		{
			cout<<"NO\n";
			return 0;
		}
		viz[make_pair(val,make_pair(nr,nb))]=true;
	}
	cout<<"YES\n";
	return 0;
}
