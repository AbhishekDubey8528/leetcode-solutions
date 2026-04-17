class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
       for(int i = 0; i < nums.size(); i++){
        mp[nums[i]]++;
       }
        int key = -1, value = -1;
       for(auto it : mp){
        int currkey = it.first;
        int currvalue = it.second;

        if(currvalue > value){
            key = currkey;
            value = currvalue;
        }
       }
        return key;
        
    }
};