//
// Created by ZhouJie on 2022/7/20.
//

#include <bits/stdc++.h>

using namespace std;
const int N = 10010;
int n,m;
int son[N][26];
int idx = 0;
int cnt[N];
int main() {
    cin >> n >> m;
    while(n--){
        string s;
        cin >> s;
        int p = 0;
        for (const auto &item: s){
            int u = item - 'a';
            if(son[p][u] == 0) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p] ++;
    }
    while(m--){
        string s;
        cin >> s;
        int q = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int u = s[i] - 'a'; q = son[q][u];
            if (q == 0) {
             cout << ans << endl;
                continue;
            }
            ans += cnt[q];
        }
        cout << ans << endl;

}
    return 0;}