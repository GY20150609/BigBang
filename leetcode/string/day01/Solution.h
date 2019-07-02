//
// Created by yu2.guo on 2019/7/2.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#endif //LEETCODE_SOLUTION_H

#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int n = s.size();
        set<char> table;
        int tmpMaxLen = 0;
        int i = 0;
        int j = 0;
        while(i<n && j<n){
            if(table.count(s[j])==0){
                table.insert(s[j++]);
                tmpMaxLen = max(tmpMaxLen,j-i);
            }
            else{
                table.erase(s[i++]);
            }
        }
        return tmpMaxLen;
    };

};
