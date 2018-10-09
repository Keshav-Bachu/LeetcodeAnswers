#include iostream
#include algorythms
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> returner;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            calcPossibilities(returner, nums[i]);
        }
        for(int i = 0; i < returner.size(); i++)
        {
            if(returner[i].size() != 3)
            {
                returner.erase(returner.begin() + i);
                i--;
            }
            else if(returner[i][0] + returner[i][1] + returner[i][2] != 0)
            {
                returner.erase(returner.begin() + i);
                i--;
            }
        }
        return returner;
    }
    
    void calcPossibilities(vector<vector<int>> & combos, int num)
    {
        if(combos.size() == 0)
        {
            vector<int> temp;
            temp.push_back(num);
            combos.push_back(temp);
            return;
        }
        
        //combo of everything else
        else
        {
            int highVal = combos.size();
            for(int i = 0; i < highVal; i++)
            {
                vector<int> temp = combos[i];
                temp.push_back(num);
                combos.push_back(temp);
            }
            return;
        }
    }
};
