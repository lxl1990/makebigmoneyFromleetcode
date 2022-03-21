class Solution {
public:
    vector<string> letterCasePermutation(string s) {
		vector<string> ret;
		int n = s.size();
		if (n == 0) return ret;
		backTrack(ret, s, 0, n);
		return ret;
    }
	void backTrack(vector<string>& ret, string& s, int cur, int n) {
		if (cur == n) {
			ret.push_back(s);
			return;
		}
 		if (s[cur] >= 'A' && s[cur] <= 'Z') {
            s[cur] += 32;
            backTrack(ret, s, cur + 1, n);
            s[cur] -= 32;
		} else if (s[cur] >= 'a' && s[cur] <= 'z') {
            s[cur] -= 32;
            backTrack(ret, s, cur + 1, n);
            s[cur] += 32;
        }
        backTrack(ret, s, cur + 1, n);
	}
};
