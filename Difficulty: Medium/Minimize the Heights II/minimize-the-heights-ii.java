import java.util.*;

class Solution {
    public static int getMinDiff(int[] arr, int k) {

        int n = arr.length;
        Arrays.sort(arr);

        
        int ans = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 1; i < n; i++) {

            
            if (arr[i] - k < 0)
                continue;

            int minHeight = Math.min(smallest, arr[i] - k);
            int maxHeight = Math.max(largest, arr[i - 1] + k);

            ans = Math.min(ans, maxHeight - minHeight);
        }

        return ans;
    }
}