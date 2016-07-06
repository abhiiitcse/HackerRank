#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
  vector<int> inputval;
  map<int,int> mapped;
  int N;
  cin >> N;
  FOR(i,0,N){
    int val;
    cin>>val;
    if (mapped.find(val) != mapped.end()){
      mapped[val] = 1;
    }else{
      mapped[val] += 1;
    }
    inputval.push_back(val);
  }
  long double factval = 1.0;
  //FOR(i,1,N+1){
  //factval *= i;
  //}
  int gval = 0;
  for(map<int,int>::iterator it=mapped.begin();it!=mapped.end();++it){
    /*long double dubperm=1.0;
    FOR(i,1,it->second+1){
      dubperm *= i;
    }
    factval = factval/dubperm;*/
    gval += 1;
  }
  FOR(i,1,gval+1){
    factval *= i;
  }
    
  int a = 1;
  long double r = 1.0/factval;
  long double b = 1.0/factval;
  int d = 1;

  long double one_minus_r = 1.0 - r;
  long double one_minus_r2 = one_minus_r * one_minus_r;
  long double ab = (long double)(a*b);
  long double dbr = (long double)(d*b*r);
  //long double s = (long double)(ab/one_minus_r) + (long double)(dbr/one_minus_r2);
  long double s1 = (long double)(factval/(factval-1));
  long double s = s1/(factval-1);
  //long double s = s2
  cout<<fixed<<setprecision(6);
  cout<<s<<endl;
  //cout<<sizeof(long double)<<endl;
  return 0;
}
