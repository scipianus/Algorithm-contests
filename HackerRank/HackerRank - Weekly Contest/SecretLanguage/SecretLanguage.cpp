#include<iostream>
#include<cstring>
#include<map>
using namespace std;
string A,B;
char s[1000];
map <char,char> M[2];
int main()
{
	int i,ns;
	A+="ANBYCODUEPFXGQHVIRJZKSLWMT";
	B+="anbycoduepfxgqhvirjzkslwmt";
	for(i=0;i<26;i++)
	{
		M[0][A[i]]=(char)('A'+i);
		M[1][B[i]]=(char)('a'+i);
	}
	cin.getline(s,1000);
	while(s[1]!='O')
	{
		ns=strlen(s);
		if(s[0]=='E')
		{
			for(i=7;i<ns;i++)
			{
				if('A'<=s[i] && s[i]<='Z')
					cout<<A[s[i]-'A'];
				else
					if('a'<=s[i] && s[i]<='z')
						cout<<B[s[i]-'a'];
					else
						cout<<s[i];
			}
			cout<<"\n";
		}
		else
		{
			for(i=7;i<ns;i++)
			{
				if('A'<=s[i] && s[i]<='Z')
					cout<<M[0][s[i]];
				else
					if('a'<=s[i] && s[i]<='z')
						cout<<M[1][s[i]];
					else
						cout<<s[i];
			}
			cout<<"\n";
		}
		cin.getline(s,1000);
	}
	return 0;
}
