#include<iostream>
#include<cstring>
using namespace std;
char s[150];
short n,m,sol;

inline void Back(short k,short pasi,short poz,short dir)
{
	if(k==n+1 && pasi==0)
		sol=max((int)sol,(int)poz);
	else
	{
		if(k==n+1)
			return;
		else
		{
			short i;
			if(s[k]=='F')
			{
				for(i=0;i<=pasi;i++)
				{
					if(i%2==0)
						Back(k+1,pasi-i,poz+dir,dir);
					else
						Back(k+1,pasi-i,poz,-dir);
				}
			}
			else
			{
				for(i=0;i<=pasi;i++)
				{
					if(i%2==1)
						Back(k+1,pasi-i,poz+dir,dir);
					else
						Back(k+1,pasi-i,poz,-dir);
				}
			}
		}
	}
}

int main()
{
	cin>>(s+1);
	n=strlen(s+1);
	cin>>m;
	Back(1,m,0,1);
	cout<<sol<<"\n";
	return 0;
}
