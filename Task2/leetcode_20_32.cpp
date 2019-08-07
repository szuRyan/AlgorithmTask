//Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        map<char, char> parenth_dict;
            parenth_dict['('] = ')';
            parenth_dict['{'] = '}';
            parenth_dict['['] = ']';
            
            stack<char> aux_stack;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
                    aux_stack.push(s[i]);
                else if (aux_stack.empty() || parenth_dict[aux_stack.top()] != s[i])
                    return false;
                else
                    aux_stack.pop();
            }
            
            return aux_stack.empty();
    }
};



//Longest Valid Parentheses
//DP  stack

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size(), maxL=0, i;
        stack<int> Stack;
        Stack.push(-1);
        for(i=0; i<length;++i)
        {
            if(s[i]==')' && Stack.top()>=0 && s[Stack.top()]=='(')
            {                            
                Stack.pop();                    
                maxL = max(maxL, i-Stack.top());   
            }
            else Stack.push(i);
        }
        return maxL;
    }
};

