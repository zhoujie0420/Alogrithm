//
// Created by ZhouJie on 2022/5/20 9:12.
//

#include <bits/stdc++.h>

using namespace std;



int main() {
   vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << endl;

    }
    return 0;
}
