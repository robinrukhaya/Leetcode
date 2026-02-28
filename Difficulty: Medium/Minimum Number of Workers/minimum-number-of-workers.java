import java.util.*;

class Solution {

    public int minMen(int[] arr) {
        
        int n = arr.length;
        List<int[]> intervals = new ArrayList<>();
        
        // Step 1: Create intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int start = Math.max(0, i - arr[i]);
                int end = Math.min(n - 1, i + arr[i]);
                intervals.add(new int[]{start, end});
            }
        }
        
        // Step 2: Sort intervals by start
        Collections.sort(intervals, (a, b) -> a[0] - b[0]);
        
        int count = 0;
        int index = 0;
        int currentEnd = 0;
        
        // Step 3: Greedy interval covering
        while (currentEnd < n) {
            
            int farthest = -1;
            
            while (index < intervals.size() && intervals.get(index)[0] <= currentEnd) {
                farthest = Math.max(farthest, intervals.get(index)[1]);
                index++;
            }
            
            if (farthest < currentEnd) {
                return -1; // Cannot cover entire day
            }
            
            count++;
            currentEnd = farthest + 1;
        }
        
        return count;
    }
}