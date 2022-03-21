/*
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> ret;
		int n = digits.size();
		if (n == 0) return ret;
		string str = "";
		backTrack(ret, digits, str, 0, n);
		return ret;
    }
	void backTrack(vector<string>& ret, string& digits, string& str, int start, int n) {
		if (start == n) {
			ret.push_back(str);
			return;
		}
		int digit = digits[start] - '0';
		for (char c : digit_map[digit]) {
			str.push_back(c);
			backTrack(ret, digits, str, start + 1, n);
			str.pop_back();
		}
	}
private:
	//unordered_map<int, vector<char>> digit_map = 
	//{
	//	{2, {'a', 'b', 'c'}},
	//	{3, {'d', 'e', 'f'}},
	//	{4, {'g', 'h', 'i'}},
	//	{5, {'j', 'k', 'l'}},
	//	{6, {'m', 'n', 'o'}},
	//	{7, {'p', 'q', 'r', 's'}},
	//	{8, {'t', 'u', 'v'}},
	//	{9, {'w', 'x', 'y', 'z'}}
	//};
	unordered_map<int, string> digit_map = 
	{
		{2, "abc"},
		{3, "def"},
		{4, "ghi"},
		{5, "jkl"},
		{6, "mno"},
		{7, "pqrs"},
		{8, "tuv"},
		{9, "wxyz"}
	};
};
