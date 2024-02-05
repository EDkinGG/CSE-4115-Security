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
	p = 101;
	q = 103;
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


	int msg1 = 10;
	int msg2 = 15;
	int Msg_Combined_cipher = power(msg1*msg2,e,n);

	int cipher1 = power(msg1,e,n);
	int cipher2 = power(msg2,e,n);

	int Cipher_Combined = (cipher1*cipher2) % n;

	int Decrypted_Combined = power(Msg_Combined_cipher,d,n);
	int Decrypted_Combined_Cipher = power(Cipher_Combined,d,n);
	
	cout<<"Decrypted_Combined "<<Decrypted_Combined<<nl;
	cout<<"Decrypted_Combined_Cipher "<<Decrypted_Combined_Cipher<<nl;

	return 0;
}