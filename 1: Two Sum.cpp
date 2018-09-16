using namespace std;
class Solution {
public:
    int pos1;
    int pos2;
    vector<int> twoSum(vector<int>& nums, int target) {
        
        pos1 = 0;
        pos2 = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(checkAll(nums, target, i))
            {
                break;
            }
        }
        
        vector<int> returner;
        returner.push_back(pos1);
        returner.push_back(pos2);
        return returner;
    }
    
    bool checkAll(vector<int>& nums, int target, int currentPos)
    {
        for(int i = currentPos + 1; i < nums.size(); i++)
        {
            if(nums[currentPos] + nums[i] == target)
            {
                pos1 = currentPos;
                pos2 = i;
                return true;
            }
        }
        return false;
    }
    
};
