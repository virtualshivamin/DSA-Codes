/*

Leetcode question 

5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.

*/

class Solution {
    public boolean Palindrome(String p)
    {
        for (int i = 0; i < p.length() / 2; i++) {
            if (p.charAt(i) != p.charAt(p.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    public String longestPalindrome(String s) {
        int l = s.length(); 
        String r = "",sub;
        int x = 0;
        for (int i = 0; i < l; i++) {
            for (int j = l - 1; j >= i + x; j--) { // i+x for x jitna length se bada hi chaiye 
                sub = s.substring(i, j + 1);
                if (Palindrome(sub)) {
                    r = sub;
                    x = sub.length();
                    break; // x se chota check karne ki jarurat nahi hai 
                }
            }
        }
        return r;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();

        String input1 = "babad";
        String input2 = "cbbd";

        System.out.println("Input 1: " + input1);
        System.out.println("Longest Palindromic Substring: " + sol.longestPalindrome(input1));

        System.out.println("\nInput 2: " + input2);
        System.out.println("Longest Palindromic Substring: " + sol.longestPalindrome(input2));

    }
}
