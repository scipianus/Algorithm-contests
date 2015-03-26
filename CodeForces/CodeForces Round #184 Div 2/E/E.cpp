#include<iostream>
#include<cstring>
using namespace std;
int n,nr[5010],nrwin;
char s[5010];
bool bun[5010];

int main()
{
	int i,lg=0,move;
	cin>>(s+1);
	n=strlen(s+1);
	for(i=2;i<n;i++)
		if(s[i-1]==s[i+1])
			bun[i]=true;
	for(i=n;i>0;i--)
	{
		if(!bun[i])
		{
			if(lg%4!=0)
			{
				nrwin++;
				if(lg%4==1)
					move=i+1;
				if(lg%4==2)
					move=i+1;
				if(lg%4==3)
					move=i+2;
			}
			lg=0;
		}
		else
			lg++;
	}
	if(nrwin%2==0)
		cout<<"Second\n";
	else
		cout<<"First\n"<<move<<"\n";
	
	return 0;
}
