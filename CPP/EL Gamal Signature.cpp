#include<bits/stdc++.h>
using namespace std;

long long modinv(long long a, long long p)
{
    a=a%p;
    for (int i = 1; i < p-1;i++)
    {
        if((a*i)%p==1)
            return i;
    }
    return 0;
}


long long calculating(long long g,long long x,long long p)
{
   long long res=1 ;
  for(int i=0;i<x;i++){
     res=res*g;
     res=res%p;
  }
  return res;
}

int main(){
    long long  p,a,alpha,beta,k;
    p= 6421;
    a= 3;
    alpha= 11;
    beta = calculating(alpha,a,p);
    k = 7;
    //printf("%d",y);

    long long m = 1807093;

    cin>>m;

    long long y1 = calculating(alpha,k,p);
    cout<<y1<<endl;
    // cout<<(m-a*y1)<<endl;
    // cout<<modinv(k,p-1)<<endl;
    long long gg = (m-a*y1)*modinv(k,p-1);
    // cout<<(m-a*y1)*modinv(k,p-1)<<endl;
    long long y2 = ((gg%(p-1))+(p-1))%(p-1);
    cout<<y2<<endl;
    long long first = calculating(y1,y2,p)*calculating(beta,y1,p);
    first = first%p;
    long long second = calculating(alpha,m,p);

    cout<<"First- "<<first<<" Second- "<<second<<endl; 

    if( first == second )
    {
      cout<<"valid"<<endl;
    }
    else
    {
      cout<<"Not valid"<<endl;
    }

    return 0;
}