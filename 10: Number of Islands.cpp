class Solution {
public:
   
    void countIslands(vector<vector<char>>& grid, int xPos, int yPos)
    {
        //cout<<"done: " << xPos << ' ' << yPos << '\n';
        if(xPos < 0 || xPos >= grid.size())
        {
            //cout<<"found: " << xPos << ' '<< yPos<< "\n";
            return;
        }
        if(yPos >= grid[0].size() || yPos < 0)
        {
            return;
        }
        if(grid[xPos][yPos] == '0')
        {
            return;
        }
        grid[xPos][yPos] = '0';
        
        //cout<<"done: " << xPos << ' ' << yPos << '\n';
        countIslands(grid, xPos + 1, yPos);//move right
        countIslands(grid, xPos, yPos + 1);//move down
        countIslands(grid, xPos, yPos - 1);
        countIslands(grid, xPos - 1, yPos);
        //cout<<"\tdone: " << xPos << ' ' << yPos << '\n';
        /*
        
        if(xPos > 0 && grid[xPos - 1][yPos] == '1')
        {
            cout << "up X\n";
            countIslands(grid, xPos - 1, yPos);
        }
        if(yPos > 0 && grid[xPos][yPos - 1] == '1')
        {
            cout << "up Y\n";
            countIslands(grid, xPos, yPos - 1);
        }
        */
        
    
        return;
        
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int islands = 0;
        for(int xPos = 0; xPos < grid.size(); xPos++)
        {
            for(int yPos = 0; yPos < grid[0].size(); yPos++)
            {
                if(grid[xPos][yPos] == '1')
                {
                    //cout<<"entered \n";
                    islands++;
                    countIslands(grid, xPos, yPos);
                    
                }
            }
        }
        //cout << grid[0][0];
        return islands;
    }
};
