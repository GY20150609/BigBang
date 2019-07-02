//
// Created by yu2.guo on 2019/7/1.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#endif //LEETCODE_SOLUTION_H

#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int value):val(value),left(NULL),right(NULL){};
};

class Solution{
public:
    //Q1:给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
    //你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
    //输入: [1, 2, 2, 3, 1]
    //输出: 2
    //解释:输入数组的度是2，因为元素1和2的出现频数最大，均为2.最短连续子数组[2, 2]的长度为2，所以返回2.
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> counttable;
        map<int, int> firsttable;
        map<int, int> lasttable;
        int result, num, tmpmax = 0;
        int tmpmin = nums.size();
        vector<int>::iterator iter;
        for (iter = nums.begin(); iter < nums.end(); iter++) {

            if (counttable.count(*iter) == 0) {
                counttable.insert(pair<int, int>(*iter, 1));
                firsttable.insert(pair<int, int>(*iter, num));
                lasttable.insert(pair<int, int>(*iter, num));
            } else {
                counttable[*iter] = counttable[*iter] + 1;
                lasttable[*iter] = num;
            }
            if (counttable[*iter] >= tmpmax) {
                tmpmax = counttable[*iter];
            }
            num++;
        }
        map<int, int>::iterator itr = firsttable.begin();
        while (itr != firsttable.end()) {
            if (counttable[itr->first] == tmpmax) {
                if (lasttable[itr->first] - firsttable[itr->first] + 1 < tmpmin) {
                    tmpmin = lasttable[itr->first] - firsttable[itr->first] + 1;
                }
            }
            itr++;
        }
        return tmpmin;
    }
};
