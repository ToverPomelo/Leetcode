#include <iostream>
#include <vector>
using namespace std;

class Solution{
	private:
		int head_v;
		int tail_v;

	public:
		int search(vector<int>& nums, int target){
			head_v = nums[0];
			tail_v = nums[nums.size()-1];

			return search_rec(nums,0,nums.size()-1,target);
		}
		
		int search_rec(vector<int>& nums, int head, int tail, int target){
			if(head >= tail) return -1;
			int new_head = nums[head];
			int new_tail = nums[tail];
			int mid = (head+tail)/2;
			if(new_head>=head_v && new_tail<=tail_v){ //with pivot
				if(target <= tail_v){
					return search_rec(nums,mid+1,tail,target);
				}else{
					return search_rec(nums,head,mid,target);
				}
			}else{ //without pivot: normal binary search
				if(nums[mid] == target){
					return mid;
				}
				else if(target >= nums[mid]){
					return search_rec(nums,mid+1,tail,target);
				}else{
					return search_rec(nums,head,mid,target);
				}
			}
			return -1;
		}
};

int main(){
	vector<int> v = {4,5,6,7,8,0,1,2,3};

	Solution* s = new Solution();
	cout<<s->search(v,0)<<endl;

	return 0;
}
