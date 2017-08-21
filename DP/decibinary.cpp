#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans;
int val(int x){
  int d=0,s=0;
  while(x>0){
    s += (x%10)*(1<<d);
    x /= 10;
    d++;
  }
  return s;
}

bool comp(int a,int b){
  if(val(a)==val(b)){
    return a<b;
  }
  return val(a)<val(b);
}

void gen(int d, int s, int v){
  if((s<0)||(s>9*((1<<(d+1))-1)));
  else if(s==0 && d==-1)
    ans.push_back(v);
  else{
    for(int i=0;i<=9;i++){
      gen(d-1,s-i*(1<<(d)),v*10+i);
    }
  }
  
}

void gen(int d, int s, int v){
  if(s<0 || s>9*((1<<(d+1))-1));
  else if(s==0 && d==-1)
    ans.push_back(v);
  else{
    for(int i=0;i<=9;i++)
      gen(d-1,s-i*(1<<d),v*10+i);
  }
}
  
int main(){
  /*for(int i=0;i<=111110;i++){
    ans.push_back(i);
  }
  sort(ans.begin(),ans.end(),comp);*/
  for(int i=0;i<600;i++)
    gen(20,i,0);
  cout<<ans.size()<<endl;
  int q,x;
  cin>>q;
  while(q--){
    cin>>x;
    cout<<ans[x-1]<<endl;

  }
  return 0;
}
  
  
