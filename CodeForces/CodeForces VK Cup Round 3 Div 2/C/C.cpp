#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[100100],nrsol;
struct Element{int val,st,dr;};
vector <Element> v,wait;
vector <Element> sol;

inline bool Sortare(Element A,Element B)
{
	return A.val<B.val;
}

inline bool Sortare2(Element A,Element B)
{
	if(A.st==B.st)
		return A.dr>B.dr;
	return A.st>B.st;
}

int main()
{
	int i,j,x,m,poz;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	Element aux;
	aux.val=a[1];
	aux.st=aux.dr=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]==aux.val)
			aux.dr++;
		else
		{
			if(aux.val!=0)
				v.push_back(aux);
			aux.val=a[i];
			aux.st=aux.dr=i;
		}
	}
	if(aux.val!=0)
		v.push_back(aux);
	aux.val=0;
	v.push_back(aux);
	make_heap(v.begin(),v.end(),Sortare);
	while(v[0].val!=0)
	{
		poz=sol.size();
		aux=v[0];
		pop_heap(v.begin(),v.end(),Sortare);
		v.pop_back();
		while(v[0].val==aux.val)
		{
			wait.push_back(aux);
			push_heap(wait.begin(),wait.end(),Sortare2);
			aux=v[0];
			pop_heap(v.begin(),v.end(),Sortare);
			v.pop_back();
		}
		wait.push_back(aux);
		push_heap(wait.begin(),wait.end(),Sortare2);
		x=aux.val;
		m=wait.size();
		for(i=0;i<m && wait.size();i++)
		{
			aux=wait[0];
			aux.val=x-v[0].val;
			pop_heap(wait.begin(),wait.end(),Sortare2);
			wait.pop_back();
			while(wait.size() && wait[0].st==aux.dr+1)
			{
				aux.dr=max(aux.dr+1,wait[0].dr);
				pop_heap(wait.begin(),wait.end(),Sortare2);
				wait.pop_back();
			}
			sol.push_back(aux);
			nrsol+=aux.val;
		}
		if(v[0].val!=0)
		{
			for(i=poz;i<sol.size();i++)
			{
				aux=sol[i];
				aux.val=v[0].val;
				v.push_back(aux);
				push_heap(v.begin(),v.end(),Sortare);
			}
		}
		wait.clear();
	}
	cout<<nrsol<<"\n";
	for(i=0;i<sol.size();i++)
	{
		aux=sol[i];
		for(j=1;j<=aux.val;j++)
			cout<<aux.st<<' '<<aux.dr<<"\n";
	}
	return 0;
}
