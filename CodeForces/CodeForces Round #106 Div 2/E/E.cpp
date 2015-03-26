#include<iostream>
#include<cstring>
using namespace std;
int n,m,ns,sol;
char s[100100],cuv[110][1010],aux[110][1010],aux2[110][1010];
bool f[30];

int main()
{
	int i,j;
	char *p,*q;
	bool gasit;
	cin>>(s+1);
	n=strlen(s+1);
	cin>>m;
	for(i=1;i<=m;i++)
	{
		gasit=false;
		cin>>(cuv[i]+1);
		ns=strlen(cuv[i]+1);
		cuv[i][ns+1]=0;
		if(ns>n || ns<2)
			continue;
		for(j=1;j<ns && !gasit;j++)
		{
			strncpy(aux[i]+1,cuv[i]+1,j);
			aux[i][j+1]=0;
			p=strstr(s+1,aux[i]+1);
			if(p!=NULL && strlen(p+j)>=ns-j)
			{
				strncpy(aux2[i]+1,cuv[i]+j+1,ns-j);
				aux2[i][ns-j+1]=0;
				q=strstr(p+j,aux2[i]+1);
				if(q!=NULL)
				{
					sol++;
					gasit=true;
				}
			}
		}
	}
	cout<<sol<<"\n";
	return 0;
}
