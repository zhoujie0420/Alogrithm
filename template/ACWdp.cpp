//
// Created by ZhouJie on 2022/8/10 14:07.
//有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
//
//第 i 件物品的体积是 vi，价值是 wi。
//
//求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
//输出最大价值。
//
//输入格式
//第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
//
//接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
//
//输出格式
//输出一个整数，表示最大价值。
//
//数据范围
//0<N,V≤1000
//0<vi,wi≤1000
//输入样例
//4 5
//1 2
//2 4
//3 4
//4 5
//输出样例：
////8
//#include <bits/stdc++.h>
//
//using namespace std;
//const int N = 1010;
//int v[N],w[N];
//int f[N][N];
//int main() {
//    int res;
//    int n,m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i] ;
//    for (int i = 1; i <= n; ++i)
//        for (int j = 0; j <= m; ++j) {
//            f[i][j] = f[i-1][j];
//            if(j >= v[i]) f[i][j] = max(f[i][j],f[i-1][j-v[i]] + w[i]);
//        }
//    cout << f[n][m] << endl;
//
//    return 0;
//}
//898. 数字三角形
//   题目
//   提交记录
//   讨论
//   题解
//   视频讲解
//
//给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。
//
//        7
//      3   8
//    8   1   0
//  2   7   4   4
//4   5   2   6   5
//输入格式
//第一行包含整数 n，表示数字三角形的层数。
//
//接下来 n 行，每行包含若干整数，其中第 i 行表示数字三角形第 i 层包含的整数。
//
//输出格式
//输出一个整数，表示最大的路径数字和。
//
//数据范围
//1≤n≤500,
//−10000≤三角形中的整数≤10000
//输入样例：
//5
//7
//3 8
//8 1 0
//2 7 4 4
//4 5 2 6 5
//输出样例：
//30
//#include <bits/stdc++.h>
//
//using namespace std;
//const int N = 510;
//int v[N],w[N];
//int f[N][N];
//int res[N][N];
//int n;
//int main() {
//    cin >> n;
//    for(int i = 1;i <= n;++i)
//        for (int j = 1; j <= i ; ++j) cin >> f[i][j];
//
//
//    memset(res,-0x3f3f3f3f,sizeof res);
//
//    res[1][1] = f[1][1];
//    for (int i = 2; i <= n ; ++i) {
//        for (int j = 1; j <= i ; ++j) {
//            res[i][j] = max(res[i-1][j],res[i-1][j-1]) + f[i][j];
//        }
//    }
//
//    int ans =-0x3f3f3f3f;
//    for(int i = 1;i <= n;++i) ans = max(ans,res[n][i]);
//    cout << ans;
//    return 0;
//}



//给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。
//
//输入格式
//第一行包含整数 N。
//
//第二行包含 N 个整数，表示完整序列。
//
//输出格式
//输出一个整数，表示最大长度。
//
//数据范围
//1≤N≤1000，
//−109≤数列中的数≤109
//输入样例：
//7
//3 1 2 1 8 5 6
//输出样例：
//4
//
//#include <bits/stdc++.h>
//
//using namespace std;
//const int N = 1010;
//int a[N],f[N];
//int n;
//vector<int> st;
//int main() {
//
//    cin >> n;
//    for(int i = 0;i < n;++i) {
//        cin >> a[i];
//
//    }
//    st.push_back(a[0]);
//    for (int i = 1; i < n;   ++i) {
//        if(a[i] > st.back()){
//            st.push_back(a[i]);
//        }else
//            *lower_bound(st.begin(),st.end(),a[i]) = a[i];
//
//    }
//
//    cout << st.size();
//    return 0;
//}



//给定两个长度分别为 N 和 M 的字符串 A 和 B，求既是 A 的子序列又是 B 的子序列的字符串长度最长是多少。
//
//输入格式
//第一行包含两个整数 N 和 M。
//
//第二行包含一个长度为 N 的字符串，表示字符串 A。
//
//第三行包含一个长度为 M 的字符串，表示字符串 B。
//
//字符串均由小写字母构成。
//
//输出格式
//输出一个整数，表示最大长度。
//
//数据范围
//1≤N,M≤1000
//输入样例：
//4 5
//acbd
//abedc
//输出样例：
//3


#include <bits/stdc++.h>

using namespace std;
const int N = 1010;
char a[N],b[N];
int f[N][N];

int n,m;
vector<int> st;
int main() {

    cin >> n >> m;
    for (int i = 1;i <= n;++i)  cin >> a[i];
    for (int i = 1; i <= m ; ++i)  cin >> b[i];



    for (int i = 1; i <= n;   ++i)
        for (int j = 1; j <= m ; ++j) {
            f[i][j] = max(f[i][j-1],f[i-1][j]);
            if(a[i] == b[j]) f[i][j]=max(f[i][j] , f[i-1][j-1] +1);
        }

    cout << f[n][m];
    return 0;
}
