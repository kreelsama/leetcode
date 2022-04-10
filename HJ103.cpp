#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int walk(const vector<int>& stamps){
    const int l = stamps.size();
    vector<int> max_stamps(l, 1);
    max_stamps[l-1] = 1;
    cout << l << endl;
    for(int i = l-2; i >= 0 ; i-- ){
        for(int j = i; j < l; j ++){
            if(stamps[j] > stamps[i] && max_stamps[i] < 1+ max_stamps[j]){
                 max_stamps[i] = 1 + max_stamps[j];
            }
        }
    }
    for(int i = 0; i < l; ++i){
        cout << max_stamps[i] << ' ';
    }
    return *max_element(max_stamps.begin(), max_stamps.end());
}

int main(void){
    // int len = 0;
    // cin >> len;
    vector<int> stamps = {2 ,5 ,1 ,5 ,4 ,5};
    // for(int i = 0; i < len; ++i){
    //     cin >> stamps[i];
    // }
    // for(int i = 0; i < len; ++i){
    //     cout << stamps[i] << ' ';
    // }

    cout << walk(stamps);
    return  0;
}