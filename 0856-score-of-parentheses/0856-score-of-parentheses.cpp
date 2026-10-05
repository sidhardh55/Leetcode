class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> st;
        for (char c : s) {
            if (c == '(') {
                st.push("(");
            } else {
                if (st.top() == "(") {
                    st.pop();
                    st.push("1");
                } else {
                    int res = 0;
                    while (st.top() != "(") {
                        res += stoi(st.top());
                        st.pop();
                    }
                    st.pop(); // remove '('
                    st.push(to_string(2 * res));
                }
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += stoi(st.top());
            st.pop();
        }
        return ans;
    }
};