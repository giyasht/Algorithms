// 40. Combination Sum II
#include<bits/stdc++.h>
using namespace std;

// each number only be used once
void solve(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int index){

    if(target == 0){
        ans.push_back(temp);
        return;
    }

    if(target < 0 || index >= candidates.size())
        return;

    // for loop already excludes calls 
    for(int i = index; i < candidates.size(); i++){
        
        if(i > index && candidates[i] == candidates[i-1])
            continue;

        if(candidates[i] > target)
            break;
        // Include
        temp.push_back(candidates[i]);
        solve(candidates, target-candidates[i], ans, temp, i+1);

        // vector<int> &temp used by reference therefore pop_back should be used (memory efficient)
        // without &temp no need to pop_back 
        temp.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    int index = 0;
    solve(candidates, target, ans, temp, index);
    return ans;
}

int main(){

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates, target);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}