#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int A[10],B[10],na,nb,ns,baz,a,b,nrsol;
char s[20];
bool nosol,manysol;
vector <int> sol;

int main()
{
	int i,j,k,aux;
	bool gata=false,ok1=true,ok2=true;
	cin>>s;
	ns=strlen(s);
	i=0;
	while(s[i]!=':')
	{
		if('0'<=s[i] && s[i]<='9')
			A[++na]=s[i]-'0';
		else
			A[++na]=s[i]-'A'+10;
		baz=max(baz,A[na]);
		i++;
	}
	i++;
	while(i<ns)
	{
		if('0'<=s[i] && s[i]<='9')
			B[++nb]=s[i]-'0';
		else
			B[++nb]=s[i]-'A'+10;
		baz=max(baz,B[nb]);
		i++;
	}
	baz++;
	for(i=1;i<na;i++)
	{
		if(A[i]!=0)
			ok1=false;
	}
	for(i=1;i<nb;i++)
	{
		if(B[i]!=0)
			ok2=false;
	}
	if(ok1==true && ok2==true && A[na]<24 && B[nb]<60)
	{
		manysol=true;
		gata=true;
	}
	while(!gata)
	{
		a=A[na];
		for(i=na-1,j=1;i>0;i--,j++)
		{
			aux=A[i];
			for(k=1;k<=j;k++)
				aux*=baz;
			a+=aux;
		}
		if(a>23)
		{
			if(nrsol==0)
				nosol=true;
			gata=true;
			continue;
		}
		b=B[nb];
		for(i=nb-1,j=1;i>0;i--,j++)
		{
			aux=B[i];
			for(k=1;k<=j;k++)
				aux*=baz;
			b+=aux;
		}
		if(b>59)
		{
			if(nrsol==0)
				nosol=true;
			gata=true;
			continue;
		}
		if(a<=23 && b<=59)
		{
			sol.push_back(baz);
			nrsol++;
			baz++;
		}
	}
	if(manysol==true)
		cout<<"-1\n";
	else
	{
		if(nosol==true)
			cout<<"0\n";
		else
		{
			for(i=0;i<sol.size();i++)
				cout<<sol[i]<<' ';
			cout<<"\n";
		}
	}
	return 0;
}
