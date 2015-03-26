#include <fstream>
using namespace std;
int n, m;
short nr[1510][1510][13],sol[30];
// nr[i][j] = nr de moduri de a imparti i bomboane in cel mult j parti

inline void Adunare(short A[],short B[])
{
	int i, t = 0;
	for( i = 1; i <= A[0] || i <= B[0] || t; ++i, t /= 10000)
		A[i] = (t += A[i] + B[i]) % 10000;
	A[0] = i - 1;
}

inline void Scadere(short A[],short B[])
{
    int i,t=0;
    for(i=1;i<=A[0];i++)
    {
        if(i<=B[0])
            A[i]=A[i]-B[i]-t;
        else
            A[i]=A[i]-t;
        if(A[i]<0)
        {
            t=1;
            A[i]+=10000;
        }
        else
            t=0;
    }
    while(A[0]>1 && A[A[0]]==0)
        A[0]--;
}

int main()
{
	int i, j;
	ifstream fin("sweets.in");
	fin >> n >> m;
	fin.close();
	
	for( j = 1; j <= m; ++j)
		nr[0][j][0] = nr[0][j][1] = 1;
	for( i = 1; i <= n; ++i)
	{
		for( j = 1; j <= m; ++j)
		{
			Adunare(nr[i][j],nr[i][j-1]);
			if(i>=j)
				Adunare(nr[i][j],nr[i-j][j]);
		}
	}
	Adunare(sol,nr[n][m]);
	Scadere(sol,nr[n][m-1]);
	
	freopen("sweets.out","w",stdout);
	printf("%hd",sol[sol[0]]);
	for( i = sol[0] - 1; i > 0; i--)
		printf("%04hd",sol[i]);
	printf("\n");
	return 0;
}
