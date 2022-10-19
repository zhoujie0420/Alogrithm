//
// Created by ZhouJie on 2022/5/23 22:15.
//

#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<int> nums;

void dfs(int u){
    if( nums.size() > m || n-u+1 + nums.size() < m) return;
    if(u == n+1) {
        for (int i = 0; i < nums.size(); ++i)
            cout << nums[i] << " " ;

        cout << endl;
        return ;
    }
    nums.push_back(u);
    dfs(u+1);
    nums.pop_back();
    dfs(u+1);
}
int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}