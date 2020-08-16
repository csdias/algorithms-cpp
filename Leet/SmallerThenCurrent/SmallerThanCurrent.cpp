#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>

using namespace std;

class Solution {
public:

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> vi(nums.size());
        int zero = 0;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(nums[i] > nums[j] && i != j){
                    vi[i] = vi[i]+1;
                }
            }
        }
        return vi;
    }
};

int main()
{
    Solution s;
    vector<int> nums{8,1,2,2,3};
    auto smallerNumbers = s.smallerNumbersThanCurrent(nums);

    for (const int& num : smallerNumbers)
    {
        cout << num << " ";
    }
    cout << endl;
}
