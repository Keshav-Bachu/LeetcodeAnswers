#include iostream
using namespace std;
class Solution {
int total_nums = 0;
int counter = 0;
vector <int> order;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //cout << matrix.size() << " size" << endl;
        
        if(matrix.size() == 0)
        {
            //cout << "WTF\n";
            return order;
        }
        
        total_nums = matrix.size() * matrix[0].size();
        counter = 0;
        matrix_return(matrix, 0, 0, 0);
        
        return order;
    }
    
    void matrix_return(vector<vector<int>>& matrix, int row, int col, int direction)
    {
        if(counter == total_nums)
        {
            return;
        }
        if(direction == 0) //move right
        {
            if(matrix[0].size() != col && matrix[row][col] != -1111)
            {
                int x = matrix[row][col];
                cout << x << ' ';
                counter++;
                matrix[row][col] = -1111;
                order.push_back(x);
                matrix_return(matrix, row, col + 1, 0);
            }
            else
            {
                matrix_return(matrix, row + 1, col - 1, 1);
            }
        }
        else if(direction == 1) //move down
        {
            if(matrix.size() != row && matrix[row][col] != -1111)
            {
                int x = matrix[row][col];
                cout << x << ' ';
                counter++;
                matrix[row][col] = -1111;
                order.push_back(x);
                matrix_return(matrix, row + 1, col, 1);
            }
            else
            {
                matrix_return(matrix, row - 1, col - 1, 2);
            }
        }
        else if(direction == 2) //move left
        {
            if(col != -1 && matrix[row][col] != -1111)
            {
                int x = matrix[row][col];
                cout << x << ' ';
                counter++;
                matrix[row][col] = -1111;
                order.push_back(x);
                //cout << endl << row << col << endl;
                matrix_return(matrix, row, col - 1, 2);
            }
            else
            {
                //cout << endl << row << col << endl;
                matrix_return(matrix, row - 1, col + 1, 3);
            }
        }
        else //move up, direction = 3
        {
            if(row != 0 && matrix[row][col] != -1111)
            {
                int x = matrix[row][col];
                cout << x << ' ';
                counter++;
                matrix[row][col] = -1111;
                order.push_back(x);
                matrix_return(matrix, row - 1, col, 3);
            }
            else
            {
                matrix_return(matrix, row + 1, col + 1, 0);
            }
        }
    }
};
