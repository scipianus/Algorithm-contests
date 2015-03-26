/*
PROB: digits
LANG: C++
*/
#include<fstream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char s1[50],s2[50];
short A[50],B[50],ns1,ns2;
int a,b,sol;
vector <int> v;

int main()
{
	int i,p1=1,p2=1,aux1,aux2,x,lim;
	bool gasit=false;
	ifstream fin("digits.in");
	fin>>s1;
	fin>>s2;
	fin.close();
	ns1=strlen(s1);
	ns2=strlen(s2);
	for(i=1;i<ns1;i++)
		p1=p1*2;
	for(i=1;i<ns2;i++)
		p2=p2*3;
	aux1=p1;
	aux2=p2;
	for(i=0;i<ns1;i++)
	{
		A[i]=s1[i]-'0';
		a=a+p1*A[i];
		p1/=2;
	}
	for(i=0;i<ns2;i++)
	{
		B[i]=s2[i]-'0';
		b=b+p2*B[i];
		p2/=3;
	}
	p1=aux1;
	p2=aux2;
	for(i=0;i<ns1;i++)
	{
		if(A[i]==1)
		{
			x=a-p1;
			v.push_back(x);
		}
		else
		{
			x=a+p1;
			v.push_back(x);
		}
		p1/=2;
	}
	for(i=0;i<ns2;i++)
	{
		if(B[i]==0)
		{
			x=b+p2;
			v.push_back(x);
			x=b+2*p2;
			v.push_back(x);
		}
		else
		{
			if(B[i]==1)
			{
				x=b-p2;
				v.push_back(x);
				x=b+p2;
				v.push_back(x);
			}
			else
			{
				x=b-2*p2;
				v.push_back(x);
				x=b-p2;
				v.push_back(x);
			}
		}
		p2/=3;
	}
	sort(v.begin(),v.end());
	lim=v.size()-1;
	for(i=0;i<lim && !gasit;i++)
	{
		if(v[i]==v[i+1])
		{
			sol=v[i];
			gasit=true;
		}
	}
	ofstream fout("digits.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
