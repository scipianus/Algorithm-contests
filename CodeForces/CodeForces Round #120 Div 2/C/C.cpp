#include<iostream>
using namespace std;
int n;
int St[100100],vf=-1;
string sol;
bool error=false;

int main()
{
	int i;
	string cuv;
	cin>>n;
	i=1;
	while(i<=n)
	{
		cin>>cuv;
		if(cuv[0]=='p')
		{
			sol+="pair<";
			St[++vf]=2;
			if(vf>=1 && St[vf-1]==2)
				St[vf-1]--;
		}
		else
		{
			i++;
			if(vf==-1)
			{
				error=true;
				i=n+1;
			}
			else
			{
				if(St[vf]==2)
				{
					sol+="int,";
					St[vf]--;
				}
				else
				{
					sol+="int>";
					vf--;
					while(vf>=0 && St[vf]==0)
					{
						sol+=">";
						vf--;
					}
					if(vf>=0)
					{
						sol+=",";
						St[vf]--;
					}
				}
			}
		}
	}
	if(error==true || vf>=0)
		cout<<"Error occurred\n";
	else
		cout<<sol<<"\n";
	return 0;
}
