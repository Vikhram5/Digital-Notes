// frog-jump/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
    public:
        int n;
        unordered_map<int,unordered_set<int>>visited;
        unordered_set<int>st;
    
        bool solve(vector<int>&nums,int i,int k){
            if(k<=0 || st.find(i)==st.end()) return false;
            if(i==nums[n-1]) return true;
            if(visited[i].count(k)) return false; //visited or not 
    
            visited[i].insert(k);
    
            if(solve(nums,i+k-1,k-1)) return true;
            if(solve(nums,i+k,k)) return true;
            if(solve(nums,i+k+1,k+1)) return true;
    
            return false;

            //return earlier if the condition is failed 
    
        }
    
        bool canCross(vector<int>& stones) {
            n=stones.size();
            for(int& num:stones) st.insert(num);
            return solve(stones,1,1);
        }
    };