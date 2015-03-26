#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n,r[100100],nrsol;
bool viz[100100];
struct Sol{int x,y,z;};
Sol sol[40000];
multiset <int> H1,H2;

int main()
{
	int i,j,k;
	multiset <int>::iterator it,jt;
	Sol aux;
	cin>>n;
	if(n>=3)
	{
		for(i=1;i<=n;i++)
		{
			cin>>r[i];
		}
		sort(r+1,r+n+1);
		H1.insert(r[1]);
		for(i=3;i<=n;i++)
			H2.insert(-r[i]);
		for(i=2;i<n;i++)
		{
			if(!H1.size())
			{
				H1.insert(r[i]);
				jt=lower_bound(H2.begin(),H2.end(),-r[i+1]);
				H2.erase(*jt);
				continue;
			}
			it=H1.begin();
			if(r[i]==*it)
			{
				H1.insert(r[i]);
				if(!H2.size())
				{
					i=n;
					continue;
				}
				jt=lower_bound(H2.begin(),H2.end(),-r[i+1]);
				H2.erase(*jt);
				continue;
			}
			if(!H2.size())
			{
				i=n;
				continue;
			}
			jt=H2.begin();
			if(r[i]==-*jt)
			{
				i=n;
				continue;
			}
			aux.x=*it;
			aux.y=r[i];
			aux.z=-*jt;
			sol[++nrsol]=aux;
			H1.erase(*it);
			H2.erase(*jt);
			jt=lower_bound(H2.begin(),H2.end(),-r[i+1]);
			H2.erase(*jt);
			
		}
	}
	cout<<nrsol<<"\n";
	for(i=1;i<=nrsol;i++)
		cout<<sol[i].x<<' '<<sol[i].y<<' '<<sol[i].z<<"\n";
	return 0;
}
