class Solution {
    static int minParentheses(String S) {
        
        int open = 0;
        int add = 0;

        for(int i = 0; i < S.length(); i++) {
            char c = S.charAt(i);

            if(c == '(') {
                open++;
            }
            else {
                if(open > 0) {
                    open--;
                } else {
                    add++;
                }
            }
        }

        return add + open;
    }
}