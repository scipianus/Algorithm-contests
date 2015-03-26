#include<iostream>
using namespace std;
int n,m,v[100100],acuzat[100100],protejat[100100],nra,nrp,cri[100100];
string sol[100100];
int main()
{
	int i,j,criminal=0,nrcri=0;
	string aux;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>aux;
		for(j=1;j<aux.size();j++)
			v[i]=v[i]*10+aux[j]-'0';
		if(aux[0]=='-')
			v[i]=-v[i];
		if(v[i]<0)
		{
			nrp++;
			protejat[-v[i]]++;
		}
		else
		{
			nra++;
			acuzat[v[i]]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(acuzat[i]+nrp-protejat[i]==m)
		{
			if(nrcri==0)
			{
				criminal=i;
				nrcri=1;
			}
			else
			{
				nrcri++;
			}
			cri[i]=1;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(nrcri==1)
		{
			if(v[i]==criminal || (v[i]<0 && v[i]!=-criminal))
				sol[i]+="Truth";
			else
			{
				if(v[i]>0 || (v[i]<0 && v[i]==-criminal))
					sol[i]+="Lie";
			}
		}
		else
		{
			if(nrcri==0)
			{
				if(v[i]>0)
					sol[i]+="Lie";
				else
					sol[i]+="Not defined";
			}
			else
			{
				if((v[i]>0 && cri[v[i]]==1) || (v[i]<0 && cri[-v[i]]==1))
					sol[i]+="Not defined";
				else
				{
					if(v[i]>0 && cri[v[i]]==0)
						sol[i]+="Lie";
					else
					{
						if(v[i]<0 && cri[-v[i]]==0)
							sol[i]+="Truth";
					}
				}
			}
		}
		cout<<sol[i]<<"\n";
	}
	return 0;
}
