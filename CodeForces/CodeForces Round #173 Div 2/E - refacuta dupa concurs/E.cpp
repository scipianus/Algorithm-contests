#include<iostream>
using namespace std;
int n,lim=63;
long long v[100100],sumaxor[100100],sumaxor2[100100],sol,put[64];
struct Trie
{
    Trie *st,*dr;
    int poz;
    Trie()
    {
        poz=0;
        st=dr=NULL;
    }
};
Trie *T=new Trie;
 
inline int Search(Trie *nod,long long x)
{
    int i;
	long long bit;
    for(i=lim;i>=0;i--)
    {
        bit=(x & put[i]);
        if(bit)            
        {
            if(nod->dr!=NULL)
                nod=nod->dr;
            else
                nod=nod->st;
        }
        else                
        {
            if(nod->st!=NULL)
                nod=nod->st;
            else
                nod=nod->dr;
        }
    }
    return nod->poz; 
}
 
inline void Push(Trie *nod,long long x,int poz)
{
    int i;
	long long bit;
    for(i=lim;i>=0;i--)
    {
        bit=(x & put[i]);
        if(bit)                     
        {
            if(nod->st==NULL)
                nod->st=new Trie;
            nod=nod->st;
        }
        else                        
        {
            if(nod->dr==NULL)
                nod->dr=new Trie;
            nod=nod->dr;
        }
    }
    nod->poz=poz;    
}
 
int main()
{
    int i,j;
	put[0]=1LL;
	for(i=1;i<=63;i++)
		put[i]=put[i-1]*2LL;
    cin>>n;
    Push(T,0,0);
	for(i=1;i<=n;i++)
		cin>>v[i];
	for(i=n;i>0;i--)
		sumaxor2[i]=(sumaxor2[i+1]^v[i]);
    for(i=1;i<=n;i++)
    {
        sumaxor[i]=(sumaxor[i-1]^v[i]);
        j=Search(T,sumaxor2[i]); 
        if(sol<(sumaxor[j]^sumaxor2[i]))
            sol=(sumaxor[j]^sumaxor2[i]);
        Push(T,sumaxor[i],i); 
    }
	j=Search(T,0);
	if(sol<sumaxor[j])
		sol=sumaxor[j];
	cout<<sol<<"\n";
    return 0;
}
