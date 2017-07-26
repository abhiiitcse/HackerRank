#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ull;

ull get_pow(int b, int k, int m){
  ull result = 1;
  while(k!=0){
    if((k%2)!=0){
      result = (result*b)%m;
    }
    k = (k/2);
    b = (b*b)%m;
  }
  result = result%m;
  return result;
}

int main(){
  int k,b,m;
  string inp;
  vector<ull> listvec;
  cin>>inp;
  cin>>k>>b>>m;
  int n = inp.length();
  ull t0=0;
  for(int i=0;i<k;i++){
    ull curr_num = (ull)(inp[i]-'0');
    t0 = (t0 + (curr_num*get_pow(b,k-i-1,m)));
  }
  t0 = (t0%m);
  if(t0<0){
    t0 = t0 + m;
  }
  // cout<<t0<<endl;
  listvec.push_back(t0);
  for(int i=1,t=i+k-1;t<n;i++,t++){
    ull prev_num = (ull)(inp[i-1]-'0');
    ull curr_num = (ull)(inp[t]-'0');
    ull t1 = ((b*t0) + curr_num) - (prev_num*get_pow(b,k,m));
    t0 = t1%m;
    if(t0<0){
      t0 = t0 + m;
    }
    listvec.push_back(t0);
  }

  ull result = 0;
  for(int i=0;i<listvec.size();i++){
    result = result + ((listvec[i])%m);
  }


  //printing list vector
  //for(int i=0;i<listvec.size();i++){
  //cout<<listvec[i]<<",";
  //}
  //cout<<endl;

  cout<<result<<endl;
  return 0;
}
