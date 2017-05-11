#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;

struct Points{
  int x;
  int y;
  int index;
};

bool compare(Points &a, Points &b){
  if(a.x!=b.x){
    return (a.x<b.x);
  }
  return (a.y<b.y);
}
  
int main(){
  int n;
  cin>>n;
  vector<pii> edges;
  vector<Points> pts;
  FOR(i,0,n-1){
    int src,dest;
    cin>>src>>dest;
    edges.push_back(mp(src,dest));
    edges.push_back(mp(dest,src));
  }
  FOR(i,1,n+1){
    Points c;
    cin>>c.x;
    cin>>c.y;
    c.index = i;
    pts.push_back(c);
  }
  sort(pts.begin(),pts.end(),compare);
  bool assigned[n+1];
  FOR(i,1,n+1){
    assigned[i] = false;
  }
  int curr_pointer=0;
  bool done = false;
  int result[n+1];
  /*while(!done){
    done = true;
    //cout<<"here"<<endl;
    FOR(i,0,edges.size()){
      pii edg = edges[i];
      if(!assigned[edg.first]){
	//cout<<"edge="<<edg.first<<endl;
	assigned[edg.first] = true;
	result[edg.first] = pts[curr_pointer++].index;
	done = false;
      }
      if(!assigned[edg.second]){
	//cout<<"edge="<<edg.second<<endl;
	assigned[edg.second] = true;
	result[edg.second] = pts[curr_pointer++].index;
	done = false;
      }
      //cout<<"curr_pointer="<<curr_pointer<<endl;
    }
    curr_pointer=0;
    }*/
  
  FOR(i,0,n){
    cout<<pts[i].index<<" ";
  }
  cout<<endl;
      
  return 0;
}
