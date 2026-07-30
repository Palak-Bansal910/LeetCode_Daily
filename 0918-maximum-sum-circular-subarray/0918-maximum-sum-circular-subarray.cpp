class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = arr[0], minSum = arr[0];

        for(int i = 0; i < n; i++){
            currMaxSum = max(currMaxSum + arr[i],arr[i]);
            maxSum = max(currMaxSum,maxSum);

            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(currMinSum,minSum);

            totalSum += arr[i];
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;
        
        if(minSum == totalSum){
            return normalSum;
        }
        return max(normalSum,circularSum);
    }
};