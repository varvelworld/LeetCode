#include <cstdint>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bs(n);
        bitset<32> reverse_bs;
        for(int i = 0; i < 32; ++i) {
            reverse_bs[31 - i] = bs[i];
        }
        return reverse_bs.to_ulong();
    }
};

int main(void) {
    Solution *solution = new Solution();
    cout << solution->reverseBits(43261596) << endl;
    return 0;
}