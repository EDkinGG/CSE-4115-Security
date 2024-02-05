#include <bits/stdc++.h>
using namespace std;
#define int            long long int
#define nl             "\n"

int gcd(int a, int b)
{
	if( b == 0 )
	{
		return a;
	}
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
	int p,q;
	p = 1009;
	q = 1013;
	int n = p*q;
	int phi = (p-1)*(q-1);
	cout<<"N "<<n<<" Phi "<<phi<<nl;
	int e;
	int tempE = 2;
	int c_gcd = 0; 
	while( c_gcd != 1  && tempE < phi )
	{
		c_gcd = gcd(tempE,phi);
		if( c_gcd == 1 )
		{
			e = tempE;
			break;
		}
		tempE++;
	}
	cout<<"Encryption Key-> "<<e<<nl;

	int d;

	int k = 1;
	while(true)
	{
		int j = (phi*k)+1;
		if( j%e == 0 )
		{
			d = j/e;
			break;
		}
		k++;
	}
	cout<<"decryption Key-> "<<d<<nl;


	int msg = 66;
	cout<<"msg "<<msg<<nl;
	int cipher = power(msg,e,n);
	cout<<"cipher "<<cipher<<nl;
	int decrypted = power(cipher,d,n);
	cout<<"decrypted msg "<<decrypted<<nl;


	return 0;
}