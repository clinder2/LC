class Solution {
    public String convert(String s, int numRows) {
        int diag = numRows - 2;
        String ans = "";
        int numRows2 = numRows;
        if (diag < 0 || s.length() < 3) {
            ans = s;
        } else {
            for (int i = 0; i < numRows2 - 1; i++) {
                int j = i;
                int k = 2 * i;
                boolean temp = true;
                while (j < s.length()) {
                    ans += s.charAt(j);
                    if (temp && i != numRows - 1) {
                        j = j + numRows + diag;
                        if (j < s.length()) {
                            ans += s.charAt(j);
                        }
                        temp = false;
                    }
                    if (j + k >= s.length()) {
                        j = s.length();
                    }
                    if (i != 0 && s.length() > k + j) {
                        j = j + k;
                        ans += s.charAt(j);
                    }
                    j = j + numRows + diag;
                }
                numRows--;
                diag--;
                if (i == numRows - 2) {
                    //diag = 0;
                    //numRows = 0;
                }
            }
            int k2 = numRows2 - 1;
            int k3 = k2 * 2;
            while (k2 < s.length()) {
                ans += s.charAt(k2);
                k2 += k3;
            }
        }
        return ans;
    }
}