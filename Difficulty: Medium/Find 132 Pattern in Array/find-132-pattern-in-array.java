class Solution {

    public boolean has132Pattern(int[] arr) {

        int n = arr.length;

        for (int i = 0; i < n - 2; i++) {

            for (int j = i + 1; j < n - 1; j++) {

                for (int k = j + 1; k < n; k++) {

                    if (arr[i] < arr[j] && arr[j] > arr[k] && arr[i] < arr[k]) {
                        return true;
                    }

                }

            }

        }

        return false;
    }
}