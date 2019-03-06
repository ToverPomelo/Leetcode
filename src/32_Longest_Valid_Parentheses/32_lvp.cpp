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
				//if(!st.empty()) cout<<(char)st.top();

				if(!st.empty()) cout<<i2cFilter(st.top());
				if(!st.empty() && i2cFilter(st.top())=='('){
					st.pop();
					//cout<<"test1: "<<tmpNum<<endl;
					st.push(tmpNum+2);
					//st.push(2);
				}else{
					if(tmpNum) st.push(tmpNum);
					st.push(c2iFilter(si));
				}
            }
        }
		cout<<endl;

		int result = 0;
		while(!st.empty()){
			mergeTopNum(st);

			int top = st.top();
			if(!isNum(top))
				cout<<"test2: "<<i2cFilter(top)<<endl;
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
	
	cout<<test.length()<<endl;

    Solution* s = new Solution();
    cout<<(s->longestValidParentheses(test))<<endl;

    return 0;
}
