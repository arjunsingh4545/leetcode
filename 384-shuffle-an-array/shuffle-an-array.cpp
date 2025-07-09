class Solution {
    vector<int> shuffledArr;
    vector<int> originalArr;
    uint32_t x = 123456789;  // Seed for Xorshift RNG

    // Xorshift32 random number generator (fast and lightweight)
    uint32_t fastRand() {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        return x;
    }

public:
    Solution(vector<int>& nums) {
        originalArr = nums;
        shuffledArr = nums;
    }

    vector<int> reset() {
        shuffledArr = originalArr;
        return shuffledArr;
    }

    vector<int> shuffle() {
        int n = shuffledArr.size();
        for (int i = n - 1; i > 0; --i) {
            int j;
            // Use bitwise AND if (i+1) is power of 2
            if ((i & (i + 1)) == 0) {
                j = fastRand() & i;
            } else {
                j = fastRand() % (i + 1);
            }
            swap(shuffledArr[i], shuffledArr[j]);
        }
        return shuffledArr;
    }
};
