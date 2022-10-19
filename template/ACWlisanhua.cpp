//
// Created by ZhouJie on 2022/4/30 10:41.
//离散化

#include <bits/stdc++.h>

using namespace std;
typedef std::pair<int,int> PII;

const int N = 310000;
int n , m;
int a[N],s[N];

vector<int> alls;
vector<PII>add,query;



int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x,c;
        cin >> x >> c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int l , r ;
        cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);

    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    for(auto item:add){
        int x = lower_bound(alls.begin(),alls.end(),item.first)-alls.begin();
        a[x] +=item.second;
    }
    for (int i = 1 ; i < alls.size(); ++i) {
        s[i] = s[i-1] +a[i];
    }
    for(auto item:query){
        int l = lower_bound(alls.begin(),alls.end(),item.first)-alls.begin();
        int r = lower_bound(alls.begin(), alls.end(), item.first) - alls.begin();
        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}

//假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。
//
//现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c。
//
//接下来，进行 m 次询问，每个询问包含两个整数 l 和 r，你需要求出在区间 [l,r] 之间的所有数的和。
//
//输入格式
//第一行包含两个整数 n 和 m。
//
//接下来 n 行，每行包含两个整数 x 和 c。
//
//再接下来 m 行，每行包含两个整数 l 和 r。
//
//输出格式
//共 m 行，每行输出一个询问中所求的区间内数字和。