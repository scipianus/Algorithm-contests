/*
PROB : hillwalk
LANG : C++
*/
#include<fstream>
#include<algorithm>
using namespace std;
int n,sol,s,X[100100];
struct Punct{int x,y;};
struct Segment{Punct A,B;};
Segment v[100100];
Punct now;

inline bool Sortare(Segment s1,Segment s2)
{
	return s1.A.x<s2.A.x;
}

int main()
{
	int i,st,dr,ind;
	bool gasit;
	double y,miny;
	ifstream fin("hillwalk.in");
	fin>>n;
	for(i=1;i<=n;i++)
		fin>>v[i].A.x>>v[i].A.y>>v[i].B.x>>v[i].B.y;
	fin.close();
	
	sort(v+1,v+n+1,Sortare);
	for(i=1;i<=n;i++)
		X[i]=v[i].A.x;
	s=1;
	while(1)
	{
		sol++;
		now=v[s].B;
		st=lower_bound(X+1,X+n+1,now.x)-X-1;
		dr=upper_bound(X+1,X+n+1,now.x)-X;
		if(dr>n)
			dr=n;
		if(st<1)
			st=1;
		gasit=false;
		miny=2000000000.0;
		ind=0;
		for(i=st;i<=dr;i++)
		{
			if(v[i].A.x<=now.x && now.x<v[i].B.x)
			{
				y=(1.0*(v[i].B.y-v[i].A.y))/(1.0*(v[i].B.x-v[i].A.x));
				y=1.0*v[i].A.y+y*1.0*(now.x-v[i].A.x);
				if(y<1.0*now.y)
				{
					gasit=true;
					if(miny>y)
					{
						miny=y;
						ind=i;
					}
				}
			}
		}
		if(!gasit)
			break;
		else
			s=ind;
	}
	
	ofstream fout("hillwalk.out");
	fout<<sol<<"\n";
	fout.close();
	return 0;
}
