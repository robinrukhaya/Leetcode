/*Complete the Function below*/
// User function Template for Jav

class Solution {
    public static boolean isPalinArray(int[] arr) {

        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            int original = num;
            int rev = 0;

            while (num > 0) {
                rev = rev * 10 + (num % 10);
                num = num / 10;
            }

            if (rev != original) {
                return false;
            }
        }

        return true;
    }
}
