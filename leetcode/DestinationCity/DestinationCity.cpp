
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
    
        std::string destination;
        std::string lastValidDestination;
    
        std::unordered_map<std::string, std::string> hash_p;
    
        for(std::vector<std::string> v: paths) {
            hash_p.insert({v[0], v[1]});
        }

        lastValidDestination = paths[0][0];

        auto it = hash_p.find(lastValidDestination);
        lastValidDestination = it->second;
      
        while(it != hash_p.end()){
            it = hash_p.find(lastValidDestination);
            if (it != hash_p.end()) {
                lastValidDestination = it->second;
            }
        }
        return lastValidDestination;
    }
};

int main() {

  std::vector<std::vector<std::string>> paths{{"London","New York"}, {"New York","Lima"}, {"Lima","Sao Paulo"}};

  Solution s;
  std::string destinCity = s.destCity(paths);

  std::cout << "Your destination city is: " << destinCity << std::endl;

};