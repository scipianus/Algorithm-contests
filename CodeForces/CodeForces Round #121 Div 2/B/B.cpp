#include<iostream>
#include<cmath>
using namespace std;
int n;
int v[1010];
bool pos[1010];

int main()
{
	int i,t;
	bool ok=false;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>v[i];
	for(t=min(v[n],v[1]);t>=0 && !ok;t--)
	{
		pos[1]=true;
		for(i=1;i<=n;i++)
		{
			if(pos[i]==true)
			{
				if(v[i+1]>=t)
					pos[i+1]=true;
				if(v[i+2]>=t)
					pos[i+2]=true;
			}
		}
		if(pos[n]==true)
		{
			ok=true;
			cout<<t<<"\n";
			continue;
		}
		for(i=1;i<=n;i++)
			pos[i]=false;
	}
	return 0;
}
