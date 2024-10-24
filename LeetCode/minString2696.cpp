#include <iostream>
using namespace std;
class Solution {
public:
    int minLength(string s) {
        bool noChange = false;
        
        while (!noChange) {
            noChange = true;
            string str = ""; // Reinitialize the result string at the beginning of each pass
            
            for (int i = 0; i < s.size(); i++) {
                // Ensure we don't go out of bounds for i+1
                if (i < s.size() - 1 && 
                    ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'C' && s[i + 1] == 'D'))) {
                    i++;  // Skip the next character as "AB" or "CD" is removed
                    noChange = false;  // Changes were made, so keep going
                } else {
                    str += s[i];  // Append character to new string
                }
            }
            
            s = str;  // Update the original string with the new one
        }
        
        return s.size();  // Return the length of the resulting string
    }
};
int main(){
    return 0;
}