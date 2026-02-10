class Solution {
    // Function to partition the array around the range such
    // that array is divided into three parts.
    public void threeWayPartition(int arr[], int a, int b) {
        // code here
        int low = 0;
        int mid = 0;
        int high = arr.length -1;
        
        while (mid <= high) {
            if (arr[mid] < a) {
                int temp = arr[low];
                arr[low]= arr[mid];
                arr[mid] = temp;
                
                low++;
                mid++;
            }
            else if (arr[mid]>b) {
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
            
                high--;
            }
            else {
                mid++;
            }
        }
    }
}