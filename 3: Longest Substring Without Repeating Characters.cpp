class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        int greatest = 0;
        int counter;
        string s1 = s;
        std::vector <int> v(300);
        int manipulate;
        
        for(int count = 0; count < s1.length(); count++)
        {
            std::fill(v.begin(), v.end(), 0);
            counter = 0;
            
            for(int count2 = count; count2 < s1.size();count2++)
            {
                manipulate = s[count2];
                if(v[manipulate] == 1)
                {
                    break;
                }
                
                else
                {
                    v[manipulate] = 1;
                }
                counter++;
                //cout<< counter << '\n';
            }
            if(greatest < counter)
            {
                greatest = counter;
            }
        }
        
        return greatest;
    }
};
