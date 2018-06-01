class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<vector<int>> result;
        vector<int> tmp;
        help(candidates,target,res,tmp,0);
        set<vector<int>> s;
        for(int i=0;i<res.size();i++)
        {
            sort(res[i].begin(),res[i].end());
            s.insert(res[i]);
        }
        for(auto se:s)
        {
            result.push_back(se);
        }
        return result;
    }
    
    void help(vector<int>& candidates, int target,vector<vector<int>>& res,vector<int>& tmp,int j)
    {
        if(target==0)
        {
            res.push_back(tmp);
            return;
        }
        
        for(int i=j;i<candidates.size() && target>=candidates[i];i++)
        {
            tmp.push_back(candidates[i]);
            help(candidates,target-candidates[i],res,tmp,i+1);
            tmp.pop_back();
        }
    }
};
