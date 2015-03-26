/*
PROB : necklace
LANG : C++
*/
#include<fstream>
#include<cstring>
#include<queue>
using namespace std;
int na,nb,sol,Pi[1010],match[10010];
char A[10010],B[1010];
queue <int> Q;

inline void Prefix()
{
	int i,k=0;
    Pi[1]=0;
    for(i=2;i<=nb;i++)
    {
        while(k && B[k+1]!=B[i]) k=Pi[k];
        if(B[k+1]==B[i]) k++;
        Pi[i]=k;
    }
}

inline bool KMP()
{
    int i,k=0,size,ind;
	for(i=1;i<=na;i++)
		match[i]=0;
    k=0;
    for(i=1;i<=na;i++)
    {
        while(k && B[k+1]!=A[i]) k=Pi[k];
        if(B[k+1]==A[i]) k++;
        if(k==nb)
        {
            match[i-nb+1]=1;
            k=Pi[k];
        }
    }
	ind=1;
	for(i=1,size=0;i<=na;i++)
	{
		if(match[i]==1)
		{
			Q.push(i);
			size++;
		}
		if(!Q.empty() && Q.front()==i-nb)
		{
			Q.pop();
			size--;
		}
		match[i]=size;
		if(size>match[ind])
			ind=i;
	}
	while(!Q.empty())
		Q.pop();
	if(!match[ind])
		return false;
	for(i=ind;i<na;i++)
		A[i]=A[i+1];
	na--;
	return true;
}

int main()
{
	ifstream fin("necklace.in");
	fin>>(A+1); na=strlen(A+1);
	fin>>(B+1); nb=strlen(B+1);
	fin.close();
	
	Prefix();
	while(KMP())
		sol++;
	
	ofstream fout("necklace.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
