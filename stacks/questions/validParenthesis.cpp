bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> ans;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '[' || ch == '{'){
            ans.push(ch);
        }
        else{
            if(!ans.empty()){
                char ch1 = ans.top();
                if((ch1 == '(' && ch == ')' )
                || (ch1 == '[' && ch == ']')
                || (ch1 == '{' && ch == '}')){
                    ans.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(ans.empty()){
        return true;
    }
    else{
        return false;
    }
}