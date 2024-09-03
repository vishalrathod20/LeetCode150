class Solution {
public:
    int evalRPN(vector<string>& tokens) {
          stack<int> st;

    for (const auto& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Agar token operator hai, toh stack se do elements nikaalo
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (token == "+") {
                st.push(a + b);
            } else if (token == "-") {
                st.push(a - b);
            } else if (token == "*") {
                st.push(a * b);
            } else if (token == "/") {
                st.push(a / b); // integer division jo towards zero truncate karta hai
            }
        } else {
            // Agar token number hai, toh usse stack mein push karo
            st.push(stoi(token)); // Convert string to integer
        }
    }

    return st.top();   
    }
};
