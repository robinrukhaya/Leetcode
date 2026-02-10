
class Solution {
    public static int minSwap(int[] arr, int k) {

        int n = arr.length;

        int good = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                good++;
            }
        }

        if (good == 0 || good == n) {
            return 0;
        }

        int bad = 0;
        for (int i = 0; i < good; i++) {
            if (arr[i] > k) {
                bad++;
            }
        }

        int minSwaps = bad;

        int i = 0, j = good;
        while (j < n) {

            if (arr[i] > k) {
                bad--;
            }
            if (arr[j] > k) {
                bad++;
            }

            minSwaps = Math.min(minSwaps, bad);

            i++;
            j++;
        }

        return minSwaps;
    }
}
