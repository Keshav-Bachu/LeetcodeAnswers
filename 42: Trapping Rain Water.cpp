#include algorythm
#include iostream
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int level = -1;
        int contained = 0;
        //cout << left << ' ' << right << endl;
        //cout << "________" << "NA" << ' ' << level << endl;
        while(left < right)
        {
            int lower  = -1;
            if(height[left] < height[right])
            {
                lower = height[left];
                left++;
            }
            else
            {
                lower = height[right];
                right--;
            }
            level = max(level, lower);
            //cout << left << ' ' << right << endl;
            //cout << "________" << lower << ' ' << level << endl;
            contained += level - lower;
        }
        return contained;
    }
};
