#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        
        vector<int> ans;
        unordered_set<int> st;
        
        for(int i = 0; i < a.size(); i++){
            st.insert(a[i]);
        }
        
        for(int i = 0; i < b.size(); i++){
            st.insert(b[i]);
        }
        
        for(auto it : st){
            ans.push_back(it);
        }
        
        return ans;
    }
};
