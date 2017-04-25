#include <iostream>
#include <map>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll get_modulo(ll num, ll pow){
  ll result = 1;
  while(pow){
    if((pow%2)!=0){
      result = (result*num)%MOD;
    }
    pow = pow/2;
    num = (num*num)%MOD;
  }
  return result;
}

int main(){
  map<char,int> mapping;
  map<char,int>::iterator it;
  string str;
  int count_odd=0;
  cin>>str;
  for(int i=0;i<str.size();i++){
    if(mapping.find(str[i])!=mapping.end()){
      mapping[str[i]] += 1;
    }else{
      mapping[str[i]] = 1;
    }
  }
  ll halfstrsize = str.size()/2;
  ll result = 1;
  ll denom = 1;
  ll numer = 1;
  for(it=mapping.begin();it!=mapping.end();++it){
    if((it->second)%2!=0){
      count_odd += 1;
      it->second -= 1;
    }
    it->second = (it->second/2);
    if(it->second > 1){
      for(int j=it->second;j>=1;j--){
	denom = (denom*j)%MOD;
      }
    }
  }
  if(count_odd>1){
    cout<<-1<<endl;
  }else{
    for(int i=1;i<=halfstrsize;i++){
      numer = (numer*i)%MOD;
    }
    denom = (get_modulo(denom,MOD-2))%MOD;
    result = (numer*denom)%MOD;
    cout<<result<<endl;
  }
  return 0;
}
