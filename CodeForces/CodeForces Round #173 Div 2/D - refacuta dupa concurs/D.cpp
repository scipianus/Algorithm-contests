#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,v[5],K;
double golden=1.6180339;
bool conf[310][310][310];
 
int main()
{
	int i,j,k,p,minim;
	cin>>n;
	if(n==1)
	{
		cin>>v[1];
		if(v[1]==0)
			cout<<"BitAryo\n";
		else
			cout<<"BitLGM\n";
	}
	if(n==2)
	{
		cin>>v[1]>>v[2];
		if(v[1]>v[2])
			swap(v[1],v[2]);
		K=v[2]-v[1];
		if((int)floor(golden*K)==v[1])
			cout<<"BitAryo\n";
		else
			cout<<"BitLGM\n";
	}
	if(n==3)
	{
		cin>>v[1]>>v[2]>>v[3];
		sort(v+1,v+4);
		for(i=0;i<=v[1];i++)
		{
			for(j=0;j<=v[2];j++)
			{
				for(k=0;k<=v[3];k++)
				{
					if(conf[i][j][k]==false)
					{
						minim=min(v[1]-i,min(v[2]-j,v[3]-k));
						for(p=1;p<=minim;p++)
							conf[i+p][j+p][k+p]=true;
						minim=v[1]-i;
						for(p=1;p<=minim;p++)
							conf[i+p][j][k]=true;
						minim=v[2]-j;
						for(p=1;p<=minim;p++)
							conf[i][j+p][k]=true;
						minim=v[3]-k;
						for(p=1;p<=minim;p++)
							conf[i][j][k+p]=true;
					}
				}
			}
		}
		if(conf[v[1]][v[2]][v[3]]==false)
			cout<<"BitAryo\n";
		else
			cout<<"BitLGM\n";
	}
    return 0;
}
