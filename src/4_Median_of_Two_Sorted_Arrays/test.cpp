#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
		int left;
		int lv1,rv1,lv2,rv2;  //index
		int ml1,mr1,ml2,mr2;  //index
		bool real1,real2;  //0->num1 ; 1->num2
		
		double getMid(int len1,int len2){
			return (len1+len2)/2;
		}
		
		int max(int a,int b){
			return a>b ? a : b;
		}
		
		void refreshM(){  
			mr1 = (rv1+1+lv1)/2;
			ml1 = lv1==rv1 ? lv1 : mr1-1;
			ml2 = (rv2+lv2)/2;
			mr2 = lv2==rv2 ? lv2 : ml2+1;
		}
		
		void reduce(vector<int>* nums1,vector<int>* nums2){
            vector<int> *v1,*v2;
            if(real1) v1 = nums2;
            else v1 = nums1;
            if(real2) v2 = nums2;
            else v2 = nums1;

            //cout<<"test2: "<<lv1<<" , "<<rv1<<" , "<<lv2<<" , "<<rv2<<endl;
            //cout<<"test3: "<<ml1<<" , "<<mr1<<" , "<<ml2<<" , "<<mr2<<endl;
            //cout<<"test4: "<<(*v1)[ml1]<<" , "<<(*v1)[mr1]<<" , "<<(*v2)[ml2]<<" , "<<(*v2)[mr2]<<endl;
			if((*v1)[ml1] < (*v2)[ml2]){  //ml1 is 1
                left += ml1-lv1+1;
                //cout<<"test5: "<<left<<endl; 
				if((*v1)[mr1] > (*v2)[mr2]){  //mr1 is 4
                    lv1 = lv2;
                    rv1 = ml2;
                    lv2 = mr2;                    
                    if(real1 != real2){
                        real1 = 1; 
                    }
				}else{  //mr2 is 4
				    lv1 = mr1;
                    rv2 = ml2;    
				}
			}else{  //ml2 is 1
                left += ml2-lv2+1;
                //cout<<"test5: "<<left<<endl; 
				if((*v1)[mr1] > (*v2)[mr2]){  //mr1 is 4
                    rv1 = ml1;
                    lv2 = mr2;                    
				}else{  //mr2 is 4
				    rv1 = ml1;
                    lv2 = mr1;
                    rv2 = rv1;
                    if(real1 != real2){
                        real2 = 0;
                    }
				}
			}
		}
		
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            left = 0;
			lv1 = lv2 = 0;
			rv1 = nums1.size()-1;
			rv2 = nums2.size()-1;
			
			real1 = 0;
			real2 = 1;
			
			while(lv1!=rv1 || lv2!=rv2){
				refreshM();
                reduce(&nums1,&nums2);				
			}
            //cout<<"test1: "<<real1<<" , "<<real2<<endl;
            //cout<<"test2: "<<lv1<<" , "<<rv1<<" , "<<lv2<<" , "<<rv2<<endl;
            //cout<<"test3: "<<ml1<<" , "<<mr1<<" , "<<ml2<<" , "<<mr2<<endl;
            //cout<<"test4: "<<nums1[ml1]<<" , "<<nums1[mr1]<<" , "<<nums2[ml2]<<" , "<<nums2[mr2]<<endl;
            cout<<" real1: "<<real1<<" , real2: "<<real2<<endl; 
            cout<<"index1: "<<lv1<<" ,index2: "<<lv2<<endl; 
            cout<<"left: "<<left<<endl; 

			int len1 = nums1.size(); 
			int len2 = nums2.size(); 
            cout<<" len1: "<<len1<<" , len2: "<<len2<<endl; 
            vector<int> *v1,*v2;
            if(real1) v1 = &nums2;
            else v1 = &nums1;
            if(real2) v2 = &nums2;
            else v2 = &nums1;
			if((len1+len2)%2){  //odd
				int mid = (len1+len2)/2 + 1;
				if(mid-left == 1){
					return max((*v1)[lv1],(*v2)[lv2]);
				}else if(mid-left == 2){
					return max((*v1)[lv1],(*v2)[lv2]);
				}
			}else{
				return ((*v1)[lv1]+(*v2)[lv2])/2;
			}
			return 0;
        }
};

int main(){
	vector<int> v1 = {1,2,3};
	vector<int> v2 = {4,5,6,7,8,9};

	Solution* s = new Solution();
	cout<<s->findMedianSortedArrays(v1,v2)<<endl;

	return 0;
}
