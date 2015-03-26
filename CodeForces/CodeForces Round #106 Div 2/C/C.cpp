#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n,lim,sum1,sum2;
struct Om{int nr,v;};
Om a[100100];
vector <Om> first,second;

inline bool Sortare(const Om A,const Om B)
{
	return A.v<B.v;
}

inline int Abs(int a)
{
	if(a>=0)
		return a;
	return -a;
}

int main()
{
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].v;
		a[i].nr=i;
		lim=max(lim,a[i].v);
	}
	sort(a+1,a+n+1,Sortare);
	for(i=1;i<=n;i++)
	{
		if(sum1==sum2)
		{
			if(first.size()<second.size())
			{
				first.push_back(a[i]);
				sum1+=a[i].v;
			}
			else
			{
				second.push_back(a[i]);
				sum2+=a[i].v;
			}
		}
		else
		{
			if(sum1<sum2)
			{
				first.push_back(a[i]);
				sum1+=a[i].v;
			}
			else
			{
				second.push_back(a[i]);
				sum2+=a[i].v;
			}
		}
	}
	if(Abs(sum1-sum2)>lim || Abs(first.size()-second.size())>1)
	{
		first.clear();
		second.clear();
		for(i=1;i<=n;i+=2)
		{
			if(i==n)
			{
				if(sum1-sum2>lim)
				{
					second.push_back(a[i]);
					sum2+=a[i].v;
				}
				else
				{
					first.push_back(a[i]);
					sum1+=a[i].v;
				}
			}
			else
			{
				first.push_back(a[i]); sum1+=a[i].v;
				second.push_back(a[i]); sum2+=a[i].v;
			}
		}
	}
	cout<<first.size()<<"\n";
	for(i=0;i<first.size();i++)
		cout<<first[i].nr<<' ';
	cout<<"\n"<<second.size()<<"\n";
	for(i=0;i<second.size();i++)
		cout<<second[i].nr<<' ';
	cout<<"\n";
	return 0;
}
