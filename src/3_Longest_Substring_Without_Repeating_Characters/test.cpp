#include <iostream>
#include <map>
using namespace std;

class Solution {
    public:
        int max(int a,int b){
            return a>b ? a : b;
        }

        int lengthOfLongestSubstring(string s) {
            if(s == "") return 0;
            map<char,unsigned long long> mp;
            unsigned long long iter = 1;
            int size = s.size(); 
            int* arr_eig = new int[size+1];  //eigenvalue
            arr_eig[0] = 0;
            int* arr_num = new int[size+1];  //dp
            arr_num[0] = 0;

            for(int i=1;i<=size;i++){
                if(!mp[s[i-1]]){  //init map
                    mp[s[i-1]] = iter; 
                    iter <<= 1;
                    arr_eig[i] = (arr_eig[i-1] | mp[s[i-1]]);
                    arr_num[i] = arr_num[i-1] +1;
                    continue;
                }
                //cout<<"test1: "<<s[i]<<" , "<<hex<<mp[s[i]]<<endl;
                
                if((mp[s[i-1]] & arr_eig[i-1])){  //repeaded
                    //妥协方法
                    int j;
                    unsigned long long eig_tmp = mp[s[i-1]];
                    for(j=i-2;(j>0 && s[j]!=s[i-1]);eig_tmp|=mp[s[j]],j--);
                    arr_eig[i] = eig_tmp;
                    arr_num[i] = i-j-1;
                }else{
                    arr_eig[i] = (arr_eig[i-1] | mp[s[i-1]]);
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
            delete[] arr_eig;
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
    string test = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABC";
    cout<<(s->lengthOfLongestSubstring(test))<<endl;

    return 0;
}

