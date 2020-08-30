class Solution {
public:
    string freqAlphabets(string s) {
        
    unordered_map<string, string> map;
    map.insert ( {{"1","a"},{"2","b"}, {"3","c"}, {"4","d"}, {"5","e"}, {"6","f"}, {"7","g"}, {"8","h"}, {"9","i"}, {"10#","j"}, {"11#","k"}, {"12#","l"}, {"13#","m"}, {"14#","n"}, {"15#","o"}, {"16#","p"}, {"17#","q"}, {"18#","r"}, {"19#","s"}, {"20#","t"}, {"20#","u"}, {"22#","v"}, {"23#","w"}, {"24#","x"}, {"25#","y"}, {"26#","z"} } );
 
        
        vector<char> v{};
        string key{};
        string decrypt{};
        unordered_map<string, string>::iterator it{};
        int c{}; string t{};
        
        for(int i{}; i < s.size(); i++) {
            
            if (s[i] == '#') {
                key.push_back(s[i-2]);
                key.push_back(s[i-1]);
                key.push_back(s[i]);
                
                cout << key << endl;
                //it = map.find(key);
                //cout << it->second << endl;
                
                if (c > 0) {
                    decrypt.pop_back();
                    c--;
                }
                
                if (c > 0) {
                    decrypt.pop_back();
                    c--;
                }
                
                //t = it->second;
                
                //cout << it->second << endl;
                
                //decrypt.push_back(t[0]);                    

                //key.pop_back(); key.pop_back(); key.pop_back();
                
            }
            else {
                c++;
                //key.push_back("1");
                //it = h.find(key);
                //token.pop_back();
                //cout << it->second << endl;
                //decode.push_back(i->second);                    
            }
        }
        return s;
    }
};