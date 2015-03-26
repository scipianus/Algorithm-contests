#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define EPS 0.0000000001
using namespace std;
int n, nrrt;
double T, A[6][6], sol[6], drum, rt[4];

void Eliminarea_Gaussiana()
{
    int i,j,k,p;
    i=j=1;
    while(i<=4 && j<=4)
    {
        for(k=i;k<=4;k++)
        {
            if(A[k][j]>EPS || A[k][j]<-EPS)
                break;
        }
        if(k==5)
        {
            j++;
            continue;
        }
        if(k!=i)
        {
            for(p=1;p<=5;p++)
                swap(A[i][p],A[k][p]);
        }
        for(k=j+1;k<=5;k++)
            A[i][k]/=A[i][j];
        A[i][j]=1.0;
        for(k=i+1;k<=4;k++)
        {
            for(p=j+1;p<=5;p++)
                A[k][p]-=A[k][j]*A[i][p];
            A[k][j]=0.0;
        }
        i++;
        j++;
    }
}
 
void Determinare_Necunoscute()
{
    int i,j,k;
    bool gasit;
    for(i=4;i>0;i--)
    {
        gasit=false;
        for(j=1;j<=4 && !gasit;j++)
        {
            if(A[i][j]>EPS || A[i][j]<-EPS)
            {
                gasit=true;
                sol[j]=A[i][5];
                for(k=j+1;k<=4;k++)
                    sol[j]-=sol[k]*A[i][k];
            }
        }
    }
}

double Valoare(double x)
{
	return (sol[1] * x * x * x + sol[2] * x * x + sol[3] * x + sol[4]);
}

double Derivata(double x)
{
	return (3.0 * sol[1] * x * x + 2.0 * sol[2] * x + sol[3]);
}

double Primitiva(double x)
{
	return (sol[1] * x * x * x * x / 4.0 + sol[2] * x * x * x / 3.0 + sol[3] * x * x / 2.0 + sol[4] * x);
}

void Radacini()
{
	int i;
	double delta, x, a, b, c;
	x = 0.01;
	nrrt = 1;
	for(i = 1; i <= 10000; ++i)
	{
		if(fabs(Valoare(x)) < EPS)
		{
			i = 10001;
			continue;
		}
		x = x - (Valoare(x) / Derivata(x));
	}
	rt[1] = x;
	a = sol[1];
	b = rt[1] * a + sol[2];
	c = rt[1] * b + sol[3];
	delta = b * b - 4.0 * a * c;
	if(delta < -EPS)
		return;
	if(fabs(delta) < EPS)
	{
		nrrt = 2;
		rt[2] = -b / (2.0 * a);
		return;
	}
	nrrt = 3;
	rt[2] = (-b + sqrt(delta)) / (2.0 * a);
	rt[3] = (-b - sqrt(delta)) / (2.0 * a);
}

int main()
{
	int i;
	double t, v;
	cin >> n;
	while(n--)
	{
		cin >> T;
		for(i = 1; i <= 4; ++i)
		{
			cin >> t >> v;
			A[i][1] = t * t * t;
			A[i][2] = t * t;
			A[i][3] = t;
			A[i][4] = 1.0;
			A[i][5] = v;
		}
		Eliminarea_Gaussiana();
		Determinare_Necunoscute();
		Radacini();
		sort(rt + 1, rt + nrrt + 1);
		while(nrrt && rt[nrrt] >= T)
			nrrt--;
		i = 1;
		while(i <= nrrt && rt[i] <= 0.0)
			i++;
		if(i > nrrt)
			drum = fabs(Primitiva(T));
		else
		{
			drum = fabs(Primitiva(rt[i]));
			while(i + 1 <= nrrt)
			{
				drum += fabs(Primitiva(rt[i + 1]) - Primitiva(rt[i]));
				i++;
			}
			drum += fabs(Primitiva(T) - Primitiva(rt[i]));
		}
		printf("%.12lf\n", drum);
	}
	return 0;
}
