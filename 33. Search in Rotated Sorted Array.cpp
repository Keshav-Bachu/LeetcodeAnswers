#include iostream
using namespace std;
class Solution {
public:
    int t = -1;
    int L = -1;
    bool found = false;
    int search(vector<int>& nums, int target) {
        t = target;
        if(nums.size() == 0)
        {
            return -1;
        }
        mergeSort(nums);
        if(found == false)
        {
            return -1;
        }
        return L;
    }



    void mergeSort(vector<int> nums)
    {
        int len = nums.size();
        
        if(len == 1){
            
            cout << nums[0] << endl;
            if(found == false){
                L++;
                if(t == nums[0])
                {
                    found = true;
                }
            }
            
            return;
        }

        vector<int> left(nums.begin(), nums.begin() + len/2);
        vector<int> right(nums.begin() + len/2, nums.end());
        mergeSort(left);
        mergeSort(right);
        
        

    }
};
