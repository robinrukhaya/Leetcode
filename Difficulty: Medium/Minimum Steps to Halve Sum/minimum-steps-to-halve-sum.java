import java.util.*;

class Solution {
    
    public int minOperations(int[] arr) {
        
        PriorityQueue<Double> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        double sum = 0;
        
        // Calculate total sum and build max heap
        for (int num : arr) {
            sum += num;
            maxHeap.add((double) num);
        }
        
        double target = sum / 2.0;
        double currentSum = sum;
        
        int operations = 0;
        
        // Greedy approach
        while (currentSum > target) {
            
            double largest = maxHeap.poll();
            double half = largest / 2.0;
            
            currentSum -= half;
            maxHeap.add(half);
            
            operations++;
        }
        
        return operations;
    }
}