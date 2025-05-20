/*

Leetcode question 

848. Shifting Letters
Solved
Medium
Topics
Companies
You are given a string s of lowercase English letters and an integer array shifts of the same length.

Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

Return the final string after all such shifts to s are applied.

 

Example 1:

Input: s = "abc", shifts = [3,5,9]
Output: "rpl"
Explanation: We start with "abc".
After shifting the first 1 letters of s by 3, we have "dbc".
After shifting the first 2 letters of s by 5, we have "igc".
After shifting the first 3 letters of s by 9, we have "rpl", the answer.
Example 2:

Input: s = "aaa", shifts = [1,2,3]
Output: "gfd"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
shifts.length == s.length
0 <= shifts[i] <= 109

 */



public class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int n = s.length();
        char[] chars = s.toCharArray();
        long totalShift = 0;

        for (int i = n - 1; i >= 0; i--) {
            totalShift = (totalShift + shifts[i]) % 26;
            int newChar = (chars[i] - 'a' + (int)totalShift) % 26;
            chars[i] = (char)('a' + newChar);
        }

        return new String(chars);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        // Sample input
        String s = "mkgfzkkuxownxvfvxasy";
        int[] shifts = {
            505870226, 437526072, 266740649, 224336793, 532917782, 311122363, 567754492, 595798950,
            81520022, 684110326, 137742843, 275267355, 856903962, 148291585, 919054234, 467541837,
            622939912, 116899933, 983296461, 536563513
        };

        String result = sol.shiftingLetters(s, shifts);
        System.out.println("Output: " + result);
    }
}
