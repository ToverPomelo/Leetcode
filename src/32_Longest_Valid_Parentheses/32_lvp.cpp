#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int max(int a,int b){
        return a>b ? a : b;
    }

	bool isNum(int i){
		return i>=0;
	}

	bool bothNumber(int last,int now){
		return last>=0 && now>=0;
	}

	int c2iFilter(char c){
		if(c == '(') return -1;
		else if(c == ')') return -2;
		else return (int)c;
	}

	char i2cFilter(int i){
		if(i == -1) return '(';
		else if(i == -2) return ')';
		else return (char)i;
	}

	void mergeTopNum(stack<int>& st){
        if(st.empty() || !isNum(st.top())) return;
        int tmpNum = st.top();
        st.pop();
        while(!st.empty() && isNum(st.top())){
            tmpNum += st.top();
            st.pop();
        }
        st.push(tmpNum);
	}

    int longestValidParentheses(string s) {
        stack<int> st;

        for(char si : s){
            if(si == '('){
                st.push(c2iFilter(si));
            }else if(si == ')'){
				mergeTopNum(st);

				int tmpNum = 0;
				if(!st.empty() && bothNumber(st.top(),0)){
					tmpNum = st.top();
					st.pop();
				}

				if(!st.empty() && i2cFilter(st.top())=='('){
					st.pop();
					st.push(tmpNum+2);
				}else{
					if(tmpNum) st.push(tmpNum);
					st.push(c2iFilter(si));
				}
            }
        }

		int result = 0;
		while(!st.empty()){
			mergeTopNum(st);

			int top = st.top();
            if(isNum(top)){
				result = max(result,top);
				//cout<<"test2: "<<top<<endl;
            }
			//else{
				//cout<<"test2: "<<i2cFilter(top)<<endl;
			//}

			st.pop();
		}
 
        return result;
    }
};

int main(){
    //string test = "";
    //string test = "(())";
    //string test = "))(())))";
    //string test = "))(((())(()))()))(()((((((())))))))((((";
    string test = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
	
	cout<<test.length()<<endl;

    Solution* s = new Solution();
    cout<<(s->longestValidParentheses(test))<<endl;

    return 0;
}
