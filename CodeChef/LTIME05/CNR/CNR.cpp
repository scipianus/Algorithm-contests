#include<iostream>
#include<cstring>
using namespace std;
int T,N,K,M[1010],aux[1010];

inline int Compara(int v1[],int v2[])
{
    if(v1[0]<v2[0])
        return -1;
    if(v1[0]>v2[0])
        return 1;
    int i;
    for(i=v1[0];i>0;i--)
    {
        if(v1[i]<v2[i])
            return -1;
        if(v1[i]>v2[i])
            return 1;
    }
    return 0;
}

inline void Scade(int A[],int B[])
{
    int i,t=0;
    for(i=1;i<=A[0];i++)
    {
        if(i<=B[0])
            A[i]=A[i]-B[i]-t;
        else
            A[i]=A[i]-t;
        if(A[i]<0)
        {
            t=1;
            A[i]+=10;
        }
        else
            t=0;
    }
    while(A[0]>1 && A[A[0]]==0)
        A[0]--;
}

inline void Inmulteste(int A[],int val)
{
    int i,t=0;
    for(i=1;i<=A[0] || t;i++,t/=10)
        A[i]=(t+=A[i]*val)%10;
    A[0]=i-1;
}
 
inline void Imparte(int A[],int val)
{
    int i,t=0;
    for(i=A[0];i>0;i--,t%=val)
    {
        t=t*10+A[i];
        A[i]=t/val;
    }
    while(A[0]>1 && A[A[0]]==0)
        A[0]--;
}

int main()
{
	int i,j;
	char s[1010];
	cin>>T;
	while(T--)
	{
		cin>>N>>K>>s;
		for(i=M[0];i>0;i--)
			M[i]=0;
		M[0]=strlen(s);
		for(i=1;i<=M[0];i++)
			M[i]=s[M[0]-i]-'0';
		for(i=1;i<=N;i++)
		{
			if(N-i+1==K)
			{
				while(K--)
					cout<<"1";
				i=N+1;
				continue;
			}
			//combinari de (N-i) luate cate K
			for(j=aux[0];j>=0;j--)
				aux[j]=0;
			aux[0]=aux[1]=1;
			for(j=2;j<=N-i;j++)
				Inmulteste(aux,j);
			for(j=2;j<=K;j++)
				Imparte(aux,j);
			for(j=2;j<=N-i-K;j++)
				Imparte(aux,j);
			if(Compara(aux,M)==-1)
			{
				cout<<"1";
				K--;
				Scade(M,aux);
			}
			else
				cout<<"0";
		}
		cout<<"\n";
	}
	return 0;
}
