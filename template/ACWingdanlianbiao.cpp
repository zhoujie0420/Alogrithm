//
// Created by ZhouJie on 2022/5/23 20:26.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    list<int> li;
    int n;
    cin >> n;
    while(n--){
        char p;
        cin >> p;
        if(p == 'H') {
            int x;
            cin >> x;
            li.push_front(x);
        }else if(p == 'D') {
            int x;
            cin >> x;
            auto del = li.begin();
            while(x--) del++;
            li.erase(del);
        }else if(p == 'I'){
            int k, x;
            cin >> k >> x;
            auto ins = li.begin();
            while(k--) ins++;
            li.emplace(li.begin()+k,x);
        }
    }
    for(auto num: li) cout << num << " ";
    return 0;
}