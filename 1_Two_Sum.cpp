#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> nums;
    nums.push_back(13);
    nums.push_back(16);
    nums.push_back(123);
    nums.push_back(67);
    nums.push_back(6);
    
    int target = 73;
    vector<int>::iterator begin = nums.begin(),end = nums.end(),current;

    vector<int> re;
    bool found = false;
    while(!found){
        current=begin;
        int difference = target - *begin;
        vector<int>::iterator finding = find(++begin,end,difference);
        if(finding!=end){
            found = true;
            re.push_back(*current);
            re.push_back(*finding);
        }
    }
    cout << re[0] << ':' << re[1] << endl;
    return 0;
}