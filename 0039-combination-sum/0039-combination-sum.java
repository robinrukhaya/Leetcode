import java.util.*;

class Solution {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        helper(candidates, target, 0, new ArrayList<>(), ans);
        return ans;
    }

    private void helper(int[] arr, int target, int index,
                        List<Integer> list, List<List<Integer>> ans) {

        if (target == 0) {
            ans.add(new ArrayList<>(list));
            return;
        }

        if (target < 0 || index == arr.length) return;

        
        list.add(arr[index]);
        helper(arr, target - arr[index], index, list, ans);

        
        list.remove(list.size() - 1);

        
        helper(arr, target, index + 1, list, ans);
    }
}
