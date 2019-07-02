//
// Created by yu2.guo on 2019/6/28.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    //Q1:找数组左边是否有重复元素
    //input: [1,3,1,2,1]
    //output：[-1,-1,0,-1,0]
    vector<int> isLeftUnique(vector<int> d){
        set<int> table;
        vector<int> result;
        if(d.size()==1){
            result.push_back(-1);
            return result;
        }
        for(int i =0;i<d.size();i++){
            if(table.count(d[i])==0){
                table.insert(d[i]);
                result.push_back(-1);
            }
            else{
                result.push_back(0);
            }
        }
        return result;
    };

    //Q2:判断当前数值第几次出现
    //input: [1,3,1,2,1]
    //output：[1,1,2,1,3]
    vector<int> isOcuerCount(vector<int> d){
        map<int,int> table;
        vector<int> result;
        if(d.size()==1){
            result.push_back(1);
            return result;
        }
        for(int i =0;i<d.size();i++){
            if(table.find(d[i])==table.end()){
                table[d[i]] = 1;
                result.push_back(1);
            }
            else{
                table[d[i]]++;
                result.push_back(table[d[i]]);
            }
        }
        return result;
    };

    //Q3:判断当前数值上次出现的位置
    //input: [1,3,1,2,1]
    //output：[-1,-1,0,-1,0]
    vector<int> lastOcuerIndex(vector<int> d){
        map<int,int> table;
        vector<int> result;
        if(d.size()==1){
            result.push_back(-1);
            return result;
        }
        for(int i =0;i<d.size();i++){
            if(table.count(d[i])==0){
                table.insert(pair<int, int>(d[i],i));
                result.push_back(-1);
                //table.insert(make_pair(d[i],i));
                //table.insert(map<int, int>::value_type (d[i],i));
            }
            else{
                result.push_back(table[d[i]]);
                table[d[i]] = i;
            }
        }
        return result;
    };

    //Q4:判断当前位置到上次出现位置中间数之和
    //input: [1,3,1,2,1]
    //output：[0,0,3,0,2]
    vector<int> lastOcuerSum(vector<int> d){
        map<int,int> table;
        vector<int> result;
        if(d.size()==1){
            result.push_back(0);
            return result;
        }
        for(int i =0;i<d.size();i++){
            if(table.count(d[i])==0){
                table.insert(pair<int, int>(d[i],i));
                result.push_back(0);
                //table.insert(make_pair(d[i],i));
                //table.insert(map<int, int>::value_type (d[i],i));
            }
            else{
                int sum = 0;
                for(int j=table[d[i]];j<=i;j++) {
                    sum = sum + d[j];
                }
                result.push_back(sum-2*d[i]);
                table[d[i]] = i;
            }
        }
        return result;
    };


};



#endif //LEETCODE_SOLUTION_H
