//
// Created by ZhouJie on 2022/6/7.
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
//
//数据范围
//−109≤x≤109,
//1≤n,m≤105,
//−109≤l≤r≤109,
//−10000≤c≤10000
//输入样例：
//3 3
//1 2
//3 6
//7 5
//1 3
//4 6
//7 8
//输出样例：
//8
//0
//5

#include <bits/stdc++.h>

using namespace std;
const int N  = 300010;
int n, m;
int a[N];//存储坐标插入的值
int s[N];//存储数组a的前缀和
vector<int> alls;  //存储（所有与插入和查询有关的）坐标
vector<pair<int, int>> add, query; //存储插入和询问操作的数据
int find(int x) { //返回的是输入的坐标的离散化下标
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        int l , r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    //排序，去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    //执行前n次插入操作
    for (auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= alls.size(); i++) s[i] = s[i-1] + a[i];
    //处理后m次询问操作
    for (auto item : query) {
        int l = find(item.first);
        int r = find(item.second);
        printf("%d\n", s[r] - s[l-1]);
    }
    return 0;
}