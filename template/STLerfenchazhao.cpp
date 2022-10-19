//
// Created by ZhouJie on 2022/4/28.
//
#include "bits/stdc++.h"
using namespace std;
int main(){
    vector<int> a= {1,2,3,3,3,4};
    cout << binary_search(a.begin(),a.end(),9) <<endl; //是否存在val

    cout << *lower_bound(a.begin(),a.end(),1) << endl;
    //范围整个数组,指向下标最小的 大于等于val的元素

    cout << *upper_bound(a.begin(),a.end(),1) << endl;
    //范围整个数组,指向下标最小的 大于val的元素

    cout << *equal_range(a.begin(),a.end(),2) << endl;
}
