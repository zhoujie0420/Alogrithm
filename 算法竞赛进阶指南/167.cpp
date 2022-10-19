//
// Created by ZhouJie on 2022/7/22.
//

#include <bits/stdc++.h>

using namespace std;
const int N = 70;
int n;
int sum;
int length;
int sticks[N];
bool st[N];


bool dfs(int u, int cur,int start) {
    if (u * length == sum) return true;
    if (cur == length) return dfs(u + 1, 0, 0);

    for (int i = start; i < n; ++i) {
        if (st[i]) continue;
        int l = sticks[i];
        if (cur + l <= length) {
            st[i] = true;
            if (dfs(u, cur + l, i + 1)) return true;
            st[i] = false;


            // 剪枝3 如果是第一个木棒失败，则一定失败
            if (!cur) return false;

            // 剪枝4 如果是最后一个木棒失败，则一定失败
            if (cur + l == length) return false;

            // 剪枝2 跳过相同木棒
            int j = i;
            while (j < n && sticks[j] == l) j++;
            i = j - 1;
        }
    }
    return false;
}
int main() {
    while(cin >> n,n){
        sum = 0;
        length = 0;
        memset(st,false,sizeof st);

        for (int i = 0; i < n; ++i){
            cin >> sticks[i];
            sum += sticks[i];
            length = max(length,sticks[i]);
        }

        sort(sticks,sticks+n, cmp);

        while(true){
            if(sum%length == 0 && dfs(0,0,0)){
                cout << length << endl;
                break;
            }
            length++;
        }
    }
    return 0;
}