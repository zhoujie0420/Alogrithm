//
// Created by ZhouJie on 2022/7/14.
//

#include <bits/stdc++.h>
using namespace std;

const int N=300100;
deque<long long> q;
long long n,m,l,r,s[N],a[N],ans = -1e7;
int main()
{
    cin >> n >> m;
    q.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i){
        if(q.front() < i - m) q.pop_front();
        ans = max(ans,s[i] - s[q.front()]);
        while(q.size() && s[q.back()] >= s[i]) q.pop_back();
        q.push_back(i);

    }
    cout << ans;
    return 0;
}
