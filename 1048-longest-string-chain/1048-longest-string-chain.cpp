
class Solution {
    
private:

    int dfs(unordered_set<string> &words, unordered_map<string, int> &memo, string currentword) {
        if (memo.find(currentword) != memo.end()) {
            return memo[currentword];
        }
        int Length = 1;

        for (int i = 0; i < currentword.length(); i++) {
            string newWord = currentword.substr(0, i) + currentword.substr(i + 1);
            if (words.find(newWord) != words.end()) {
                int currentLength = 1 + dfs(words, memo, newWord);
                Length = max(Length, currentLength);
            }
        }
        memo[currentword] = Length;

        return Length;
    }

public :
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> memo;
        unordered_set<string> WordsPresent;
        for (const string &word : words) {
            WordsPresent.insert(word);
        }
        int ans = 0;
        for (const string &word : words) {
            ans = max(ans, dfs(WordsPresent, memo, word));
        }
        return ans;
    }
};
