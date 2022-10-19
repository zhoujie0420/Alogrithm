//
// Created by ZhouJie on 2022/5/23 22:30.
//

#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 11;
vector<int> nums;
bool flag[N];
void dfs(int u){
    if(u > n) {
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i) {
        if(!flag[i]) {
            nums.push_back(i);
            flag[i] = true;
            dfs(u+1);
            nums.pop_back();
            flag[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}