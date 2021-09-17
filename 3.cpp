#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=1;
        if(s.length() == 0){return 0;}
        string::iterator s_start = s.begin();
        string::iterator s_end = s.end();
        for( ;s_start!=s_end;s_start++){
            string::iterator finding = find(s_start+1,s_end,*s_start);
            if(finding - s_start>length){
                for(int i=1;i<=finding-s_start;i++){
                    for(string::iterator temp = s_start; temp!=s_start+i ; temp++){
                        if(count(s_start,s_start+i,*temp)>1){
                            break;
                        }
                        else if((temp+1) == (s_start+i)){
                            if(i>length){
                                length = i;break;
                            }
                        }
                    }
                }
            }
        }
        return length;
    }
};

int main(){
    string input;
    cin >> input;
    Solution solution;
    cout << solution.lengthOfLongestSubstring(input) << endl;
    return 0;
}