#include <bits/stdc++.h>
using namespace std;
#define int            long long int
#define nl             "\n"


int power(int b, int p, int mod)
{
    b = b%mod;
    if(p == 0)
        return 1;
    int j = power(b,p/2,mod);
    j=(j*j)%mod;
    if(p%2==1)
        j=(j*b)%mod;
    return j;
}

int32_t main()
{
    int e = 29;
    int n = 17*19;
    int msg = 50;
    cout<<"Message: "<<msg<<endl;
    int cypher = power(msg,e,n);
    cout<<"Cypher: "<<cypher<<endl;

    int d=2;
    while(1)
    {
        int new_msg=power(cypher,d, n);
        if(new_msg==msg)
        {
            cout<<"New Message: "<<new_msg<<endl;
            cout<<"Private key: "<<d<<endl;
            break;
        }
        d++;
    }

    return 0;
}
