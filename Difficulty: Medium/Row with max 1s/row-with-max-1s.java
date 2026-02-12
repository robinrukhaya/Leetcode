class Solution {
    int rowWithMax1s(int arr[][]) {

        int n = arr.length;
        int m = arr[0].length;

        int row = 0;
        int col = m - 1;
        int maxRow = -1;

        while (row < n && col >= 0) {

            if (arr[row][col] == 1) {
                maxRow = row;
                col--;      
            } else {
                row++;      
            }
        }

        return maxRow;
    }
}
