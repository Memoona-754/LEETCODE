class Solution {
public:
    string smallestPalindrome(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        
        string half = "";
        char mid = '\0';
        
        for (int i = 0; i < 26; i++) {
            half += string(cnt[i] / 2, 'a' + i);
            if (cnt[i] % 2 == 1) {
                mid = 'a' + i;
            }
        }
        
        string rev = half;
        reverse(rev.begin(), rev.end());
        
        string result = half;
        if (mid != '\0') result += mid;
        result += rev;
        
        return result;
    }
};