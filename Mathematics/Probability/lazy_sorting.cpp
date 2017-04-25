#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#define pb push_back
using namespace std;
typedef long int li;
bool isSorted(vector<li> vec){
  li first_element = vec[0];
  for(int i=1;i<vec.size();i++){
    if(vec[i]<first_element){
      return false;
    }else{
      first_element = vec[i];
    }
  }
  return true;
}

li fact(li num){
  li result = 1;
  for(int i=1;i<=num;i++){
    result *= i;
  }
  return result;
}

int main(){
  li n;
  cin>>n;
  vector<li> inpvec;
  map<li,li> count;
  for(int i=0;i<n;i++){
    li val;
    cin>>val;
    inpvec.pb(val);
    if(count.find(val)!=count.end()){
      count[val]++;
    }else{
      count[val] = 1;
    }
  }
  if(isSorted(inpvec)){
    cout<<fixed<<setprecision(6)<<0.0<<endl;
  }else{
    double result = 0.0;
    result += ((double)(fact(n)));
    for(map<li,li>::iterator it=count.begin();it!=count.end();++it){
      result /= ((double)(fact(it->second)));
    }
    cout<<fixed<<setprecision(6)<<result<<endl;
  }
  return 0;
}
  
  
