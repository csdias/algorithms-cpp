#include <vector>
#include <unordered_map>
//#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string, int> umap;
        
        string morseAlphabet[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        string morseCode{};
        for(auto w: words){
            morseCode = "";
            for(char c: w){
                morseCode += morseAlphabet[ int(c) - 97 ];
            }
            umap[morseCode]++;
        }
            
        return umap.size();
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<string> input = {"gin", "zen", "gig", "msg"}; 
    int output = s.uniqueMorseRepresentations(input);
}