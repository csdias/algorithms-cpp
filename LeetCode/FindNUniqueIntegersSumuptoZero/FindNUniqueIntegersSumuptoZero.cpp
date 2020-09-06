#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v(n);

        if (n == 1) {
            v[0] = 0;
            return v;
        }
        
        bool isEven = (n%2 == 0);
        int m = n/2 - (isEven ? 1 : 0); 
                
        for(int i{}; i<= m; i++) {
        
            if (i == m && !isEven)
                v[i] = 0;
            else {
                v[i] = (i+1)*-1;;
                v[n-i-1] = i+1;
            }
        }
        
        return v;
    }
};