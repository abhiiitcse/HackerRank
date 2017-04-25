#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
long int fact(int n){
  long int result = 1;
  for(int i=1;i<=n;i++){
    result *= i;
  }
  return result;
}

long int ncr(int n,int r){
  long int numer = fact(n);
  long int denom = fact(r)*fact(n-r);
  long int result = numer/denom;
  return result;
}

double b(int x,int n,double p){
  double result = ((double)(ncr(n,x)));
  result *= pow(p,x);
  result *= pow(1.0-p,n-x);
  return result;
}

int main(){
  double p = 4.0/5.0;
  double first_result = 0.0;
  for(int i=3;i<=4;i++){
    first_result += b(i,4,p);
  }
  double second_result = 0.0;
  double q = 1.0- p;
  for(int i=3;i<=4;i++){
    second_result += b(i,4,q);
  }
  cout<<fixed<<setprecision(3)<<first_result<<endl;
  cout<<fixed<<setprecision(3)<<second_result<<endl;
  return 0;
}
  
