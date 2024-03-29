// Greedy, easier to understand
// Always find smaller numbers to maximize the possible sequence length
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sequence;
        for (int n : nums) {
            auto itr = lower_bound(sequence.begin(), sequence.end(), n);
            if (itr == sequence.end()) {
                sequence.push_back(n);
            } else {
                sequence[itr - sequence.begin()] = n;
            }
        }

        return sequence.size();
    }
};

// Greedy
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails(nums.size());
        int length = 0;
        for (int num : nums) {
            int left = 0;
            int right = length;
            while (left < right) {
                int mid = (left + right) / 2;
                if (tails[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            tails[left] = num;
            if (length == right) {
                length++;
            }
        }
        
        return length;
    }
};

// DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLength = 1;
        vector<int> lisEndMap(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lisEndMap[i] = max(lisEndMap[i], lisEndMap[j] + 1);
                }
            }
            
            maxLength = max(maxLength, lisEndMap[i]);
        }
        
        return maxLength;
    }
};