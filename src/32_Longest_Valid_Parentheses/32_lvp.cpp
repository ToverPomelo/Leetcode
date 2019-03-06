#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int max(int a,int b){
        return a>b ? a : b;
    }

    int longestValidParentheses(string s) {
        int tmpNum = 0;
        stack<int> st;

        for(char si : s){
            if(si == '('){
                st.push(int(si));
            }else if(si == ')'){
                /*char表示正常的，int存合理的大小（分段）*/
            }
        }
 
        return 0;
    }
};

int main(){
    string test = "(())";

    Solution* s = new Solution();
    cout<<(s->longestValidParentheses(test))<<endl;


    return 0;
}
