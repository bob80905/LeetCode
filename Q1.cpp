class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> u;
        vector<int> ret;
        for(unsigned int i = 0; i < nums.size(); i++){
            u.insert(make_pair(nums[i], i));
        }
        for(unsigned int i = 0; i < nums.size(); i++){
            std::unordered_map<int, int>::iterator it = u.find(target-nums[i]);
            if(it != u.end() && it->second != i){
                ret.push_back(i);
                ret.push_back(it->second);
                return ret;
            }
        }
        return ret;
    }
};