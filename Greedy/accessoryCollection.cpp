#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORI(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long int li;
li get_total(li a,li b){
  li res1 = (b*(b+1))/2;
  li res2 = (a*(a-1))/2;
  return res1 - res2;
}

li max_expenditure(li l,li a,li n,li d){
  li result = -1;
  if(d>a){
    return -1;
  }
  if(d==1){
    return (a*l);
  }
  li upperlimit = (n-1)/(d-1);
  FOR(i,1,upperlimit){
    li extra = (n-1) - (i*(d-1));
    //cout<<"extra = "<<extra<<endl;
    if((extra + (i*a))<l){
      continue;
    }
    li temp = extra * a;
    li num = (l-extra)/i;
    li subtotal = get_total(a-num+1,a);
    temp += (i*subtotal);
    if((l-extra)%i !=0){
      li last = (l-extra)%i;
      temp += (a-num)*last;
    }
    if(temp>result){
      result = temp;
    }
    if (temp>result){
      result = temp;
    }
  }
  if(result == 0){
    result = -1;
  }
  
  return result;
}
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    li L,A,N,D;
    cin>>L>>A>>N>>D;
    li diff_types = (N-D) + 1;
    li req_num = L;
    li result = max_expenditure(L,A,N,D);
    if(result==-1){
      cout<<"SAD"<<endl;
    }else{
      cout<<result<<endl;
    }
  }
  return 0;
}
