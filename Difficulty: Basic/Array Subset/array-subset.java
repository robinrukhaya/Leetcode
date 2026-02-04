import java.util.*;

class Solution {
    public static boolean isSubset(int[] a, int[] b) {

        HashMap<Integer, Integer> map = new HashMap<>();

        // Store frequency of elements in array a
        for (int x : a) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        // Check elements of array b
        for (int x : b) {
            if (!map.containsKey(x) || map.get(x) == 0) {
                return false;
            }
            map.put(x, map.get(x) - 1);
        }

        return true;
    }
}
