#include <iostream>
#include <map>
using namespace std;

class Solution {
    public:
        int max(int a,int b){
            return a>b ? a : b;
        }

        bool repeat(string s,char c){
            for(char si : s){
                if(c == si) return true;
            }
            return false;
        }

        int lengthOfLongestSubstring(string s) {
            if(s == "") return 0;
            map<char,bool> mp;
            int size = s.size(); 
            int* arr_num = new int[size+1];  //dp
            arr_num[0] = 0;

            for(int i=1;i<=size;i++){
                if(!mp[s[i-1]]){  //init map
                    mp[s[i-1]] = true; 
                    arr_num[i] = arr_num[i-1] +1;
                    continue;
                }
                //cout<<"test1: "<<s[i]<<" , "<<hex<<mp[s[i]]<<endl;
                
                //if((mp[s[i-1]] & arr_eig[i-1])){  //repeaded
                if(repeat(s,s[i-1])){  //repeaded
                    int j;
                    for(j=i-2;(j>i-arr_num[i]-1 && s[j]!=s[i-1]);j--);
                    arr_num[i] = i-j-1;
                }else{
                    arr_num[i] = arr_num[i-1] +1;
                }

            }

            int result = 0;
            for(int i=1;i<=size;i++){
                result = max(result,arr_num[i]);
            }

            cout<<"test2: ";
            for(int i=0;i<size;i++){
                cout<<s[i]<<"\t";
            }
            cout<<endl;

            cout<<"test2: ";
            for(int i=1;i<=size;i++){
                cout<<arr_num[i]<<"\t";
            }
            cout<<endl;

            delete[] arr_num;
            return result;
        }
};

int main(){
    Solution* s = new Solution();
    //string test = "pwwwkew";
    //string test = "abcabcbb";
    //string test = "aaaaaaaaaaaaaaaaaa";
    //string test = "";
    //string test = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    //string test = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABC";
    //string test = "abba";
    string test = "dvdf";
    cout<<(s->lengthOfLongestSubstring(test))<<endl;

    return 0;
}

