
class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> freq;

        for (int x : nums)
        {
            freq[x]++;
        }

        int ans = 0;

        // Handle 1 separately
        int ones = freq[1];

        if (ones > 0)
        {
            if (ones % 2 == 0)
                ones--;

            ans = ones;
        }

        long long maxVal = *max_element(nums.begin(), nums.end());

        for (auto p : freq)
        {
            long long x = p.first;

            if (x == 1)
                continue;

            int len = 0;

            while (freq[x] >= 2)
            {
                // Prevent overflow and unnecessary squaring
                if (x > maxVal / x)
                    break;

                long long next = x * x;

                // Square must exist in the array
                if (freq.find(next) == freq.end())
                    break;

                len += 2;
                x = next;
            }

            // Add middle element
            if (freq[x] >= 1)
                len++;

            ans = max(ans, len);
        }

        return ans;
    }
};

