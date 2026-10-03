class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find the '#'
            while (s[j] != '#') {
                j++;
            }

            // Get the length
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Extract the string
            string word = s.substr(j, len);
            ans.push_back(word);

            // Move to the next encoded string
            i = j + len;
        }

        return ans;
    }
};