#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef long int li;
li get_digit_sum(li num){
  li result = 0;
  while(num>0){
    result += (num%10);
    num /= 10;
  }
  return result;
}

/**
 * Get the sum of the prime factor of any number
 */
li get_sum_prime_factor(li num){
  li result = 0;
  li last_val = ceil(sqrt(num));
  FOR(i,2,last_val){
    while((num%i)==0){
      result += get_digit_sum(i);
      num /= i;
    }
  }
  if(num>2){
    result += get_digit_sum(num);
  }
  return result;
}

int isSmithNum(li num){
  int result;
  li digit_sum = get_digit_sum(num);
  li prime_factor_sum = get_sum_prime_factor(num);
  //cout<<"d sum = "<<digit_sum<<endl;
  //cout<<"p sum = "<<prime_factor_sum<<endl;
  result = (digit_sum == prime_factor_sum)?1:0;
  return result;
}

int main(){
  li val;
  cin>>val;
  cout<<isSmithNum(val)<<endl;
  return 0;
}
