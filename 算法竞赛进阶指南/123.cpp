//
// Created by ZhouJie on 2022/7/13.
//格格兰郡的 N 名士兵随机散落在全郡各地。
//
//格格兰郡中的位置由一对 (x,y) 整数坐标表示。
//
//士兵可以进行移动，每次移动，一名士兵可以向上，向下，向左或向右移动一个单位（因此，他的 x 或 y 坐标也将加 1 或减 1）。
//
//现在希望通过移动士兵，使得所有士兵彼此相邻的处于同一条水平线内，即所有士兵的 y 坐标相同并且 x 坐标相邻。
//
//请你计算满足要求的情况下，所有士兵的总移动次数最少是多少。
//
//需注意，两个或多个士兵不能占据同一个位置。
//
//输入格式
//第一行输入整数 N，代表士兵的数量。
//
//接下来的 N 行，每行输入两个整数 x 和 y，分别代表一个士兵所在位置的 x 坐标和 y 坐标，第 i 行即为第 i 个士兵的坐标 (x[i],y[i])。
//
//输出格式
//输出一个整数，代表所有士兵的总移动次数的最小值。
//
//数据范围
//1≤N≤10000,
//−10000≤x[i],y[i]≤10000
//输入样例：
//5
//1 2
//2 2
//1 3
//3 -2
//3 3
//输出样例：
//8

#include <bits/stdc++.h>

using namespace std;
int x[100010], y[100010];
int n;
int res = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }
    sort(y,y+n);
    int ymid = y[n>>1];
    for (int i = 0; i < n; ++i){
        res += abs(y[i]-ymid);
    }

    sort(x,x+n);
    for (int i = 0; i < n; ++i){
        x[i] -= i;
    }
    sort(x,x+n);
    int xmid = x[n>>1];
    for (int i = 0; i < n; ++i){
        res+= abs(x[i] - xmid);
    }

    cout << res;
    return 0;
}