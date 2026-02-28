import java.util.*;

class Solution {

    public ArrayList<Integer> prevSmaller(int[] arr) {
        
        int n = arr.length;
        ArrayList<Integer> result = new ArrayList<>();
        
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < n; i++) {
            
            while (!stack.isEmpty() && stack.peek() >= arr[i]) {
                stack.pop();
            }
            
            if (stack.isEmpty()) {
                result.add(-1);
            } else {
                result.add(stack.peek());
            }
            
            stack.push(arr[i]);
        }
        
        return result;
    }
}