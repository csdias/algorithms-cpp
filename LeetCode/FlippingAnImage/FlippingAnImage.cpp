#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {        

        for(int i{}; i < A.size(); i++) {
            
            bool isEven = (A[i].size()%2==0);
            int m = A[i].size()/2 - (isEven?1:0);
            int s = A[i].size();
            
            for(int j{}; j <= m; j++) {
                if(j == m && !isEven) {
                    A[i][j] ^= 1;
                }
                else
                {
                    A[i][j] ^= A[i][s -j -1];
                    A[i][s -j-1] ^= A[i][j];
                    A[i][j] ^= A[i][s -j -1];
                    
                    A[i][j] ^= 1;
                    A[i][s-j-1] ^= 1;
                }                 
            }
        }
        return A;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<vector<int>> input =  {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}}; 
    vector<vector<int>> output; 
    output = s.flipAndInvertImage(input);
}