/*

Leetcode Question
58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

*/


import java.util.Scanner;

class Solution {
    public int lengthOfLastWord(String s) {
        
        s = s.trim();
        int l = s.lastIndexOf(" ");
        return s.length() - l - 1;
        /*

        iss method se kar rahe the error aa raha tha bina trim use kiye.
        
        String str = s, r = "";
        str = str.toUpperCase();
        int l = str.length();
        for(int i = l - 1; i >= 0; i--){
            if(str.charAt(i) == ' ')
                i--;
            else{
                str = str.substring(0, i);
                r = str.substring(str.lastIndexOf(" ") + 1);
            }
        }
        return r.length();
        */
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        Solution sol = new Solution();
        int result = sol.lengthOfLastWord(input);
        System.out.println("Length of last word: " + result);
    }
}
