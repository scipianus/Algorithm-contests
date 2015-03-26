#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int n,lg[110],nrtaxi[110],nrpizza[110],nrfete[110],maxtaxi,maxpizza,maxfete;
string nume[110];
vector <string> taxi,pizza,fete;

int main()
{
	int i,j,a[10];
	string nr;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>lg[i];
		cin>>nume[i];
		for(j=1;j<=lg[i];j++)
		{
			cin>>nr;
			a[1]=nr[0]-'0';
			a[2]=nr[1]-'0';
			a[3]=nr[3]-'0';
			a[4]=nr[4]-'0';
			a[5]=nr[6]-'0';
			a[6]=nr[7]-'0';
			if(a[1]==a[2] && a[1]==a[3] && a[1]==a[4] && a[1]==a[5] && a[1]==a[6])
				nrtaxi[i]++;
			else
			{
				if(a[1]>a[2] && a[2]>a[3] && a[3]>a[4] && a[4]>a[5] && a[5]>a[6])
					nrpizza[i]++;
				else
					nrfete[i]++;
			}
		}
		maxtaxi=max(maxtaxi,nrtaxi[i]);
		maxpizza=max(maxpizza,nrpizza[i]);
		maxfete=max(maxfete,nrfete[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(nrtaxi[i]==maxtaxi)
			taxi.push_back(nume[i]);
		if(nrpizza[i]==maxpizza)
			pizza.push_back(nume[i]);
		if(nrfete[i]==maxfete)
			fete.push_back(nume[i]);
	}
	cout<<"If you want to call a taxi, you should call: ";
	cout<<taxi[0];
	for(i=1;i<taxi.size();i++)
		cout<<", "<<taxi[i];
	cout<<".\n";
	cout<<"If you want to order a pizza, you should call: ";
	cout<<pizza[0];
	for(i=1;i<pizza.size();i++)
		cout<<", "<<pizza[i];
	cout<<".\n";
	cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
	cout<<fete[0];
	for(i=1;i<fete.size();i++)
		cout<<", "<<fete[i];
	cout<<".\n";
	return 0;
}
