#include<iostream>
#include<map>
using namespace std;
int n,v[100100],sol,maxim,nrd;
map <int,int> nr;

int main()
{
	int i,x,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>v[i];
		nr[v[i]]++;
		maxim=max(maxim,v[i]);
		if(nr[v[i]]==1)
			nrd++;
	}
	for(i=1;i<=n;i++)
	{
		x=nr[v[i]];
		j=1;
		while(x>=2)
		{
			if(nr[v[i]+j]==0)
			{
				nrd++;
				maxim=max(maxim,v[i]+j);
			}
			nr[v[i]+j]+=x/2;
			nr[v[i]+j-1]%=2;
			if(nr[v[i]+j-1]==0)
				nrd--;
			x=nr[v[i]+j];
			j++;
		}
	}
	sol=maxim+1-nrd;
	
	cout<<sol<<"\n";
	return 0;
}
