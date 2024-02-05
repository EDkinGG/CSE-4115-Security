#include <bits/stdc++.h>
using namespace std;
#define int            long long int
#define nl             "\n"

int gcd(int a, int b)
{
	if( b == 0 )
		return a;
	return gcd(b,a%b);
}

int power(int b, int p, int mod)
{
   int res = 1;
   while( p > 0 )
   {
        if( (p&1) != 0 )
        {
            res = (res*b)%mod;
        }
        p = p>>1;
        b = (b*b)%mod;
   }
   return res%mod;
}

int modinv(int a, int p )
{
	a=a%p;
    for (int i = 1; i <= p-1;i++)
    {
        if((a*i)%p==1)
            return i;
    }
    return 0;
}

int L(int x, int n)
{
	return (x-1)/n;
}

int32_t main()
{
	int p = 101, q = 103;
	int n = p*q;
	int phi = (p-1)*(q-1);
	//here gcd(n,phi) = 1
	cout<<gcd(n,phi)<<nl;

	int lamda;

	lamda = ((p-1)*(q-1))/gcd(p-1,q-1);
	cout<<lamda<<nl;

	int g = 2;
	int cen_g = 2;
	while( cen_g < n*n )
	{
		int gg = gcd(cen_g,n*n);
		if( gg == 1)
		{
			g = cen_g;
			break;
		}
		cen_g++;
	}

	cout<<g<<nl;

	int fst = L(power(g,lamda,n*n),n);

	int miu = modinv(fst,n);
	cout<<miu<<nl;

	int m = 9000;
	int r = 59;
	// gcd(r,n) = 1
	int cipher = (power(g,m,n*n)*power(r,n,n*n))%(n*n);
	cout<<cipher<<nl;
	int gm = ((L(power(cipher,lamda,n*n),n)%n)*(miu%n))%n;
	cout<<gm<<nl;

}