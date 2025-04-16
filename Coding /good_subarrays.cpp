
// 2537. Count the Number of Good Subarrays

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int i=0,j=0;
            int n=nums.size();
            unordered_map<int,int>mp;
            long long res=0;
            long long pairs=0;
    
            while(j<n){
                pairs+=mp[nums[j]];
                mp[nums[j]]++;
    
                while(pairs>=k){
                    res+=(n-j);
                    mp[nums[i]]--;
                    pairs-=mp[nums[i]];
                    i++;
                }
    
                j++;
            }
            return res;
        }
    };
    
    