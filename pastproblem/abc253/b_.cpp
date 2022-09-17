#include <bits/stdc++.h>
using namespace std;
int main(){
    int h, w;
    cin >> h>> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }
    vector<int> x,y;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == 'o'){
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    cout << abs(x[0] - x[1]) + abs(y[0] - y[1]) << endl;
}
