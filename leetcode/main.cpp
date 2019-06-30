#include <iostream>
#include "day01/Solution.h"

int main()
{
    Solution ss;
    vector<int> input = {2,2,2,2,2};
    vector<int> output1 = ss.isLeftUnique(input);
    vector<int> output2 = ss.isOcuerCount(input);
    vector<int> output3 = ss.lastOcuerIndex(input);
    vector<int> output4 = ss.lastOcuerSum(input);

    vector<int>::iterator iter;
    for(iter = output4.begin(); iter != output4.end(); iter++)
        cout  << *iter << endl;



    return 0;
}