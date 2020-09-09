#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum{};
        int s = mat.size();
        bool isEven = s%2 == 0;
        int m = s/2 - (isEven ? 1: 0);
        int j{};
        for(int i{}; i <= m; i++) {
                if(i == m && j == m && !isEven){
                    sum += mat[i][j];
                }
                else {
                    sum += mat[i][j];
                    sum += mat[i][s-j-1];
                                     
                    sum += mat[s-i-1][j];
                    sum += mat[s-i-1][s-j-1];
                }
                j++;
        }
        return sum;
    }  
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<vector<int>> input =  {{1,2,3},{4,5,6},{7,8,9}};
    //vector<vector<int>> input =  {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}}; 
    //vector<vector<int>> input = {{6,3,1,10,7,4},{4,10,1,9,5,10},{5,5,7,3,8,5},{2,7,6,4,7,6},{7,9,6,1,8,5},{1,7,9,5,8,4}};

    int output; 
    output = s.diagonalSum(input);
}