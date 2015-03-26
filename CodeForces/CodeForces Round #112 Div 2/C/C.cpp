#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int K,ns;
char s[1000100];
long long sol;
vector <int> poz;

int main()
{
	cin>>K;
	cin>>(s+1); ns=strlen(s+1);
	int i=1,nr=0;
	if(K==0)
	{
		for(i=1;i<=ns;i++)
		{
			if(s[i]=='0')
			{
				nr++;
				sol+=(long long)nr;
			}
			else
			{
				nr=0;
			}
		}
	}
	else
	{
		for(i=1;i<=ns;i++)
		{
			if(s[i]=='1')
			{
				if(nr<K)
				{
					nr++;
					poz.push_back(i);
					if(nr==K)
						sol+=(long long)poz[0];
				}
				else
				{
					nr++;
					poz.push_back(i);
					sol+=(long long)(poz[nr-K]-poz[nr-K-1]);
				}
			}
			else
			{
				if(nr==K)
				{
					sol+=(long long)poz[0];
				}
				else
				{
					if(nr>K)
					{
						sol+=(long long)(poz[nr-K]-poz[nr-K-1]);
					}
				}
			}
		}
	}
	cout<<sol<<"\n";
	return 0;
}
