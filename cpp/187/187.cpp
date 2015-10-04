#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include <map>

using namespace std;

int sub_dna_map[1048576];

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
		bitset<20> sub_dna;
		memset(sub_dna_map, 0xFF, 1048576 * sizeof(int));
		for(size_t i = 0; i < 10; ++i)
		{
			switch(s[i])
			{
			case 'A':
				break;
			case 'C':
				sub_dna.set(2 * i);
				break;
			case 'G':
				sub_dna.set(2 * i + 1);
				break;
			case 'T':
				sub_dna.set(2 * i);
				sub_dna.set(2 * i + 1);
				break;
			}
		}
		int index_1 = (int)sub_dna.to_ulong();
		sub_dna_map[index_1] = 0;
		for(size_t i = 10; i < s.size(); ++i)
		{
			sub_dna = sub_dna >> 2;
			switch(s[i])
			{
			case 'A':
				break;
			case 'C':
				sub_dna.set(18);
				break;
			case 'G':
				sub_dna.set(19);
				break;
			case 'T':
				sub_dna.set(18);
				sub_dna.set(19);
				break;
			}
			int index = (int)sub_dna.to_ulong();
			if(sub_dna_map[index] == -1)
				sub_dna_map[index] = i - 9;
			else if(sub_dna_map[index] >= 0)
			{
				result.push_back(s.substr(sub_dna_map[index], 10));
				sub_dna_map[index] = -2;
			}
		}
		return result;
    }
};


int main()
{
	Solution solution;
	vector<string> result = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for(auto iter = result.begin(); iter != result.end(); ++iter)
		cout << *iter << endl;
	return 0;
}