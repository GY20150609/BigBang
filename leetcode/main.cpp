#include <iostream>
#include <vector>
#include "day03/Solution.h"

using namespace std;

int main()
{
    Solution ss;
    Node Head(1);
    Node Head1(2);
    Node Head2(3);
    Node Head3(4);
    Node Head4(5);
    Node Head5(6);
    Node Head6(7);

    Head.left = &Head1;
    Head.right = &Head2;
    Head.left->left = &Head3;
    Head.left->right = &Head4;
    Head.right->left = &Head5;
    Head.right->right = &Head6;
    //vector<int> input = {1};
    //vector<float> output = ss.excepSelfSquare(input);
    //vector<float>::iterator iter;
    //ss.displayTree(Head);
    /*
    for(iter = output.begin(); iter != output.end(); iter++)
       cout  << *iter << endl;
    */
    //cout << 0%input.size() << endl;



    return 0;
}