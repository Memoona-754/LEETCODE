class Solution {
public:
    const long long CAP = 2000000;
    
    long long arrangements(vector<int>& counts, int n) {
        long long result = 1;
        int seen = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= counts[i]; j++) {
                seen++;
                result = result * seen / j;
                if (result > CAP) return CAP + 1;
            }
        }
        return result;
    }
    
    string smallestPalindrome(string s, long long k) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        vector<int> half(26, 0);
        char mid = '\0';
        int halfLen = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            halfLen += half[i];
            if (cnt[i] % 2 == 1) mid = 'a' + i;
        }
        
        long long total = arrangements(half, halfLen);
        if (k > total) return "";
        
        string result = "";
        int remainingLen = halfLen;
        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;
                half[c]--;
                long long cntArr = arrangements(half, remainingLen - 1);
                half[c]++;
                if (k <= cntArr) {
                    half[c]--;
                    result += (char)('a' + c);
                    remainingLen--;
                    break;
                } else {
                    k -= cntArr;
                }
            }
        }
        
        string rev = result;
        reverse(rev.begin(), rev.end());
        string ans = result;
        if (mid != '\0') ans += mid;
        ans += rev;
        return ans;
    }
};