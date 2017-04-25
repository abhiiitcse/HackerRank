#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  long int sum = 0;
  long int val;
  for(int i=0;i<n;i++){
    cin>>val;
    sum += val;
  }
  double prob = ((double)(sum))/2;
  cout<<fixed<<setprecision(1)<<prob<<endl;
  return 0;
}
