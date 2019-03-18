#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    unsigned int* dp;
    unsigned int size;

    unsigned int v_min(unsigned int left,unsigned int right){
        unsigned int min = left;
        if(right >= size-1) return size-1;
        for(unsigned int i=left+1;i<size&&i<=right;i++){
            if(dp[i] < dp[min]) min = i;
        }
        return min;
    }

    void view(){
        for(unsigned int i=0;i<size;i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }

public:
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;
        size = nums.size();
        if(size == 1) return 0;
        dp = new unsigned int[size];
        dp[size-1] = 0;
        for(unsigned int i=size-2;i>=0&&i<(unsigned int)(0)-1;i--){
            if(i+1<size-1 && nums[i]>nums[i+1]) dp[i] = dp[i+1];  //TLE...
            else dp[i] = dp[v_min(i+1,i+nums[i])]+1; 
        }

        //view();

        return dp[0];
    }

    ~Solution(){
        if(dp){
            delete[] dp;
        }
    }
};

int main(){
	vector<int> v = {2,3,1,1,4};

	Solution* s = new Solution();
	cout<<s->jump(v)<<endl;

	return 0;
}

