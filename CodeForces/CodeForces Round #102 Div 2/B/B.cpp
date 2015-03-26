#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char s[210],intreg[210],frac[210],aux[210];
int n,ni,na;
vector <char> A;

int main()
{
	int i,j,k;
	cin>>s;
	n=strlen(s);
	if(s[0]=='-')
	{
		i=1;
		A.push_back('(');
		A.push_back('$');
		while(i<n && s[i]!='.')
			i++;
		strncpy(intreg,s+1,i-1);
		ni=i-1;
		k=0;
		for(j=ni-1;j>=0;j--)
		{
			aux[na++]=intreg[j];
			k++;
			if(k==3 && j!=0)
			{
				k=0;
				aux[na++]=',';
			}
		}
		for(j=na-1;j>=0;j--)
			A.push_back(aux[j]);
		if(i<n)
		{
			i++;
			if(n-i>=2)
				strncpy(frac,s+i,2);
			else
			{
				strncpy(frac,s+i,n-i);
				if(n-i==0)
				{
					frac[0]=frac[1]='0';
				}
				else
					frac[1]='0';
			}
			A.push_back('.');
			A.push_back(frac[0]);
			A.push_back(frac[1]);
		}
		else
		{
			A.push_back('.');
			A.push_back('0');
			A.push_back('0');
		}
		A.push_back(')');
	}
	else
	{
		i=0;
		A.push_back('$');
		while(i<n && s[i]!='.')
			i++;
		strncpy(intreg,s,i);
		ni=i;
		k=0;
		for(j=ni-1;j>=0;j--)
		{
			aux[na++]=intreg[j];
			k++;
			if(k==3 && j!=0)
			{
				k=0;
				aux[na++]=',';
			}
		}
		for(j=na-1;j>=0;j--)
			A.push_back(aux[j]);
		if(i<n)
		{
			i++;
			if(n-i>=2)
				strncpy(frac,s+i,2);
			else
			{
				strncpy(frac,s+i,n-i);
				if(n-i==0)
				{
					frac[0]=frac[1]='0';
				}
				else
					frac[1]='0';
			}
			A.push_back('.');
			A.push_back(frac[0]);
			A.push_back(frac[1]);
		}
		else
		{
			A.push_back('.');
			A.push_back('0');
			A.push_back('0');
		}
	}
	for(i=0;i<A.size();i++)
		cout<<A[i];
	cout<<"\n";
	return 0;
}
