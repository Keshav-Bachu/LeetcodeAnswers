class Solution {
public:
    int reverse(int x) 
    {
        int sign = 1;
        long sum = 0;
        
        if(x < 0)
        {
            sign = sign * -1;
            x = x * -1;
        }
        
        
        
        cout << "Start\n";
        for(long incriment = 1; incriment <= x; incriment *= 10)
        {
            
            long temp = x/incriment;
            temp = temp % 10;
            //cout << temp << '\n';
            //cout << sum << '\n';
            sum = sum * 10 + temp;
            
        }
        
        if (sum > 2147483647)
            return 0;
        
        
        return sign * sum;
    }
};
