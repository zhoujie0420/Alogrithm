//
// Created by ZhouJie on 2022/7/1.
//“飞行员兄弟”这个游戏，需要玩家顺利的打开一个拥有 16 个把手的冰箱。
//
//已知每个把手可以处于以下两种状态之一：打开或关闭。
//
//只有当所有把手都打开时，冰箱才会打开。
//
//把手可以表示为一个 4×4 的矩阵，您可以改变任何一个位置 [i,j] 上把手的状态。
//
//但是，这也会使得第 i 行和第 j 列上的所有把手的状态也随着改变。
//
//请你求出打开冰箱所需的切换把手的次数最小值是多少。
//
//输入格式
//输入一共包含四行，每行包含四个把手的初始状态。
//
//符号 + 表示把手处于闭合状态，而符号 - 表示把手处于打开状态。
//
//至少一个手柄的初始状态是关闭的。
//
//输出格式
//第一行输出一个整数 N，表示所需的最小切换把手次数。
//
//接下来 N 行描述切换顺序，每行输出两个整数，代表被切换状态的把手的行号和列号，数字之间用空格隔开。
//
//注意：如果存在多种打开冰箱的方式，则按照优先级整体从上到下，同行从左到右打开。
//
//数据范围
//1≤i,j≤4
//输入样例：
//-+--
//----
//----
//-+--
//输出样例：
//6
//1 1
//1 3
//1 4
//4 1
//4 3
//4 4

#include <bits/stdc++.h>

using namespace std;
char p[4][4] ;
vector<pair<int,int>> ans, tmp;
void turnone(int x,int y){
    if(p[x][y] == '+') p[x][y] = '-';
    else p[x][y] = '+';
}
void turnall (int x,int y){
    for (int i = 0; i < 4; ++i) {
        turnone(i,y);
        turnone(x,i);
    }
    turnone(x,y);
}
void dfs(int x, int y ){

    if(x == 3 && y == 4){
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if(p[i][j] == '+') return ;
            }
        }

        if(ans.empty() || ans.size() > tmp.size())
            ans = tmp;

        return;
    }

    if(y == 4) {
        x++;
        y = 0;
    }
    //操作
    turnall(x,y);
    tmp.push_back({x,y});
    dfs(x,y+1);
    tmp.pop_back();
    turnall(x,y);

    //不操作
    dfs(x,y+1);
}
int main() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> p[i][j];
        }
    }
    dfs(0,0);


    cout << ans.size() << endl;
    for (const auto &item: ans){
        cout << item.first+1 << " " << item.second+1 << endl;
    }
    return 0;
}