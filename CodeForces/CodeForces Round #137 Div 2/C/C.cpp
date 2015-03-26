#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
struct El{int f,exp;};
El v[2][105100];
int nrf[2];
int prim[3500],nrp;
bool ciur[3500];
vector <El> solA,solB;
vector <int> sol1,sol2;

inline bool Sortare(El A,El B)
{
	return A.f<B.f;
}

int main()
{
	El aux;
	int i,j,x,nr,F,E;
	prim[++nrp]=2;
	v[0][++nrf[0]].f=2;
	v[1][++nrf[1]].f=2;
	for(i=3;i<=3200;i+=2)
	{
		if(!ciur[i])
		{
			v[0][++nrf[0]].f=i;
			v[1][++nrf[1]].f=i;
			prim[++nrp]=i;
			for(j=i*i;j<=3200;j+=2*i)
				ciur[j]=true;
		}
	}
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		j=1;
		while(x>1 && j<=nrp)
		{
			if(x%prim[j]==0)
			{
				while(x%prim[j]==0)
				{
					v[0][j].exp++;
					x/=prim[j];
				}
			}
			j++;
		}
		if(x>1)
		{
			v[0][++nrf[0]].f=x;
			v[0][nrf[0]].exp=1;
		}
	}
	for(i=1;i<=m;i++)
	{
		cin>>x;
		j=1;
		while(x>1 && j<=nrp)
		{
			if(x%prim[j]==0)
			{
				while(x%prim[j]==0)
				{
					v[1][j].exp++;
					x/=prim[j];
				}
			}
			j++;
		}
		if(x>1)
		{
			v[1][++nrf[1]].f=x;
			v[1][nrf[1]].exp=1;
		}
	}
	
	sort(v[0]+1,v[0]+nrf[0]+1,Sortare);
	sort(v[1]+1,v[1]+nrf[1]+1,Sortare);
	for(i=2;i<=nrf[0];i++)
	{
		if(v[0][i].f==v[0][i-1].f)
		{
			nr=v[0][i].exp;
			x=v[0][i-1].f;
			j=i-1;
			while(i+1<=nrf[0] && v[0][i+1].f==x)
			{
				i++;
				nr+=v[0][i].exp;
				v[0][i].exp=0;
			}
			v[0][j].exp+=nr;
		}
	}
	for(i=2;i<=nrf[1];i++)
	{
		if(v[1][i].f==v[1][i-1].f)
		{
			nr=v[1][i].exp;
			x=v[1][i-1].f;
			j=i-1;
			while(i+1<=nrf[1] && v[1][i+1].f==x)
			{
				i++;
				nr+=v[1][i].exp;
				v[1][i].exp=0;
			}
			v[1][j].exp+=nr;
		}
	}
	i=1;
	j=1;
	while(i<=nrf[0] && j<=nrf[1])
	{
		if(v[0][i].f==v[1][j].f)
		{
			if(v[0][i].exp>v[1][j].exp)
			{
				aux.f=v[0][i].f;
				aux.exp=v[0][i].exp-v[1][j].exp;
				solA.push_back(aux);
			}
			else
				if(v[0][i].exp<v[1][j].exp)
				{
					aux.f=v[0][i].f;
					aux.exp=v[1][j].exp-v[0][i].exp;
					solB.push_back(aux);
				}
			i++;
			j++;
		}
		else
		{
			if(v[0][i].f<v[1][j].f)
				i++;
			else
				j++;
		}
	}
	
	n=solA.size();
	m=solB.size();
	x=1;
	for(i=0;i<n;i++)
	{
		aux=solA[i];
		F=aux.f;
		E=aux.exp;
		for(j=1;j<=E;j++)
		{
			x*=F;
			if(x>10000000)
			{
				x/=F;
				sol1.push_back(x);
				x=1;
				j--;
			}
		}
	}
	if(x>1 || (x==1 && sol1.size()==0))
		sol1.push_back(x);
	x=1;
	for(i=0;i<m;i++)
	{
		aux=solB[i];
		F=aux.f;
		E=aux.exp;
		for(j=1;j<=E;j++)
		{
			x*=F;
			if(x>10000000)
			{
				x/=F;
				sol2.push_back(x);
				x=1;
				j--;
			}
		}
	}
	if(x>1 || (x==1 && sol2.size()==0))
		sol2.push_back(x);
	
	n=sol1.size();
	m=sol2.size();
	cout<<n<<' '<<m<<"\n";
	for(i=0;i<n;i++)
		cout<<sol1[i]<<' ';
	cout<<"\n";
	for(i=0;i<m;i++)
		cout<<sol2[i]<<' ';
	cout<<"\n";
	return 0;
}
