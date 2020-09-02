#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <iomanip>

using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {

        stringstream hhmm{};
        string largestTime{};

        vector<vector<int>> hourCandidates{}; 
        vector<int> f{};
        f.push_back(0);
        f.push_back(0);
        f.push_back(0);
        f.push_back(0);

        for(int i{}; i < A.size(); i++) {
            for(int j{}; j < A.size(); j++) {
                if (i != j &&  (A[i]*10) + A[j] < 24) {
                    for(int k{}; k < A.size(); k++) {
                        for(int l{}; l < A.size(); l++) {
                            if (k != l && (k != i && k != j) && (l != i && l != j) && (A[k]*10) + A[l] < 60) {     
                                hourCandidates.push_back({A[i],A[j],A[k],A[l]});
                            }
                        }
                    }
                }
            }
        }

        if (hourCandidates.size() == 0) {
            return "";
        }

        for(int v{}; v < hourCandidates.size(); v++){

            int h1 = ( ((hourCandidates[v][0]*10) + (hourCandidates[v][1])) * 60);
            int m1 = ( (hourCandidates[v][2]*10) + (hourCandidates[v][3]));
            int h2 = ( ((f[0]*10) + (f[1])) * 60);
            int m2 = ( (f[2]*10) + (f[3]));

            if (h1 + m1 > h2 + m2) {
                 f[0] = hourCandidates[v][0];
                 f[1] = hourCandidates[v][1];
                 f[2] = hourCandidates[v][2];
                 f[3] = hourCandidates[v][3];
             }
        }

        hhmm << f[0] << f[1] << ":" << f[2] << f[3];

        largestTime += hhmm.str();

        return largestTime;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,2,3,4};
    auto smallerNumbers = s.largestTimeFromDigits(nums);

    for (const int& num : smallerNumbers)
    {
        cout << num << " ";
    }
    cout << endl;
}
