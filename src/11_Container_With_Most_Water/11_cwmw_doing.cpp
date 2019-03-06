#include <iostream>
#include <vector>
using namespace std;

class Solution{
	private:

	public:
        int min(int a,int b){
            return a<b ? a : b;
        }

        int max(int a,int b){
            return a>b ? a : b;
        }

        int listMax(int* arr,int len){
            int tmp = -1;
            for(int i=0;i<len;i++){
                tmp = max(tmp,arr[i]);
            }
            return tmp;
        }

        int maxArea(vector<int>& height) {
            if(height.empty()) return 0;

            int len = height.size();
            int* arr = new int[len];
            for(int i=0;i<len;i++){
                arr[i] = 0;
                for(int j=i+1;j<len;j++){
                    arr[i] = max(arr[i] , (min(height[i],height[j]) * (j-i)));
                }
                //cout<<"test1: "<<arr[i]<<endl;
            }

            int result = listMax(arr,len);
            delete[] arr;
            return result;
        }

};

int main(){
	vector<int> v = {};
	//vector<int> v = {1,8,6,2,5,4,8,3,7};

	Solution* s = new Solution();
	cout<<s->maxArea(v)<<endl;

	return 0;
}
