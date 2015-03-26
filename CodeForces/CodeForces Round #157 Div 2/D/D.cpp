#include<iostream>
#include<map>
#define MOD 1000000007
using namespace std;
int n,nrc,zece[10],nr[10];
int v[11];
long long now,sol;
map <int,bool> viz;

inline int Nrcif(int x)
{
	int rez=0;
	while(x)
	{
		rez++;
		x/=10;
	}
	return rez;
}

inline int Nrlucky(int x)
{
	int rez=0;
	while(x)
	{
		if(x%10==4 || x%10==7)
			rez++;
		x/=10;
	}
	return rez;
}

inline void Euclid_extins(long long a,long long b,long long &x,long long &y)
{
    if(b==0LL)
    {
        x=1LL;
        y=0LL;
        return;
    }
    else
    {
        Euclid_extins(b,a%b,x,y);
        long long aux,q=a/b;
        aux=x;
        x=y;
        y=aux-y*q;
    }
}

inline long long Comb(int N,int K)
{
	long long n=(long long)N;
	long long k=(long long)K;
	if(n<k)
		return 0LL;
	if(K==0)
		return 1LL;
	if(K==1)
		return (n%MOD);
	if(K==2)
		return ((n*(n-1LL)/2LL)%MOD);
	long long rez=1LL,inv,aux,num;
	for(int i=N-K+1;i<=N;i++)
	{
		rez=rez*(long long)i;
		rez%=MOD;
	}
	num=1LL;
	for(int j=2;j<=K;j++)
		num*=j;
	inv=aux=0LL;
	Euclid_extins(num,MOD,inv,aux);
	while(inv<0)
		inv+=MOD;
	inv%=MOD;
	rez=rez*inv;
	rez%=MOD;
	return rez;
}

inline void Procesare()
{
	long long rez=1;
	int i,Nr[10];
	for(i=0;i<10;i++)
		Nr[i]=0;
	for(i=1;i<=6;i++)
		Nr[v[i]]++;
	for(i=0;i<10;i++)
	{
		rez=rez*Comb(nr[i],Nr[i]);
		rez%=MOD;
	}
	rez=rez*720LL;
	rez%=MOD;
	now+=rez;
	while(now>=MOD)
		now-=MOD;
}

inline void Back(int pas,int sum,int snow)
{
	if(pas==7)
		Procesare();
	else
	{
		int i;
		for(i=v[pas-1];snow+i<=sum;i++)
		{
			v[pas]=i;
			Back(pas+1,sum,snow+i);
		}
	}
}

int main()
{
	int i,x,y,lim;
	cin>>n;
	if(n==7)
	{
		cout<<"0\n";
		return 0;
	}
	if(n==1000000000)
		lim=100000000;
	else
	{
		nrc=Nrcif(n)-1;
		lim=1;
		while(nrc--)
			lim*=10;
	}
	zece[0]=1;
	for(i=1;i<=9;i++)
		zece[i]=zece[i-1]*10;
	for(x=1;x<lim;x++)
	{
		nrc=Nrcif(x);
		for(i=0;i<=nrc;i++)
		{
			y=((x/zece[i])*10+4)*zece[i]+x%zece[i];
			if(y<=n && !viz[y])
			{
				viz[y]=true;
				nr[Nrlucky(y)]++;
			}
			y=((x/zece[i])*10+7)*zece[i]+x%zece[i];
			if(y<=n && !viz[y])
			{
				viz[y]=true;
				nr[Nrlucky(y)]++;
			}
		}
	}
	nr[1]+=2;
	nr[0]=n;
	for(i=1;i<=9;i++)
		nr[0]-=nr[i];
	
	for(x=1;x<=9;x++)
	{
		if(nr[x])
		{
			now=0;
			Back(1,x-1,0);
			sol+=(now*(long long)nr[x])%MOD;
			sol%=MOD;
		}
	}
	cout<<sol<<"\n";
	return 0;
}
