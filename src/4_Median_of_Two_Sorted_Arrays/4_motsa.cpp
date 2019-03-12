#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        }
};

int main(){
	vector<int> v1 = {1,3,5,7,9};
	vector<int> v2 = {2,4,6,8,10};

	Solution* s = new Solution();
	cout<<s->findMedianSortedArrays(v1,v2)<<endl;

	return 0;
}

