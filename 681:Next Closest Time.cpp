class Solution {
public:
    vector <int> timeSets;
    string nextClosestTime(string time) {
        //convert to all ints
        vector <int> valAvailable;
        valAvailable.push_back((int)(time[0] - '0'));
        valAvailable.push_back((int)(time[1] - '0'));
        valAvailable.push_back((int)(time[3] - '0'));
        valAvailable.push_back((int)(time[4] - '0'));
        int origVal = 1000*valAvailable[0] + 100*valAvailable[1] + 10*valAvailable[2] + valAvailable[3];
        
        vector <int> empty;
        allCombos(valAvailable, 0, empty);
        
        sort(timeSets.begin(), timeSets.end());
        vector <int> :: iterator midVal = find(timeSets.begin(), timeSets.end(), origVal);
        while(*midVal == origVal)
        {
            midVal++;
            if(midVal == timeSets.end())
            {
                return time;
            }
        }
        
        while(*midVal != origVal)
        {
            //cout << *midVal << endl;
            if(checkVal(*(midVal)))
            {
                break;
            }
            midVal++;
            if(midVal == timeSets.end())
            {
                midVal = timeSets.begin();
            }
        }
        
        
        
        
        return convIntString(*midVal);
    }
    
     string convIntString(int newTime)
    {
        cout << newTime;
        string Temp = to_string(newTime);
        while(Temp.size() < 4)
        {
            Temp.insert(0, "0");
        }
        Temp.insert(2, ":");
        return Temp;
    }
    
    bool checkVal(int newTime)
    {
        int thousandth =  newTime / 1000;
        int hundredth = newTime % 1000;
        hundredth = hundredth / 100;
        int tenth = newTime % 100;
        tenth = tenth / 10;
        int ones = newTime % 10;
        
        //need to check if valid time
        if(thousandth > 2)
        {
            return false;
        }
        if(thousandth == 2 && hundredth > 4)
        {
            return false;
        }
        if(tenth > 5)
        {
            return false;
        }
        return true;
    }
    
    void allCombos(vector <int> & valAvailable, int termOn, vector <int> currUsed)
    {
        if(termOn == 4) //max digits for time
        {
            //convert to an int
            int timeStamp = 1000*currUsed[0] + 100*currUsed[1] + 10*currUsed[2] + currUsed[3];
            timeSets.push_back(timeStamp);
            return;
        }
        
        for(int i = 0; i < valAvailable.size(); i++)
        {
            vector <int> adding = currUsed;
            adding.push_back(valAvailable[i]);
            allCombos(valAvailable, termOn + 1, adding);
        }
    }
};
