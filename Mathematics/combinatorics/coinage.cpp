#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
class Coinage{
private:
  const static int max_index = 100000;
  int denom[4];
  int denom_cnt[4];
  int count[max_index][4];
  bool visited[max_index][4];
public:
  Coinage(int count[]);
  int get_count(int n,int k);
  ~Coinage();
};

/*
 * @Definition of functions of class
 */
Coinage::Coinage(int count1[]){
  FOR(i,0,3){
    denom_cnt[i] = count1[i];
  }
  FOR(i,0,max_index-1){
    FOR(j,0,3){
      count[i][j] = 0;
      visited[i][j] = false;
    }
  }
  denom[0] = 1; denom[1] = 2; denom[2] = 5; denom[3] = 10;
}

Coinage::~Coinage(){
}

int Coinage::get_count(int n, int k){
  if(!visited[n][k]){
    if(k==0){
      if(((n%denom[k])==0) && ((denom_cnt[k]*denom[k])>=n)){
	count[n][k] = 1;
      }else{
	count[n][k] = 0;
      }
      visited[n][k] = true;
    }else{
      int i= 0 ;
      int cnt = 0;
      while((i<=denom_cnt[k]) && ((i*denom[k])<=n)){
	cnt += get_count((n-(i*denom[k])),k-1);
	i+=1;
	count[n][k] = cnt ;
	visited[n][k] = true;
      }
    }
  }
  return count[n][k];
}

int main(){
  int count[4];
  int tt;
  cin>>tt;
  while(tt--){
    int n;
    cin>>n;
    FOR(i,0,3){
      cin>>count[i];
    }
    Coinage cobj(count);
    cout<<cobj.get_count(n,3)<<endl;
  }
  return 0;
}
