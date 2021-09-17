#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        bool odd;
        if(size%2){
            odd = true;
        }
        else{
            odd = false;
        }
        if(odd){
            int target = size/2;
            int one=0,two=0,num;
            while(one+two<=target){
                if(one==nums1.size()){
                    num = nums2[two++];
                }
                else if(two == nums2.size()){
                    num = nums1[one++];
                }
                else if(nums1[one]<nums2[two]){
                    num = nums1[one++];
                }
                else{
                    num = nums2[two++];
                }
            }
            return num;
        }
        else{
            int target = size/2;
            int one=0,two=0,num1=-1,num2=-1;
            while(one+two<=target){
                if(one==nums1.size()){
                    num2 = num1;
                    num1 = nums2[two++];
                }
                else if(two == nums2.size()){
                    num2 = num1;
                    num1 = nums1[one++];
                }
                else if(nums1[one]<nums2[two]){
                    num2 = num1;
                    num1 = nums1[one++];
                }
                else{
                    num2 = num1;
                    num1 = nums2[two++];
                }
            }
            return (static_cast<double>(num1)+static_cast<double>(num2))/2;
        }

    }
};

int main(){
    vector<int> nums1,nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(4);
    nums1.push_back(5);
    nums2.push_back(3);
    nums2.push_back(6);

    Solution solution;
    cout << solution.findMedianSortedArrays(nums1,nums2) << endl;;
    return 0;
}