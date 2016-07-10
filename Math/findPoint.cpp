#include <iostream>
using namespace std;

struct Point{
  int x;
  int y;
  Point operator-(const Point& p2){
    Point p1;
    p1.x = (x-p2.x);
    p1.y = (y-p2.y);
    return p1;
  }
  Point operator+(const Point& p2){
    Point p1;
    p1.x = (x+p2.x);
    p1.y = (y+p2.y);
    return p1;
  }
}Point;

int main(){
  int tt;
  struct Point p1,p2,p3,p4;
  cin>>tt;
  while(tt--){
    cin>>p1.x>>p1.y;
    cin>>p2.x>>p2.y;
    p3 = (p2 - p1);
    p4 = (p2 + p3);
    cout<<p4.x<<" "<<p4.y<<endl;
  }
  return 0;
}
