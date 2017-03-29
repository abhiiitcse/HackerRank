#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
typedef vector<long int> vli;
typedef long int li;
/**
 * As a and x are coprime, we can use euler method to find out the modulo inverse
 */
int getapowbmodx(long int a,long int b, long int x){
  long int ans=1;
  long int k = b;
  while(k){
    if((k%2)==1){
      ans = (ans*a)%x;
    }
    a = (a*a)%x;
    k = k/2;
  }
  return ans;
}

li gcd(li a,li b){
  li c,d;
  if(a>b){
    c = a;
    d = b;
  }else{
    c = b;
    d = a;
  }
  while(d){
    li temp = c%d;
    c = d;
    d = c%d;
  }
  return c;
}
    
int main(){
  const int maxind = 1000006;
  bool isprime[maxind];
  vli primenum;
  int tot= 0;
  memset(isprime,true,sizeof(isprime));
  FOR(i,2,maxind-1){
    if(isprime[i]){
      primenum.pb(i);
      for(int j=i*2;j<maxind;j+=i){
	isprime[j] = false;
      }
    }
  }
  int t;
  // cout<<"enter t"<<endl;
  cin>>t;
  while(t--){
    long int a,b,x,k,numer,m;
    cin>>a>>b>>x;
    m = x;
    if(b<0){
      int count = 0;
      numer = x;
      li denom = 1;
      li sqrtx = ceil(sqrt(x));
      while(primenum[count] <= sqrtx){
	li mul = primenum[count];
	if((x%mul)==0){
	  numer *= (mul-1);
	  denom *= mul;
	  li common = gcd(numer,denom);
	  numer /= common;
	  denom /= denom;
	  while((x%mul)==0){
	    x /= mul;
	  }
	}
	count++;
      }
      if((x!=1)&&isprime[x]){
	numer *= (x-1);
	denom *= x;
      }
      numer /= denom;
      k = numer - 1;
      b = -b;
    }
    li ans = getapowbmodx(a,k,m);
    ans = getapowbmodx(ans,b,m);
    cout<<ans<<endl;
  }
	 
  return 0;
}
