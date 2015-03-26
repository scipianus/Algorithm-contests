#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n;
char s[100100];
struct Element{int nr,st,dr;};
Element St[100100];
int vf=-1;

int main()
{
	int i;
	cin>>(s+1);
	n=strlen(s+1);
	Element aux,sol;
	sol.nr=-1;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='(')
		{
			aux.nr=-1;
			aux.st=aux.dr=i;
			St[++vf]=aux;
			continue;
		}
		if(s[i]=='[')
		{
			aux.nr=-2;
			aux.st=aux.dr=i;
			St[++vf]=aux;
			continue;
		}
		if(s[i]==')')
		{
			if(vf>0 && St[vf].nr>=0 && St[vf-1].nr==-1)
			{
				aux.st=St[vf-1].st;
				aux.dr=i;
				aux.nr=St[vf].nr;
				vf-=2;
				if(vf>=0 && St[vf].nr>=0)
				{
					aux.st=St[vf].st;
					aux.nr+=St[vf].nr;
					vf--;
				}
				St[++vf]=aux;
				if(aux.nr>sol.nr)
					sol=aux;
				continue;
			}
			if(vf>=0 && St[vf].nr==-1)
			{
				aux.st=St[vf].st;
				aux.dr=i;
				aux.nr=0;
				vf--;
				if(vf>=0 && St[vf].nr>=0)
				{
					aux.st=St[vf].st;
					aux.nr+=St[vf].nr;
					vf--;
				}
				St[++vf]=aux;
				if(aux.nr>sol.nr)
					sol=aux;
				continue;
			}
			vf=-1;
		}
		if(s[i]==']')
		{
			if(vf>0 && St[vf].nr>=0 && St[vf-1].nr==-2)
			{
				aux.st=St[vf-1].st;
				aux.dr=i;
				aux.nr=St[vf].nr+1;
				vf-=2;
				if(vf>=0 && St[vf].nr>=0)
				{
					aux.st=St[vf].st;
					aux.nr+=St[vf].nr;
					vf--;
				}
				St[++vf]=aux;
				if(aux.nr>sol.nr)
					sol=aux;
				continue;
			}
			if(vf>=0 && St[vf].nr==-2)
			{
				aux.st=St[vf].st;
				aux.dr=i;
				aux.nr=1;
				vf--;
				if(vf>=0 && St[vf].nr>=0)
				{
					aux.st=St[vf].st;
					aux.nr+=St[vf].nr;
					vf--;
				}
				St[++vf]=aux;
				if(aux.nr>sol.nr)
					sol=aux;
				continue;
			}
			vf=-1;
		}
	}
	if(sol.nr==-1)
		cout<<"0\n";
	else
	{
		cout<<sol.nr<<"\n";
		for(i=sol.st;i<=sol.dr;i++)
			cout<<s[i];
		cout<<"\n";
	}
	return 0;
}
