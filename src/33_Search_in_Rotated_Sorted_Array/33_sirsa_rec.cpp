#include <iostream>
#include <vector>
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
			return search_rec(nums,0,nums.size()-1,target);
		}
		
		int search_rec(vector<int>& nums, int head, int tail, int target){
			int mid = (head+tail)/2;
            //cout<<"test0: "<<head<<" , "<<tail<<" , "<<mid<<endl;
            if(nums[mid] == target){
                return mid;
            } 
			if(head >= tail) return -1;
			int new_head = nums[head];
			int new_tail = nums[tail];
            //cout<<"test1: "<<new_head<<" : "<<head_v<<" , "<<new_tail<<" : "<<tail_v<<endl;
			if(head_v>=tail_v && new_head>=head_v && new_tail<=tail_v){ //with pivot
                //cout<<"test2: "<<head<<" , "<<tail<<" , "<<mid<<endl;
                if(nums[mid] <= tail_v){ //pivot on left side
                    if(target>=nums[mid] && target<=tail_v){
                        return search_rec(nums,mid+1,tail,target);
                    }else/* if(target>=nums[mid] && target>=head_v)*/{
                        return search_rec(nums,head,mid,target);
                    } 
                }else if(nums[mid] >= head_v){ //pivot on right side
                    if(target<=nums[mid] && target>=head_v){
                        return search_rec(nums,head,mid,target);
                    }else{
                        return search_rec(nums,mid+1,tail,target);
                    }
                }
			}else{ //without pivot: normal binary search
                //cout<<"test3: "<<head<<" , "<<tail<<" , "<<mid<<endl;
				if(target >= nums[mid]){
					return search_rec(nums,mid+1,tail,target);
				}else{
					return search_rec(nums,head,mid,target);
				}
			}
			return -1;
		}
};

int main(){
	//vector<int> v = {13,23,33,43,50,0,1,2,6,8,12};
	//vector<int> v = {0,1,2,6,8,12};
	//vector<int> v = {};
	vector<int> v = {4,5,6,7,8,1,2,3};
	//vector<int> v = {7,8,9,1,2,3,4,5,6};
	//vector<int> v = {3,1};

	Solution* s = new Solution();
	cout<<s->search(v,8)<<endl;

	return 0;
}
