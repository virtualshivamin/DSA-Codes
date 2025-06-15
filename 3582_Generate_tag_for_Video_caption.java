/*


Leetcode question 
3582. Generate Tag for Video Caption
Solved
Easy
premium lock icon
Companies
Hint
You are given a string caption representing the caption for a video.

The following actions must be performed in order to generate a valid tag for the video:

Combine all words in the string into a single camelCase string prefixed with '#'. A camelCase string is one where the first letter of all words except the first one is capitalized. All characters after the first character in each word must be lowercase.

Remove all characters that are not an English letter, except the first '#'.

Truncate the result to a maximum of 100 characters.

Return the tag after performing the actions on caption.

 

Example 1:

Input: caption = "Leetcode daily streak achieved"

Output: "#leetcodeDailyStreakAchieved"

Explanation:

The first letter for all words except "leetcode" should be capitalized.

Example 2:

Input: caption = "can I Go There"

Output: "#canIGoThere"

Explanation:

The first letter for all words except "can" should be capitalized.

Example 3:

Input: caption = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"

Output: "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"

Explanation:

Since the first word has length 101, we need to truncate the last two letters from the word.

 

Constraints:

1 <= caption.length <= 150
caption consists only of English letters and ' '.


*/

public class Solution {
    
    public String generateTag(String caption) {
        if (caption == null || caption.trim().isEmpty()) {
            return "#";
        }

        caption = caption.trim().toLowerCase();

        String tag = "";
        boolean makeUpper = false; // for camelCase: first word stays lowercase

        for (char c : caption.toCharArray()) {
            if (Character.isWhitespace(c)) {
                makeUpper = true;
            } else if (makeUpper) {
                tag = tag + Character.toUpperCase(c);
                makeUpper = false;
            } else {
                tag = tag + c;
            }
        }

        // Convert first character to lowercase (for camelCase)
        if (!tag.isEmpty()) {
            tag = Character.toLowerCase(tag.charAt(0)) + tag.substring(1);
        }

        String result = "#" + tag;

        // Trim to max 100 characters
        if (result.length() > 100) {
            result = result.substring(0, 100);
        }

        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        String[] testCaptions = {
            "Leetcode daily streak achieved",
            "can I Go There",
            "    THIS is a TesT     ",
            "    ",
            "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
        };

        for (String caption : testCaptions) {
            System.out.println("Input: \"" + caption + "\"");
            System.out.println("Output: " + sol.generateTag(caption));
            System.out.println();
        }
    }
}
