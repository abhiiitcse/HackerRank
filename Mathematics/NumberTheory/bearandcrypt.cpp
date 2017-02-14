#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b,d) for(int i=a;i<=b;i+=d)
typedef long int li;
typedef vector<li> vli;
typedef vector<pair<li,li> > vlii;

/**
 * Get the prime number divisor of a number
 */
vlii get_prime(li n){
  vlii result;
  li max_div = ceil(sqrt(n));
  FOR(i,2,max_div){
    int count = 0;
    while((n%i)==0){
      count++;
      n /= i;
    }
    if(count>0)
      result.pb(mp(i,count));
  }
  if(n>1){
    result.pb(mp(n,1));
  } 
  return result;
}

/**
 * Get the divisor of a number
 */
vli get_divisors(li n, vlii prime_num){
  vli result;
  vli div;
  vli temp;
  div.pb(1);
  if(prime_num.size()>=1){
    FOR(i,0,prime_num.size()-1){
      li p = prime_num[i].first;
      li r = prime_num[i].second;
      FOR(j,0,div.size()-1){
	FOR(k,0,r){
	  temp.pb(div[j]*(pow(p,k)));
	}
      }
      div = temp;
      temp.clear();
    }
  }
  result = div;
  return result;
}

li get_large_num(li n, li k){
  if(n==0){
    return -1;
  }else{
    vlii pmnum = get_prime(n);
    vli val = get_divisors(n,pmnum);
    if(val.size()==k){
      return n;
    }else{
      return get_large_num(n-1,k);
    }
  }
}
    

int main(){
  int t;
  cin>>t;
  while(t--){
    li n,k;
    cin>>n>>k;
    li ret_val = get_large_num(n,k);
    cout<<ret_val<<endl;
  }
  return 0;
}
