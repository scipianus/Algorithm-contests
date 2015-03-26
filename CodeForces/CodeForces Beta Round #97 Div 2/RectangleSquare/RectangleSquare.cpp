#include<iostream>
#include<cmath>
using namespace std;
bool gasit=false,uz[10];
struct Punct{int x,y;};
Punct P[10];
short sol[10];

inline int Dist(short i,short j)
{
	return (int)(P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y);
}

void Prelucrare()
{
	int i;
	//patrat
	int ab,cd,ad,bc,ac,bd;
	ab=Dist(sol[1],sol[2]);
	cd=Dist(sol[3],sol[4]);
	ad=Dist(sol[1],sol[4]);
	bc=Dist(sol[2],sol[3]);
	ac=Dist(sol[1],sol[3]);
	bd=Dist(sol[2],sol[4]);
	if(ab!=bc || ab!=ad || ab!=cd || bc!=cd || bc!=ad || cd!=ad)
		return;
	if(ac!=bd)
		return;
	//dreptunghi
	ab=Dist(sol[5],sol[6]);
	cd=Dist(sol[7],sol[8]);
	ad=Dist(sol[5],sol[8]);
	bc=Dist(sol[6],sol[7]);
	ac=Dist(sol[5],sol[7]);
	bd=Dist(sol[6],sol[8]);
	if(ab!=cd || ad!=bc)
		return;
	if(ac!=bd)
		return;
	gasit=true;
	cout<<"YES\n";
	for(i=1;i<=4;i++)
		cout<<sol[i]<<' ';
	cout<<"\n";
	for(i=5;i<=8;i++)
		cout<<sol[i]<<' ';
	cout<<"\n";
}

inline void Back(short k)
{
	if(gasit)
		return;
	else
	{
		if(k==9)
			Prelucrare();
		else
		{
			short i;
			for(i=1;i<=8;i++)
			{
				if(uz[i]==false)
				{
					uz[i]=true;
					sol[k]=i;
					Back(k+1);
					uz[i]=false;
				}
			}
		}
	}
}

int main()
{
	int i;
	for(i=1;i<=8;i++)
		cin>>P[i].x>>P[i].y;
	Back(1);
	if(!gasit)
		cout<<"NO\n";
	return 0;
}
