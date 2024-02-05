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

int power( int a, int p, int mod )
{
	int res = 1;
	for( int i = 1 ; i <= p ; i++ )
	{
		res = res*a;
		res = ((res%mod)+mod)%mod;
	}
	return res;
}

int32_t main()
{
	int p = 1009;
	int q = 1013;

	int n = p*q;
	int phi = (p-1)*(q-1);

	int can_e = 2;
	int e = 2;
	while(can_e < phi )
	{
		int c_gcd = gcd(can_e,phi);
		if( c_gcd == 1 )
		{
			e = can_e;
			break;
		}
		can_e++;
	}

	int d;
	int k = 1;
	while( true )
	{
		int j = (phi*k) + 1;
		if( j%e == 0 )
		{
			d = j/e;
			break;
		} 
		k++;
	}
	int m = 66;
	cout<<"Private key(p,q,d) "<<p<<", "<<q<<", "<<d<<nl;
	cout<<"Public key(e,n) "<<e<<", "<<n<<nl;
	cout<<"Msg "<<m<<nl;


	//Signing
	int s = power(m,d,n);
	cout<<"Signing "<<s<<nl;


	//Verification
	int v = power(s,e,n);
	cout<<"Verification "<<v<<nl;


	if( v == m )
	{
		cout<<"Verified"<<nl;
	}
	else
	{
		cout<<"Not Verified"<<nl;
	}

}