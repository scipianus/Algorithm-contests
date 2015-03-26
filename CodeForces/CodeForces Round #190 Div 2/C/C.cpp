#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int ns;
char s[110];
struct Pozitie{int x,y;};
Pozitie dif,finish,v[210];

inline int Semn(int x)
{
	if(x>=0)
		return 1;
	return -1;
}

int main()
{
	Pozitie now;
	int i,c;
	bool sol=false;
	cin>>finish.x>>finish.y;
	cin>>(s+1);
	ns=strlen(s+1);
	
	now.x=now.y=0;
	if(now.x==finish.x && now.y==finish.y)
		sol=true;
	v[0]=now;
	for(i=1;i<=ns;i++)
	{
		if(s[i]=='U')
			now.y++;
		if(s[i]=='D')
			now.y--;
		if(s[i]=='L')
			now.x--;
		if(s[i]=='R')
			now.x++;
		v[i]=now;
		if(now.x==finish.x && now.y==finish.y)
			sol=true;
	}
	if((now.x==0 || Semn(now.x)==Semn(finish.x)) && (now.y==0 || Semn(now.y)==Semn(finish.y)))
	{
		if(now.x)
		{
			if(now.y)
			{
				c=min(finish.x/now.x,finish.y/now.y);
				finish.x-=c*now.x;
				finish.y-=c*now.y;
			}
			else
				finish.x%=now.x;
		}
		else
			finish.y%=now.y;
		for(i=0;i<=ns;i++)
			if(v[i].x==finish.x && v[i].y==finish.y)
				sol=true;
	}
	if(sol)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}
