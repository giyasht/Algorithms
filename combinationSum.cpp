class Solution {
public:
    
    void findCombination(int ind, int target, vector<int>&candidates, vector<vector<int>>&ans, vector<int>&ds) 
    {
        // base condition
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        
        //take 
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findCombination(ind, target-candidates[ind], candidates, ans, ds);
            ds.pop_back();
        }
        
        findCombination(ind+1, target, candidates, ans, ds);
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};