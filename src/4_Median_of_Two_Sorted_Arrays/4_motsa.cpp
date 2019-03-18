#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
    private:
		int left,right;
		int lv1,rv1,lv2,rv2;  //index
		int ml1,mr1,ml2,mr2;  //index
		bool real1,real2;  //0->num1 ; 1->num2
		
		double getMid(int len1,int len2){
			return (len1+len2-1)/2;
		}
		
		int max(int a,int b){
			return a>b ? a : b;
		}
		
		void refreshM(){  
			ml1 = lv1+(rv1-lv1)/2;
			mr1 = rv1-(rv1-lv1)/2;
			ml2 = lv2+(rv2-lv2)/2;
			mr2 = rv2-(rv2-lv2)/2;
		}

		void cut1(vector<int>* v1,vector<int>* v2){
			if((*v1)[ml1] < (*v2)[ml2]){  //ml1 is 1
				left += mr1-lv1;
				if(real1!=real2 && lv1>=rv1){
					lv1 = lv2;
					rv1 = mr2;
					lv2 = ml2;
				}else{
					lv1 = mr1;
				}
			}else{  //ml2 is 1
				left += mr2-lv2;
				if(real1!=real2 && lv2>=rv2){
					lv2 = lv1;
					rv2 = mr1;
					lv1 = ml1;
				}else{
					lv2 = mr2;
				}
			}	

		}

		void cut4(vector<int>* v1,vector<int>* v2){
			if((*v1)[mr1] > (*v2)[mr2]){  //mr1 is 4
				right += rv1-ml1;
				if(real1!=real2 && lv1>=rv1){
					lv1 = ml2;
					rv1 = rv2;
					rv2 = mr2;
				}else{
					rv1 = ml1;
				}
			}else{  //mr2 is 4
				right += rv2-ml2;
				if(real1!=real2 && lv2>=rv2){
					lv2 = ml1;
					rv2 = rv1;
					rv1 = mr1;
				}else{
					rv2 = ml2;
				}
			}

		}
		
		void cut(vector<int>* nums1,vector<int>* nums2){
            vector<int> *v1,*v2;
            if(real1) v1 = nums2;
            else v1 = nums1;
            if(real2) v2 = nums2;
            else v2 = nums1;

            cout<<"real1 : "<<real1<<" ,real2 : "<<real2<<endl; 
            cout<<"test2: "<<lv1<<","<<rv1<<","<<lv2<<","<<rv2<<endl;
            cout<<"test3: "<<ml1<<","<<mr1<<","<<ml2<<","<<mr2<<endl;
			cout<<"left  : "<<left<<" ,right  : "<<right<<endl; 
			
			if(left < right){  //cut 1
				cut1(v1,v2);
			}else if(left > right){  //cut 4
				cut4(v1,v2);
			}else{  //random
				if(rand()%2) cut1(v1,v2);
				else cut4(v1,v2);
			}
		}
		
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			srand((unsigned)time(0));
            left = right = 0;
			lv1 = lv2 = 0;
			rv1 = nums1.size()-1;
			rv2 = nums2.size()-1;
			
			real1 = 0;
			real2 = 1;
			
			int mid = getMid(nums1.size(),nums2.size());
			while(left!=mid || right!=mid){
                refreshM();
                cut(&nums1,&nums2);				
			}
            //cout<<"test1: "<<real1<<" , "<<real2<<endl;
            cout<<"test2: "<<lv1<<" , "<<rv1<<" , "<<lv2<<" , "<<rv2<<endl;
            //cout<<"test3: "<<ml1<<" , "<<mr1<<" , "<<ml2<<" , "<<mr2<<endl;
            //cout<<"test4: "<<nums1[ml1]<<" , "<<nums1[mr1]<<" , "<<nums2[ml2]<<" , "<<nums2[mr2]<<endl;
            cout<<"real1 : "<<real1<<" ,real2 : "<<real2<<endl; 
            //cout<<"index1: "<<lv1<<" ,index2: "<<lv2<<endl; 
            cout<<"left  : "<<left<<" ,right  : "<<right<<endl; 

			int len1 = nums1.size(); 
			int len2 = nums2.size(); 
            vector<int> *v1,*v2;
            if(real1) v1 = &nums2;
            else v1 = &nums1;
            if(real2) v2 = &nums2;
            else v2 = &nums1;
			if((len1+len2)%2){  //odd
				return (*v1)[lv1];
			}else{
				return (double)((*v1)[lv1]+(*v2)[lv2])/2;
			}
			return 0;
        }
};

int main(){
	vector<int> v1 = {1,2};
	vector<int> v2 = {4,5,6};

	Solution* s = new Solution();
	cout<<s->findMedianSortedArrays(v1,v2)<<endl;

	return 0;
}
