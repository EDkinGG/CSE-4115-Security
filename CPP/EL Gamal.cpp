#include<bits/stdc++.h>
using namespace std ;
long long calculating(long long g,long long x,long long p){
   long long res=1 ;
  for(int i=0;i<x;i++){
     res=res*g;
     res=res%p;
  }
  return res;
}
int main(){
    long long  g,y,p,x;
    p=2039;
    x=13;
    g=5;
    y=calculating(g,x,p);
    //printf("%d",y);
    long long m = 1807093;

    long long r =  rand()%m;


    long long c1 = calculating(g,r,p);
    long long c2 = m *calculating(y,r,p) ;

    long long dm = c2 /calculating(c1,x,p);
    cout<<"message="<<m<<"\n";
    cout<<"encryption="<<c1 <<c2<<"\n";
    cout<<"after decryption="<<dm;

    return 0;
}