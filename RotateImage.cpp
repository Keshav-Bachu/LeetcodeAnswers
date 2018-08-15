#include vector
#include iostream
using namespace std;
class Solution {
public:
    int finalPos = 0;
    void rotate(vector<vector<int>>& matrix) {
        finalPos = matrix.size();
        returnLocations(matrix, 0, 0);
    }
    
    void returnLocations(vector<vector<int>>& matrix, int row, int col)
    {
        if(row >= finalPos)
        {
            return;
        }
        
        int holdVal = matrix[row][col];
        int newROW = col;
        int newCOL = finalPos - 1 - row;;
        //cout << row << ' ' << col << endl;
        
        newXY(row, col);
        returnLocations(matrix, row, col);
        matrix[newROW][newCOL] = holdVal;
        
    }
    
    
    void newXY(int & row, int & col)
    {
        if(col < finalPos - 1)
        {
            col++;
            //y stays the same
        }
        else
        {
            col = 0;
            row++;
        }
    }
};
