
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::string freqAlphabets(std::string s) {

        std::string decrypt{};
        
        for(int i{}; i < s.size(); ++i) {
            
            if(i+2 >= s.size() || s[i+2] != '#') {

                decrypt += (char)(96 + (s[i] - '0'));

            }
            else {
                i+=2;

                decrypt += (char)(96 + (s[i-2] - '0')*10 + (s[i-1] - '0'));

            }
        }
        
        return decrypt;
   
    }
};

int main() {

  std::string cypher = "1326#";// "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"; //"1326#"; // cypher = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"; // cypher{"25#"}; // cypher{"1326#"}; // cypher{"10#11#12"};

  Solution s;
  std::string decrypt = s.freqAlphabets(cypher);

  std::cout << "Your decrypt is: " << decrypt << std::endl;

};