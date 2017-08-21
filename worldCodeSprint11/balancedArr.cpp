#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  int mid = n/2;
  int first_sum = 0;
  int second_sum = 0;
  FOR(i,0,mid){
    int val;
    cin>>val;
    first_sum += val;
  }
  FOR(i,mid,n){
    int val;
    cin>>val;
    second_sum += val;
  }
  int result = abs(first_sum-second_sum);
  cout<<result<<endl;
  return 0;
}
