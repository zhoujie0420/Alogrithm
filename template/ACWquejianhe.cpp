//
// Created by ZhouJie on 2022/4/30 11:34.
//区间和

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
const int N = 10010;
int n;
vector<PII> segs;


void merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(),segs.end());

    int start = -2e9,end = -2e9;
    for(auto seg : segs)
        if(end < seg.first) {
            if(start != -2e9 ) res.push_back({start,end});
            start = seg.first,end = seg.second;
        }
        else end = max(end,seg.second);

        if(start != 2e9) res.push_back({start,end});
        segs = res;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int  l ,r;
        cin >> l  >> r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout << segs.size() << endl;

    return 0;
}