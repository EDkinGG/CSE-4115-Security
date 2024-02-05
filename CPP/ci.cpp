#include<bits/stdc++.h>
#define FastIO      ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define pb          push_back
#define mp          make_pair
#define mem(x,i)    memset(x,i,sizeof(x))
#define ff          first
#define ss          second
#define all(x)      x.begin(),x.end()
#define fileout     freopen("output.txt","w",stdout)
#define filein      freopen("input.txt","r",stdin)
#define w(x)        cout << (#x) << " is " << x << "\n" ;
#define mod         1000000007
#define INF         1000000000
#define INF18       1e18
#define for1(i,n)   for( int i = 1 ; i<=n ; i++ )
#define for0(i,n)   for( int i = 0 ; i<n ; i++ )
typedef long long   ll;
const char nl = '\n';
 
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    string s;
    char k;
    cin>>s;
    int n = s.size();
    cin>>k;

    int val = k-'a'+1;
    cout<<val<<nl;

    for( int i = 0 ; i < n ; i++ )
    {
    	int v = s[i]-'a';
    	int fv = (v+val)%26;
    	s[i] = 'a'+fv;
    }
    cout<<s<<nl;

    for( int i = 0 ; i < n ; i++ )
    {
    	int v = s[i]-'a';
    	int fv = (v-val);
    	if( fv < 0 )
    	{
    		fv = 26 - fv;
    	}
    	s[i] = 'a'+fv;
    }
    cout<<s<<nl;

}

int main()
{
    FastIO ;
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}