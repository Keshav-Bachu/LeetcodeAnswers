class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        //vector<int> maxDist;
        int max = 0;
        int max2 = 0;
        int height1;
        int height2;
        int countDist;
        int temp = 0;
        
        for(int count1 = 0; count1 < height.size(); count1++)
        {
            max = 0;
            //calculate max distance
            height1 = height[count1];
            if(count1 < height.size()/2)
            {
                for(int count2 = height.size() - 1; count2 >= 0; count2--)
                {
                    height2 = height[count2];
                    countDist = count1 - count2;

                    if(countDist < 0)
                    {
                        countDist = countDist * -1;
                    }


                    if(count1 != count2 && countDist > max && height2 >= height1)
                    {
                        max = countDist;
                        break;
                    }

                }
            }
            
            else
            {
                for(int count2 = 0; count2 < height.size(); count2++)
                {
                    height2 = height[count2];
                    if(height2 >= height1)
                    {

                        countDist = count1 - count2;

                        if(countDist < 0)
                        {
                            countDist = countDist * -1;
                        }


                        if(count1 != count2 && countDist > max)
                        {
                            max = countDist;
                            break;
                        }
                    }
                }
            }            
            //maxDist.push_back(max);
            temp = height1 * max;
            if(temp  > max2)
            {
                max2 = temp;
            }
        }
        
        return max2;
        //return 1;
        */
        
        
        int start = 0; 
        int end = height.size() - 1;
        int length;
        int max = 0;
        int height2;
        
        for(start = 0; start < end; start = start)
        {
            length =  end - start;
            
            if(height[start] < height[end])
            {
                height2 = height[start];
                start++;
            }
            else
            {
                height2 = height[end];
                end--;
            }
            
            cout << length;
            if(max < length * height2)
            {
                max = length * height2;
            }
        }
        
        return max;
        
    }
};
