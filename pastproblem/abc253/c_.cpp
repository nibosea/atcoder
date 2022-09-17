#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    multiset<int> st;
    for(int i = 0; i < q ; i++){
        int t;
        cin >> t;
        if(t==1){
            int x;
            cin >> x;
            st.insert(x);
        }
        if(t==2){
            int x, c;
            cin >> x>> c;
            for(int j = 0; j < c ; j++){
                auto itr = st.lower_bound(x);
                if(itr == st.end()){
                    break;
                }
                if(*itr != x){
                    break;
                }
                st.erase(itr);
            }
        }
        if(t == 3){
            cout << *st.rbegin() - *st.begin() << endl;
        }
    }
}
