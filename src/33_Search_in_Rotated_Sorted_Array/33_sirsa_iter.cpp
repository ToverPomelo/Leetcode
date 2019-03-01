#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
	private:
		int head_v;
		int tail_v;

	public:
		int search(vector<int>& nums, int target){
            if(nums.size() <= 0) return -1;
			head_v = nums[0];
			tail_v = nums[nums.size()-1];

			stack<int> st;
			int head = 0;
			int tail = nums.size()-1;

			while(head<tail){
				int mid = (head+tail)/2;
				//cout<<"test0: "<<head<<" , "<<tail<<" , "<<mid<<endl;
				if(nums[mid] == target){
					return mid;
				} 
				int new_head = nums[head];
				int new_tail = nums[tail];
				//cout<<"test1: "<<new_head<<" : "<<head_v<<" , "<<new_tail<<" : "<<tail_v<<endl;
				if(head_v>=tail_v && new_head>=head_v && new_tail<=tail_v){ //with pivot
					//cout<<"test2: "<<head<<" , "<<tail<<" , "<<mid<<endl;
					if(nums[mid] <= tail_v){ //pivot on left side
						if(target>=nums[mid] && target<=tail_v){
							head = mid+1;
							//return search_rec(nums,mid+1,tail,target);
						}else/* if(target>=nums[mid] && target>=head_v)*/{
							tail = mid;
							//return search_rec(nums,head,mid,target);
						} 
					}else if(nums[mid] >= head_v){ //pivot on right side
						if(target<=nums[mid] && target>=head_v){
							tail = mid;
							//return search_rec(nums,head,mid,target);
						}else{
							head = mid+1;
							//return search_rec(nums,mid+1,tail,target);
						}
					}
				}else{ //without pivot: normal binary search
					//cout<<"test3: "<<head<<" , "<<tail<<" , "<<mid<<endl;
					if(target >= nums[mid]){
						head = mid+1;
						//return search_rec(nums,mid+1,tail,target);
					}else{
						tail = mid;
						//return search_rec(nums,head,mid,target);
					}
				}
			}
			if(head==tail && nums[head]==target) return head;
			return -1;
		}
};

int main(){
	//vector<int> v = {13,23,33,43,50,0,1,2,6,8,12};
	//vector<int> v = {0,1,2,6,8,12};
	//vector<int> v = {};
	//vector<int> v = {4,5,6,7,8,1,2,3};
	vector<int> v = {7,8,9,1,2,3,4,5,6};
	//vector<int> v = {3,1};
	//vector<int> v = {4,5,7,8,9,10,12,15,22,23,27,32,35};

	Solution* s = new Solution();
	cout<<s->search(v,111111)<<endl;
	for(int i : v){
		cout<<s->search(v,i)<<endl;
	}

	return 0;
}
