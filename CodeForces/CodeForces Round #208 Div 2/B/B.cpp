#include<iostream>
#include<cstring>
using namespace std;
int n,ns,lg[200100],N;
string word[200100];
char s[100100];

int main()
{
	int i,j,k;
	cin>>n;
	N++;
	word[N]="<3";
	lg[N]=2;
	for(i=1;i<=n;i++)
	{
		N++;
		cin>>word[N];
		lg[N]=word[N].size();
		N++;
		word[N]="<3";
		lg[N]=2;
	}
	cin>>s;
	ns=strlen(s);
	
	for(i=1,j=0,k=0;i<=N && k<ns;k++)
	{
		if(s[k]==word[i][j])
		{
			j++;
			if(j==lg[i])
			{
				i++;
				j=0;
			}
		}
	}
	if(i==N+1)
		cout<<"yes\n";
	else
		cout<<"no\n";
	return 0;
}
