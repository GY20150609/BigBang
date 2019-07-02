//
// Created by yu2.guo on 2019/7/2.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#endif //LEETCODE_SOLUTION_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution{
public:
    //Q1：在一排座位（ seats）中，1 代表有人坐在座位上，0 代表座位上是空的。
    //至少有一个空座位，且至少有一人坐在座位上。
    //亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。
    //返回他到离他最近的人的最大距离。
    //
    //示例 1：
    //输入：[1,0,0,0,1,0,1]
    //输出：2
    int maxDistToClosest(vector<int> &seats){
        int tmpMax = 0;
        int lptr = 0;
        int rptr = 0;
        int isl = 0;
        int isr = 0;
        vector<int> leftIndx(seats.size(),-1);
        vector<int> rightIndx(seats.size(),-1);
        for(int i=0;i<seats.size();i++){
            if(seats[i]==0 && isl>0){
                    lptr++;
            }
            if(seats[i]==1){
                lptr = 0;
                isl++;
            }
            if(seats[seats.size()-i-1]==0 && isr>0){
                    rptr++;
            }
            if(seats[seats.size()-i-1]==1){
                rptr = 0;
                isr++;
            }
            leftIndx[i] = lptr;
            rightIndx[seats.size()-i-1] = rptr;
        }
        for(int i=0;i<seats.size();i++){
            if(leftIndx[i] == 0 || rightIndx[i] == 0){
                tmpMax = max(leftIndx[i],rightIndx[i])>tmpMax?max(leftIndx[i],rightIndx[i]):tmpMax;
            }
            else{
                tmpMax = min(leftIndx[i],rightIndx[i])>tmpMax?min(leftIndx[i],rightIndx[i]):tmpMax;
            }
        }
        return tmpMax;

    }
};