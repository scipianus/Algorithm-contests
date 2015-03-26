#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int masina[400100],nrliber,st[1000100],dr[1000100],loc[1000100];
struct Interval{int st,dr;};
vector <Interval> H;
int v[400100];

inline bool Sortare(Interval A,Interval B)
{
	if(A.dr-A.st==B.dr-B.st)
		return A.st>B.st;
	if(A.dr-A.st==B.dr-B.st+1 && (B.dr-B.st+1)%2==1)
		return A.st>B.st;
	if(A.dr-A.st==B.dr-B.st-1 && (A.dr-A.st+1)%2==1)
		return A.st>B.st;
	return (A.dr-A.st)<(B.dr-B.st);
}

inline void Aduna(int poz,int x)
{
	while(poz<=2*n)
	{
		v[poz]+=x;
		poz+=(poz & -poz);
	}
}

inline int Suma(int poz)
{
	int sum=0;
	while(poz>0)
	{
		sum+=v[poz];
		poz-=(poz & -poz);
	}
	return sum;
}

int main()
{
	Interval aux,aux2;
	int i,op,car,sum,left;
	//ifstream fin("E.in");
	//fin>>n>>m;
	cin>>n>>m;
	nrliber=n;
	for(i=1;i<=m;i++)
	{
		//fin>>op>>car;
		cin>>op>>car;
		if(op==1)
		{
			if(nrliber==n)
			{
				cout<<"1\n";
				Aduna(1,1);
				masina[1]=car;
				loc[car]=1;
				aux.st=2;
				aux.dr=2*n-2;
				H.push_back(aux);
				push_heap(H.begin(),H.end(),Sortare);
				st[car]=0;
				dr[car]=n+1;
				nrliber--;
			}
			else
			{
				aux=H[0];
				pop_heap(H.begin(),H.end(),Sortare);
				H.pop_back();
				left=max(aux.st-1,0);
				sum=Suma(aux.dr)-Suma(left);
				while(H.size()>0 && sum!=0)
				{
					aux=H[0];
					pop_heap(H.begin(),H.end(),Sortare);
					H.pop_back();
					left=max(aux.st-1,0);
					sum=Suma(aux.dr)-Suma(left);
				}
				loc[car]=(aux.st+aux.dr)/2;
				Aduna(loc[car],1);
				masina[loc[car]]=car;
				cout<<loc[car]<<"\n";
				if(loc[car]==n)
				{
					aux.dr=n-1;
					if(aux.dr-aux.st+1>0)
					{
						H.push_back(aux);
						push_heap(H.begin(),H.end(),Sortare);
					}
					st[car]=aux.st-1;
					dr[car]=n+1;
					nrliber--;
					dr[masina[aux.st-1]]=n;
				}
				else
					if(loc[car]==1)
					{
						aux.st=2;
						if(aux.dr-aux.st+1>0)
						{
							H.push_back(aux);
							push_heap(H.begin(),H.end(),Sortare);
						}
						st[car]=0;
						dr[car]=aux.dr+1;
						nrliber--;
						st[masina[aux.dr+1]]=1;
					}
					else
					{
						aux2.dr=aux.dr;
						aux2.st=loc[car]+1;
						if(aux2.dr-aux2.st+1>0)
						{
							H.push_back(aux2);
							push_heap(H.begin(),H.end(),Sortare);
						}
						aux.dr=loc[car]-1;
						if(aux.dr-aux.st+1>0)
						{
							H.push_back(aux);
							push_heap(H.begin(),H.end(),Sortare);
						}
						st[car]=aux.st-1;
						dr[car]=aux2.dr+1;
						nrliber--;
						dr[masina[aux.st-1]]=loc[car];
						st[masina[aux2.dr+1]]=loc[car];
					}
			}
		}
		else
		{
			Aduna(loc[car],-1);
			dr[masina[st[car]]]=dr[car];
			st[masina[dr[car]]]=st[car];
			masina[loc[car]]=0;
			nrliber++;
			aux.st=st[car]+1;
			aux.dr=dr[car]-1;
			if(aux.st<=1 && 1<=aux.dr)
				aux.st=2-aux.dr;
			else
				if(aux.st<=n && n<=aux.dr)
					aux.dr=2*n-aux.st;
			H.push_back(aux);
			push_heap(H.begin(),H.end(),Sortare);
		}
	}
	return 0;
}
