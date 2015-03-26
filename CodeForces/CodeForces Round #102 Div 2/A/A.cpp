#include<iostream>
#include<cstring>
using namespace std;
int r1,r2,c1,c2,d1,d2;

int main()
{
	int a,b,c,d;
	cin>>r1>>r2>>c1>>c2>>d1>>d2;
	for(a=1;a<10;a++)
	{
		for(b=1;b<10;b++)
		{
			for(c=1;c<10;c++)
			{
				for(d=1;d<10;d++)
				{
					if(a==b || a==c || a==d || b==c || b==d || c==d)
						continue;
					if(a+b==r1 && c+d==r2 && a+c==c1 && b+d==c2 && a+d==d1 && b+c==d2)
					{
						cout<<a<<' '<<b<<"\n";
						cout<<c<<' '<<d<<"\n";
						return 0;
					}
				}
			}
		}
	}
	cout<<"-1\n";
	return 0;
}
