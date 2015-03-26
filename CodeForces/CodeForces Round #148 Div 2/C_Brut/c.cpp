#include<iostream>
#define MOD 1000000009
using namespace std;
int n,m,sol,v[20];

inline void Back(int k)
{
	if(k==n+1)
		sol++;
	else
	{
		int i,j,sumaxor;
		bool gresit;
		for(i=1;i<(1<<m);i++)
		{
			sumaxor=i;
			gresit=false;
			for(j=k-1;j>0;j--)
			{
				sumaxor^=v[j];
				if(sumaxor==0)
					gresit=true;
			}
			if(!gresit)
			{
				v[k]=i;
				Back(k+1);
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	Back(1);
	cout<<sol<<"\n";
	return 0;
}
