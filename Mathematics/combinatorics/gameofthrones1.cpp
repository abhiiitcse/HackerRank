#include <iostream>
#include <map>
using namespace std;
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
  bool result = true;
  for(it=mapping.begin();it!=mapping.end();++it){
    if((it->second)%2!=0){
      count_odd += 1;
    }
  }
  if(count_odd>1){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
  }
  return 0;
}
