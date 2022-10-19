//
// Created by ZhouJie on 2022/7/20.
//

#include <bits/stdc++.h>

using namespace std;
const int N  = 10010;




int main() {
    int n;
    while(cin >> n) {
        vector<pair<int,int >> a(N);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second >> a[i].first;
        }
        sort(a.begin(),a.end());
        priority_queue<int,vector<int>,greater<int> > heap;
        for (auto p:a) {
            heap.push(p.second);
            if (heap.size() > p.first) heap.pop();
        }
        int res = 0;
        while (heap.size()) {
            res += heap.top();
            heap.pop();
        }
        cout << res << endl;

    }
    return 0;
}



