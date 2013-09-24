#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // trivial case first
        if (s.empty())
            return 0;
            
        int ret = 1;
        unordered_map<char, int> prev;
        int longest_ending_here = 0;
        for (int i = 0; i < s.length(); i++) {
            longest_ending_here = min(i + 1 - prev[s[i]], longest_ending_here + 1);
            if (longest_ending_here > ret)
                ret = longest_ending_here;
            prev[s[i]] = i + 1;
        }
        
        return ret;
    }
};
