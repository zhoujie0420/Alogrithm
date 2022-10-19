//
// Created by ZhouJie on 2022/5/18 8:59.
//n−皇后问题是指将 n 个皇后放在 n×n 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。
//
//1_597ec77c49-8-queens.png
//
//现在给定整数 n，请你输出所有的满足条件的棋子摆法。
//
//输入格式
//共一行，包含整数 n。
//
//输出格式
//每个解决方案占 n 行，每行输出一个长度为 n 的字符串，用来表示完整的棋盘状态。
//
//其中 . 表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。
//
//每个方案输出完成后，输出一个空行。
//
//注意：行末不能有多余空格。
//
//输出方案的顺序任意，只要不重复且没有遗漏即可。
//
//数据范围
//1≤n≤9
//输入样例：
//4
//输出样例：
//.Q..
//...Q
//Q...
//..Q.
//
//..Q.
//Q...
//...Q
//.Q..

#include <bits/stdc++.h>

using namespace std;
const int N = 11;
char mp[N][N];
bool col[N] , dg[N] , udg[N] ; //标记棋盘  其中col表示横向  dg表示 y = x 轴  udg表示 y = x + n 轴
int n; // 输入的棋盘边长


void dfs(int u){
    if( u == n) {      //输出棋盘内容
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << mp[i][j] ;
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n ; ++i) {
        if(!col[i] && !dg[i+u] && !udg[n-u+i]){
            mp[u][i] = 'Q';

            col[i] = dg[i+u] = udg[n-u+i] = true;

            dfs(u+1);

            col[i] = dg[i+u] = udg[n-u+i] = false;

            mp[u][i] = '.';
            }
        }
    }




int main() {
    cin >> n;
    if(n==1) {cout << 'Q' ;
        return 0;}
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mp[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}