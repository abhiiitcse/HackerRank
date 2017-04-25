#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

long int get_pow(long int val,long int expterm){
  long int result=1;
  while(expterm){
    if((expterm%2)!=0){
      result = (result*val)%MOD;
    }
    val = (val*val)%MOD;
    expterm = expterm/2;
  }
  return result;
}


int main(){
  long int a,b;
  long int t;
  cin>>a>>b>>t;
  long int x_val = get_pow(a+b,t)%MOD;
  long int y_val = get_pow(2,MOD-2)%MOD;
  y_val = get_pow(y_val,t)%MOD;
  long int result = (x_val*y_val)%MOD;
  cout<<result<<endl;
  return 0;
}
  
