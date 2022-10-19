//
// Created by ZhouJie on 2022/5/10 14:17.
//给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。
//
//现在，请你按照字典序将所有的排列方法输出。
//
//输入格式
//共一行，包含一个整数 n。
//
//输出格式
//按字典序输出所有排列方案，每个方案占一行。
//
//数据范围
//1≤n≤7

/*
#include <bits/stdc++.h>

using namespace std;
const int N = 10006;
int n;
int  path[N];
bool flag[N];

void dfs(int u){
    if(u == n){
        for (int i = 0; i < n; ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
        for (int i = 1; i <= n ; ++i) {
            if(!flag[i]){
                path[u] = i;
                flag[i] = true;
                dfs(u+1);
               // path[u] = 0;        //恢复现场，可以删除 因为上面已经进行了迭代
                flag[i] = false;    //恢复现场
            }
        }

}
int main() {
    cin >> n;

    dfs(0);

    return 0;
}

 */
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

/*
#include <bits/stdc++.h>

using namespace std;
const int N = 10006;

int n;
bool col[N] , dg[N] ,udg[N];
char g[N][N];

void dfs(int u){
    if( u == n){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << g[i][j] << ' ';
            }    cout << endl;
        }

        return ;
    }

    for (int i = 0; i < n; ++i) {
        if(!col[i] && !dg[i+u] && !udg[n-u+i]){
            g[u][i] = 'Q';
            col[i] = dg[i+u] = udg[n-u+i] = true;
            dfs(u+1);
            col[i] = dg[i+u] = udg[n-u+i] = false;
            g[u][i] = '.';
        }
    }
}

int main(){

    cin >> n;
    if(n==1) {cout << 'Q' ;
        return 0;}
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
 */
//方法二


#include <bits/stdc++.h>

using namespace std;
const int N = 10006;

int n;
bool col[N] , row[N], dg[N] ,udg[N];
char g[N][N];

void dfs(int x,int y,int s){

    if(y == n) {
        y = 0;
        x++;
    }
    if(x == n){
        if(s == n) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << g[i][j] ;
                }
                cout << endl;
            }
            cout << endl;
        }
        return ;
    }
    //不放皇后
    dfs(x,y+1,s);

    //放皇后
    if(!row[x] && !col[y] && !dg[x+y] && !udg[x-y+n]){
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = true;
        dfs(x,y+1,s+1);
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = false;
        g[x][y] = '.';
    }
}

int main(){

    cin >> n;
    if(n==1) {
        cout << 'Q' ;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = '.';
        }
    }
    dfs(0,0,0);
    return 0;
}