#include <bits/stdc++.h>
using namespace std;
#define int            long long int
#define nl             "\n"

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

int32_t main()
{
    int p = 101;
    vector<int>premitives;
    for( int i = 1 ; i <= p-1 ; i++ )
    {
        map<int,int>cnt;
        int flag = 1;
        for( int j = 1 ; j <= p-1 ; j++ )
        {
            int val = power(i,j,p);
            cnt[val]++;
            if( cnt[val] > 1 )
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            premitives.push_back(i);
        }
    }
    cout<<"Total Primitive Elements "<<premitives.size()<<nl;
    for( auto x:premitives )
    {
        cout<<x<<" ";
    }
    cout<<nl;

    return 0;
}
