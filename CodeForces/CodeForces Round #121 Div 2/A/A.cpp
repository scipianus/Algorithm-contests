#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector <int> v;
vector <int>::iterator it;

int main()
{
	int i,aux;
	bool ok=false;
	cin>>n;
	for(i=1;i*(i+1)<=2*n;i++)
		v.push_back((i*(i+1))/2);
	for(i=0;i<v.size() && !ok;i++)
	{
		aux=n;
		aux-=v[i];
		it=lower_bound(v.begin(),v.end(),aux);
		if(it!=v.end() && *it==aux)
			ok=true;
	}
	if(ok)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
