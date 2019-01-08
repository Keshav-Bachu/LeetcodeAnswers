class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxTotal = nums[0], maxTemp = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            int temp = maxTemp + nums[i];
            //option of adding something to itself or 0
            maxTemp = max(nums[i], temp);
            if(maxTemp > maxTotal)
            {
                maxTotal = maxTemp;
            }
            //cout << maxTemp << endl;
        }
        return maxTotal;
        
    }
};
