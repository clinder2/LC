package hashtable;

public class k-diffPairsInAnArray {
    class Solution {
        public int findPairs(int[] nums, int k) {
            Map<Integer, Integer> h = new HashMap();
            int ans = 0;
            for (int i : nums) {
                if (!h.containsKey(i)) {
                    h.put(i, 1);
                    if (k != 0) {
                        ans += h.getOrDefault(i+k, 0) + h.getOrDefault(i-k, 0);
                    }
                } else {
                    if (k == 0 && h.get(i) == 1) {
                        h.put(i, 2);
                        ans++;
                    }
                }
            }
            return ans;
        }
    }
}
