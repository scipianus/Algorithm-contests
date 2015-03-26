#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long MOD,L,R,K,gcdmax;
long long A[2][2]={{0,1},{1,1}};
long long B[2][2]={{0,1},{1,1}};
long long rez[2][2]={{0,0},{0,0}};

inline long long CautareBinara()
{
	long long st,dr,mij,rez=1LL,lim1,lim2,nr;
	st=1LL;
	dr=R;
	while(st<=dr)
	{
		mij=st+dr;
		mij/=2LL;
		lim2=R-R%mij;
		if(L%mij==0LL)
			lim1=L;
		else
			lim1=L-L%mij+mij;
		nr=lim2-lim1;
		nr/=mij;
		nr++;
		if(nr>=K)
		{
			rez=max(rez,mij);
			st=mij+1LL;
		}
		else
			dr=mij-1LL;
	}
	return rez;
}

inline void InmultesteMatrici(long long rez[2][2],long long A[2][2],long long B[2][2])
{
	rez[0][0]=((A[0][0]*B[0][0])%MOD + (A[0][1]*B[1][0])%MOD)%MOD;
	rez[0][1]=((A[0][0]*B[0][1])%MOD + (A[0][1]*B[1][1])%MOD)%MOD;
	rez[1][0]=((A[1][0]*B[0][0])%MOD + (A[1][1]*B[1][0])%MOD)%MOD;
	rez[1][1]=((A[1][0]*B[0][1])%MOD + (A[1][1]*B[1][1])%MOD)%MOD;
}

inline void LgPut(long long put)
{
	long long i=1LL,j=put;
	while(j>1LL)
	{
		i=i*2LL;
		j=j/2LL;
	}
	i=i/2LL;
	while(i)
	{
		InmultesteMatrici(rez,A,A);
		memcpy(A,rez,4*sizeof(long long));
		if(put&i)
		{
			InmultesteMatrici(rez,B,A);
			memcpy(A,rez,4*sizeof(long long));
		}
		i=i/2LL;
	}
}

int main()
{
	cin>>MOD>>L>>R>>K;
	gcdmax=CautareBinara();
	if(gcdmax<=2LL)
	{
		if(MOD>1LL)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
	else
	{
		LgPut(gcdmax-1LL);
		cout<<A[1][1]<<"\n";
	}
	return 0;
}
