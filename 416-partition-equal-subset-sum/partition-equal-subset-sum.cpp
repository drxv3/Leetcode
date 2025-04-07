

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int resultant_sums = 0 ;

        for (auto x : nums)
            resultant_sums +=x;
        
        if(resultant_sums % 2) return false;

        resultant_sums /= 2;
        

        vector<bool> dp(resultant_sums+1,false);
        dp[0]=true;
        for(auto x:nums){
            for(int i=resultant_sums;i>=x;i--){
                dp[i] = dp[i] || dp[i-x] ;
            }
        }
        return dp[resultant_sums];
    }
};