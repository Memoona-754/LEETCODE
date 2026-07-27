class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> characters;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            while (characters.find(s[right]) != characters.end()) {
                characters.erase(s[left]);
                left++;
            }

            characters.insert(s[right]);

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};