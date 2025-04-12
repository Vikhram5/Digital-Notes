class Solution {
    public:
        vector<int>getNSL(vector<int>&nums){
            int n=nums.size();
            stack<int>st; vector<int>left(n);
    
            for(int i=0;i<n;i++){
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }
                left[i]=st.empty()?-1:st.top();
                st.push(i);
            }
            return left;
        }
    
        vector<int>getNSR(vector<int>&nums){
            int n=nums.size();
            stack<int>st; vector<int>right(n);
    
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    st.pop();
                }
                right[i]=st.empty()?n:st.top();
                st.push(i);
            }
            return right;
        }
    
        int solve(vector<int>&height){
            int n=height.size();
    
            vector<int>NSR=getNSR(height);
            vector<int>NSL=getNSL(height);
            vector<int>width(n);
    
            for(int i=0;i<n;i++){
                width[i]=NSR[i]-NSL[i]-1;
            }
    
            int maxArea=0;
            for(int i=0;i<height.size();i++){
                maxArea=max(maxArea,height[i]*width[i]);
            }
    
            return maxArea;
        }
    
        int maximalRectangle(vector<vector<char>>& matrix) {
            int m=matrix.size(),n=matrix[0].size();
            int maxArea=0;
            vector<int>height(n,0);
    
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]=='0') height[j]=0;
                    else height[j]+=1;
                }
                maxArea=max(maxArea,solve(height));
            }
            return maxArea;
        }
    };