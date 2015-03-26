#include<iostream>
#include<cmath>
using namespace std;
int size[305],poz[305];;

int main()
{
	int i;
	cout<<302<<"\n";
	size[1]=1000000;
	poz[1]=0;
	size[2]=300;
	poz[2]=(int)ceil(2*sqrt((double)(size[1]*size[2])));
	for(i=3;i<=301;i++)
	{
		size[i]=size[i-1]-1;
		poz[i]=(int)ceil(2*sqrt((double)(size[i]*size[i-1]))+poz[i-1]);
	}
	size[302]=1000000;
	poz[302]=(int)ceil(2*sqrt((double)(size[302]*size[2]))+poz[2]);
	for(i=3;i<=301;i++)
		poz[302]=max(poz[302],(int)ceil(2*sqrt((double)(size[302]*size[i]))+poz[i]));
	for(i=1;i<=302;i++)
		cout<<poz[i]<<' '<<size[i]<<"\n";
	return 0;
}
