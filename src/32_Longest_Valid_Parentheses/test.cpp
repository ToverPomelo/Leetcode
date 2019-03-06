#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int max(int a,int b){
        return a>b ? a : b;
    }

	bool bothNumber(int last,int now){
		return (char)last!='(' && (char)last!=')' && (char)now!='(' && (char)now!=')';
	}

    int longestValidParentheses(string s) {
        stack<int> st;

        for(char si : s){
            if(si == '('){
                st.push(int(si));
            }else if(si == ')'){
				int lastTop = 0;
				if(!st.empty()){
					lastTop = st.top();
					st.pop();
				}else{
					st.push((int)')');
					continue;
				}

				int tmpNum = 0;
				if(!bothNumber(lastTop,0)){ //not a number
					st.push(lastTop);
				}else{
					while(!st.empty() && bothNumber(lastTop,st.top())){  //sum numbers(final lastTop)
						lastTop = st.top()+lastTop;
						st.pop();
					}
					tmpNum = lastTop;
				}

				if(!st.empty() && (char)st.top()=='('){
					st.pop();
					//cout<<"test1: "<<tmpNum<<endl;
					st.push(tmpNum+2);
				}else{
					if(tmpNum) st.push(tmpNum);
					st.push((int)')');
				}
            }
        }

		int result = 0;
		while(!st.empty()){
			while(st.size() >= 2){  //sum numbers
				int lastTop = st.top();
				st.pop();
				int nowTop = st.top();
				st.pop();
				
				if(bothNumber(lastTop,nowTop)){
					st.push(lastTop+nowTop);
				}else{
					st.push(nowTop);
					st.push(lastTop);
					break;
				}
			}

			int top = st.top();

			if((char)top=='(' || (char)top==')')
				cout<<"test2: "<<(char)top<<endl;
			else{
				result = max(result,top);
				cout<<"test2: "<<top<<endl;
			}

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

    Solution* s = new Solution();
    cout<<(s->longestValidParentheses(test))<<endl;

    return 0;
}
