#include<iostream>
using namespace  std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merge = "";
        int j = 0;
        int l1 = word1.length();
        int l2 = word2.length();
        if (l1 > l2) {
            for (int i = 0; i < l1; i++) {
                merge += word1[i];
                if(j != l2){
                merge += word2[i];
                j++;
                }
                
            }
        } else {
            for (int i = 0; i < l2; i++) {
                if(j != l1){
                 merge += word1[i];
                 j++;
                }
                
                merge += word2[i];
            }
        }
        return merge;
    }
};

int main(){
    Solution sol;
    cout<<sol.mergeAlternately("abcd" , "pq");

}
