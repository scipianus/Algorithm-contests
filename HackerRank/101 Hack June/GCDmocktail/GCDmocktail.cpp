#include<iostream>
#define MOD 30000001 
using namespace std;
int T,n,d,Q,L,v[1010],nr[10000100],sol;

inline int LgPut(int baz,int put)
{
	int p=1;
	while(put)
	{
		if(put%2==1)
		{
			p=((1LL*p*baz)%MOD);
			put--;
		}
		baz=((1LL*baz*baz)%MOD);
		put/=2;
	}
	return p;
}

inline int Gcd(int a,int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

inline void Prelucrare()
{
	int i,gcd;
	gcd=v[1];
	for(i=2;i<=d;i++)
		gcd=Gcd(gcd,v[i]);
	nr[gcd]++;
}

inline void Back(int k)
{
	if(k==d+1)
		Prelucrare();
	else
	{
		int i;
		for(i=1;i<=n;i++)
		{
			v[k]=i;
			Back(k+1);
		}
	}
}

int main()
{
	int i;
	cin>>T;
	while(T--)
	{
		cin>>n>>d;
		Back(1);
		cin>>Q;
		while(Q--)
		{
			cin>>L;
			sol=0;
			for(i=1;i<=n;i++)
			{
				if(nr[i])
				{
					sol+=((1LL*nr[i]*LgPut(i,L))%MOD);
					if(sol>=MOD)
						sol-=MOD;
				}
			}
			cout<<sol<<"\n";
		}
		for(i=1;i<=n;i++)
			nr[i]=0;
	}
	return 0;
}
