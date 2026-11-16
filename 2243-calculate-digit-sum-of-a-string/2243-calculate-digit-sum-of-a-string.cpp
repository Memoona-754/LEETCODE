
class Solution {
public:
    string digitSum(string s, int k) {

        while (s.length() > k)
        {
            string ans = "";

            // Divide string into groups of size k
            for (int i = 0; i < s.length(); i += k)
            {
                int sum = 0;

                // Calculate sum of digits in each group
                for (int j = i; j < i + k && j < s.length(); j++)
                {
                    sum += s[j] - '0';
                }

                // Convert sum into string
                ans += to_string(sum);
            }

            // Update original string
            s = ans;
        }

        return s;
    }
};
