#include <bits/stdc++.h>
using namespace std;
#define int            long long int
#define nl             "\n"


int32_t main()
{
    string s,k;
    cout<<"Enter the message : ";
    cin>>s;
    cout<<"Enter the key(same len as msg) : ";
    cin>>k;

    int n = s.size();

    for( int i = 0 ; i < n ; i++ )
    {
        s[i] = toupper(s[i]);
        k[i] = toupper(k[i]);
    }
    string cipher;
    cipher = s;
    for( int i = 0 ; i < n ; i++ )
    {
        int vals = cipher[i] - 'A';
        int valk = k[i] - 'A';
        int fval = vals+valk;
        fval = fval%26;
        cipher[i] = 'A'+fval;
    }
    cout<<cipher<<nl;
    string decrypted;
    decrypted = cipher;

    for( int i = 0 ; i < n ; i++ )
    {
        int vals = decrypted[i] - 'A';
        int valk = k[i] - 'A';
        int fval = vals-valk;
        if( fval < 0 )
        {
            fval = 26-abs(fval);
        }
        fval = fval%26;
        decrypted[i] = 'A'+fval;
    }
    cout<<decrypted<<nl;

    return 0;
}
