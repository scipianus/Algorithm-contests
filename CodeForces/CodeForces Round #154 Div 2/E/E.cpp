#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
int n,X;
struct Task{int t,pag,val,ind,ics;};
Task v[100100];
long long T;
int value[100100],sol;
long long final[100100];
vector <Task> H;

inline bool Sortare(Task A,Task B)
{
	if(A.t==B.t)
		return A.val>B.val;
	return A.t<B.t;
}

inline bool SortareH(Task A,Task B)
{
	return A.val<B.val;
}

inline long long Timp(int pri)
{
	int i,aux,size;
	long long timp;
	Task varf;
	H.clear();
	v[X].val=pri;
	sort(v+1,v+n+1,Sortare);
	for(i=1;i<=n;i++)
	{
		if(v[i].ics)
		{
			X=i;
			i=n+1;
		}
	}
	timp=(long long)v[1].t;
	H.push_back(v[1]);
	size=1;
	for(i=2;i<=n;i++)
	{
		if(size)
		{
			varf=H[0];
			pop_heap(H.begin(),H.end(),SortareH);
			H.pop_back();
			aux=varf.pag;
			timp=(long long)v[i].t;
			varf.pag-=(v[i].t-varf.t);
			size--;
			if(varf.pag>0)
			{
				varf.t=v[i].t;
				H.push_back(varf);
				push_heap(H.begin(),H.end(),SortareH);
				size++;
			}
			else
				final[varf.ind]=timp-(long long)(v[i].t-varf.t-aux);
		}
		H.push_back(v[i]);
		push_heap(H.begin(),H.end(),SortareH);
		size++;
	}
	while(size)
	{
		varf=H[0];
		pop_heap(H.begin(),H.end(),SortareH);
		H.pop_back();
		timp+=(long long)varf.pag;
		final[varf.ind]=timp;
		size--;
	}
	return final[v[X].ind];
}

inline int Next(int val,int d)
{
	int i;
	int gasit=0;
	for(i=2;i<=n && !gasit;i++)
	{
		if(value[i]==val)
			gasit=i;
	}
	if(!gasit)
		return val;
	for(i=gasit;i<=n && value[i]+1<=d;i++)
	{
		if(i<n)
		{
			if(value[i+1]-value[i]>1)
				return value[i]+1;
		}
		else
			return value[i]+1;
	}
	return 0;
}

inline int Pred(int val,int s)
{
	int i;
	int gasit=0;
	for(i=2;i<=n && !gasit;i++)
	{
		if(value[i]==val)
			gasit=i;
	}
	if(!gasit)
		return val;
	for(i=gasit;i>1 && value[i]-1>=s;i--)
	{
		if(i>2)
		{
			if(value[i]-value[i-1]>1)
				return value[i]-1;
		}
		else
			return value[i]-1;
	}
	return 0;
}

inline int CautareBinara()
{
	int st,dr,mij,mij1;
	long long rez;
	st=1;
	dr=1000000000;
	while(st<=dr)
	{
		mij=(st+dr)/2;
		mij1=Next(mij,dr);
		if(mij1==0)
			mij1=Pred(mij,st);
		rez=Timp(mij1);
		if(rez<T)
			dr=mij-1;
		else
		{
			if(rez>T)
				st=mij+1;
			else
				return mij1;
		}
	}
	return 1;
}

int main()
{
	int i;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>v[i].t>>v[i].pag>>v[i].val;
		v[i].ind=i;
		if(v[i].val==-1)
		{
			X=i;
			v[i].ics=1;
		}
		else
			value[i]=v[i].val;
	}
	fin>>T;
	sort(v+1,v+n+1,Sortare);
	sort(value+1,value+n+1);
	for(i=1;i<=n;i++)
	{
		if(v[i].ics)
		{
			X=i;
			i=n+1;
		}
	}
	sol=CautareBinara();
	fout<<sol<<"\n";
	for(i=1;i<=n;i++)
		fout<<final[i]<<' ';
	fout<<"\n";
	
	fin.close();
	fout.close();
	return 0;
}
