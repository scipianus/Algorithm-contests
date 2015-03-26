/*
PROB: climb
LANG: C++
*/
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int n,sol;
struct Vaca{int u,d;};
vector <Vaca> H1,H2;

void Citire()
{
	int i;
	Vaca aux;
	ifstream fin("climb.in");
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>aux.u>>aux.d;
		H1.push_back(aux);
	}
	fin.close();
}

inline bool SortareHeap1(Vaca A,Vaca B)
{
	if(A.u==B.u)
		return A.d>B.d;
	return A.u>B.u;
}

inline bool SortareHeap2(Vaca A,Vaca B)
{
	return A.d>B.d;
}

void Rezolvare()
{
	Vaca aux,aux2;
	int t;
	make_heap(H1.begin(),H1.end(),SortareHeap1);
	
	aux=H1[0];
	pop_heap(H1.begin(),H1.end(),SortareHeap1);
	H1.pop_back();
		
	H2.push_back(aux);
	push_heap(H2.begin(),H2.end(),SortareHeap2);
	
	sol=aux.u;
	
	while(H1.size())
	{
		if(!H2.size())
		{
			aux=H1[0];
			pop_heap(H1.begin(),H1.end(),SortareHeap1);
			H1.pop_back();
				
			H2.push_back(aux);
			push_heap(H2.begin(),H2.end(),SortareHeap2);
			
			sol+=aux.u;
		}
		aux=H2[0];
		pop_heap(H2.begin(),H2.end(),SortareHeap2);
		H2.pop_back();
		
		sol+=aux.d;
		while(H1.size() && H1[0].u<=aux.d)
		{
			aux.d-=H1[0].u;
			
			aux2=H1[0];
			pop_heap(H1.begin(),H1.end(),SortareHeap1);
			H1.pop_back();
			
			H2.push_back(aux2);
			push_heap(H2.begin(),H2.end(),SortareHeap2);
		}
		if(H1.size())
		{
			H1[0].u-=aux.d;
		}
	}
	while(H2.size())
	{
		aux=H2[0];
		pop_heap(H2.begin(),H2.end(),SortareHeap2);
		H2.pop_back();
		
		sol+=aux.d;
	}
}

void Afisare()
{
	ofstream fout("climb.out");
	fout<<sol<<"\n";
	fout.close();
}

int main()
{
	Citire();
	Rezolvare();
	Afisare();
	return 0;
}
