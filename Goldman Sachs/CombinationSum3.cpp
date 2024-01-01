// Problem: https://leetcode.com/problems/combination-sum-iii/

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. 
// The list must not contain the same combination twice, and the combinations may be returned in any order.

#include<bits/stdc++.h>
using namespace std;

void helper(int start, vector<int>&temp, vector<vector<int>>&ans, int k, int target){
    if(temp.size()>k){
        return;
    }

    if(target==0 && temp.size()==k){
        ans.push_back(temp);
        return;
    }


    for(int i=start; i<=9; i++){
        if(i>target){
            break;
        }
        temp.push_back(i);
        helper(i+1, temp, ans, k, target-i);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>temp;
    vector<vector<int>> ans;
    helper(1, temp, ans, k, n);
    return ans;
}

int main()
{
    return 0;
}