#include<iostream>
using namespace std;
double vp,vd,start,pause,lg;
double pozp,pozd,sol;

int main()
{
	double pauza,t;
	bool gata=false;
	cin>>vp>>vd>>start>>pause>>lg;
	pozp=start*vp;
	pozd=0;
	if(pozp>=lg)
		gata=true;
	while(!gata)
	{
		t=(double)(pozp-pozd)/(double)(vd-vp);
		pozp=t*vp+pozp;
		pozd=t*vd+pozd;
		if(pozp>=lg)
			gata=true;
		else
		{
			sol++;
			pauza=pause+pozd/vd;
			pozp+=(pauza*vp);
			pozd=0;
			if(pozp>=lg)
				gata=true;
		}
		/*pozp+=vp;
		pozd+=vd;
		if(pozp>=lg)
			gata=true;
		else
		{
			if(pozd>=pozp)
			{
				sol++;
				pauza=pozd/vd+pause;
				pozp+=(pauza*vp);
				pozd=0;
				if(pozp>=lg)
					gata=true;
			}
		}*/
	}
	cout<<sol<<"\n";
	return 0;
}
