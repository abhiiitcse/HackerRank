#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
void nextMove(int n, int r, int c, vector <string> grid){
    short int princePos[2],botPos[2];
    int up,left;
    FOR(i,0,n){
        FOR(j,0,n){
            if (grid[i][j] == 'p'){
	           princePos[0] = i;
	           princePos[1] = j;
            }
        }
    }
    cout<<princePos[0]<<" ,"<<princePos[1]<<endl;
    botPos[0] = r;
    botPos[1] = c;
    
    if((up = (princePos[0] - botPos[0])) > 0){
        cout<<"DOWN"<<endl;
    }
    else if((up = (princePos[0] - botPos[0])) < 0){
        cout<<"UP"<<endl;
    }
    else if ((left = (princePos[1] - botPos[1])) > 0){
        cout<<"RIGHT"<<endl;
    }
    else if ((left = (princePos[1] - botPos[1])) < 0){
        cout<<"LEFT"<<endl;
    }
}

int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}

