//
// Created by yu2.guo on 2019/6/30.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    //Q1：给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
    //你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
    //示例:
    //给定 nums = [2, 7, 11, 15], target = 9
    //因为 nums[0] + nums[1] = 2 + 7 = 9
    //所以返回 [0, 1]

    //S1：暴力解法 O(N^2) O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size()<2)
            return {-1,-1};
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                if(target-nums[i]==nums[j])
                    result = {i,j};
                else
                    result = {-1,-1};
        return result;
    };

    //S2：两遍遍历 O(N) O(N)
    vector<int> twoSumV2(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> table;
        if(nums.size()<2)
            return {-1,-1};
        for(int i=0;i<nums.size();i++)
            table[nums[i]] = i;
        for(int j=0;j<nums.size();j++)
            if(table.count(target-nums[j])!=0 && table[target-nums[j]]!=j){
                result = {j,table[target-nums[j]]};
            }
        return result;
    };

    //S3：一遍遍历 O(N) O(N)
    vector<int> twoSumV3(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        map<int,int> table;
        if(nums.size()<2) {
            return result;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(table.count(target-nums[i])>0){
                result[0] = table[target-nums[i]];
                result[1] = i;
                break;
            }
            table.insert(pair<int,int>(nums[i],i));
        }
        return result;
    };

    //Q2:数组中除自己以外的乘积和，不能用除法，空间复杂度O(1)
    //M1:暴力法
    vector<int> productExceptSelfV1(vector<int>& nums) {
        int leftResult = 1;
        int rightResult = 1;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            leftResult = multiply(nums,i,-1);
            rightResult = multiply(nums,i,1);
            result.push_back(leftResult*rightResult);
        }
        return result;
    };
    int multiply(vector<int>& nums,int indx,int mode){
        int result = 1;
        switch(mode){
            case 1:
                if(indx==nums.size())
                    result = 1;
                else
                    for(int i=indx+1;i<nums.size();i++){
                        result *= nums[i];
                    }
                break;
            case -1:
                if(indx==0)
                    result = 1;
                else
                    for(int i=0;i<indx;i++){
                        result *= nums[i];
                    }
                break;
        };
        return result;
    };
    // M2:时间复杂度O(N),空间复杂度O(3N)
    vector<int> productExceptSelfV2(vector<int>& nums) {
        vector<int> leftResult(nums.size(),-1);
        vector<int> rightResult(nums.size(),-1);
        vector<int> result;
        int left = 1;
        int right = 1;
        for (int i = 0; i <nums.size(); i++) {
            if(i==0){
                left = 1;
                right = 1;
            }
            else{
                right *= nums[nums.size()-i];
                left *= nums[i-1];
            }
            rightResult[nums.size()-i-1] = right;
            leftResult[i] = left;
        }
        for (int i = 0; i <nums.size(); i++) {
            result.push_back(leftResult[i]*rightResult[i]);
        }
        return result;
    };

    // M3:时间复杂度O(N),空间复杂度O(N)
    vector<int> productExceptSelfV3(vector<int>& nums) {
        vector<int> result(nums.size(),-1);
        int left = 1;
        int right = 1;
        for (int i = 0; i <nums.size(); i++) {
            if(i>0){
                right *= nums[nums.size()-i];
            }
            result[nums.size()-i-1] = right;
        }
        for (int i = 0; i <nums.size(); i++) {
            if(i>0){
                left *= nums[i-1];
            }
            result[i] = result[i]*left;
        }
        return result;
    };

    //Q3:数组中除自己以外计算方差
    vector<float> excepSelfSquare(vector<int>& nums) {
        vector<float> result;
        float leftResult = 0;
        float rightResult = 0;
        for (int i = 0; i < nums.size(); i++) {
            leftResult = square(nums,i,-1);
            rightResult = square(nums,i,1);
            result.push_back(leftResult+rightResult);
        }
        return result;
    };

    float square(vector<int>& nums,int indx,int mode){
        float avg;
        float result = 0.0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        avg = (sum - nums[indx])*1.0/(nums.size()-1);
        switch(mode){
            case 1:
                if(indx==nums.size())
                    result = 0;
                else
                    for(int i=indx+1;i<nums.size();i++){
                        result += pow((nums[i]-avg),2);
                    }
                break;
            case -1:
                if(indx==0)
                    result = 0;
                else
                    for(int i=0;i<indx;i++){
                        result += pow((nums[i]-avg),2);
                    }
                break;
        };
        return result;
    };


};

#endif //LEETCODE_SOLUTION_H
