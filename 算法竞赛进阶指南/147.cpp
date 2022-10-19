//
// Created by ZhouJie on 2022/7/21.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<LL,int > PII;
const int N  = 100010;
int lf[N],ri[N];
int n,k;
LL d[N];

void delete_node (int p) {
    ri[lf[p]] = ri[p];
    lf[ri[p]] = lf[p];
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)  cin >> d[i];
    for(int i = n-1;i;i--) d[i] -= d[i-1];
    set<PII> st;
    d[0] = d[n] = INT_MAX;

    for (int i = 0; i <= n ; ++i){
        lf[i] = i-1;
        ri[i] = i+1;
        st.insert({d[i],i});
    }
    LL res = 0;
    while(k--){
        auto it = st.begin();
        LL v = it->first;
        int p = it->second;
        int left = lf[p],right = ri[p];

        st.erase(it);
        st.erase({d[left],left});
        st.erase({d[right],right});
        delete_node(left), delete_node(right);
        res += v;
        d[p] = d[left] + d[right] - d[p];
        st.insert({d[p], p});
    }
        cout << res;
    return 0;
}