class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        
        // Step 1: Count frequency
        for (int x : nums) count[x]++;
        
        // Step 2: Prefix sum
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }
        
        // Step 3: Build answer
        vector<int> ans;
        for (int x : nums) {
            if (x == 0) ans.push_back(0);
            else ans.push_back(count[x - 1]);
        }
        
        return ans;
    }
};