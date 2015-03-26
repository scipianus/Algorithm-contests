#include<iostream>
#include<cstdio>
using namespace std;
int nrop;
int St[200100],vf,add[200100];
long long sum;
double rez;

int main()
{
	int op,val,nr;
	scanf("%d",&nrop);
	St[++vf]=0;
	while(nrop--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d %d",&nr,&val);
			add[nr]+=val;
			sum+=1LL*nr*val;
		}
		if(op==2)
		{
			scanf("%d",&val);
			St[++vf]=val;
			sum+=1LL*val;
		}
		if(op==3)
		{
			sum-=1LL*St[vf];
			sum-=1LL*add[vf];
			add[vf-1]+=add[vf];
			add[vf]=0;
			vf--;
		}
		rez=1.0*sum;
		rez/=1.0*vf;
		printf("%.7lf\n",rez);
	}
	return 0;
}
