class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int diff = Integer.MAX_VALUE;
        int l = 0, r = 0, res = 0, sum = 0;
        for(int i = 0; i < nums.length - 2; i++) {
            l = i + 1;
            r = nums.length - 1;

            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];

                if(sum == target)
                    return sum;

                int tdiff = Math.abs(sum - target);

                if(tdiff < diff) {
                    diff = tdiff;
                    res = sum;                                                     
                }
                else if (sum > target){ 
                    r--;                   
                }
                else {
                    l++;                   
                }

            }
        }

        return res;
    }
}