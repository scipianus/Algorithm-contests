#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int T,n;
long long A,B,v[1500000];

inline void Back(int pas,long long val)
{
	if(val>10000000000LL)
		return;
	if((long long)sqrt(1.0*val)*(long long)sqrt(1.0*val)==val)
		v[++n]=val;
	if(pas>0)
		Back(pas+1,val*10LL);
	Back(pas+1,val*10LL+1LL);
	Back(pas+1,val*10LL+4LL);
	Back(pas+1,val*10LL+9LL);
}

int main()
{
	int st,dr;
	Back(0,0);
	v[++n]=100000000000LL;
	sort(v+1,v+n+1);
	cin>>T;
	while(T--)
	{
		cin>>A>>B;
		st=lower_bound(v+1,v+n+1,A)-v;
		dr=upper_bound(v+1,v+n+1,B)-v-1;
		cout<<(dr-st+1)<<"\n";
	}
	return 0;
}
