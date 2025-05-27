******************************************************
//   Understanding the problem and the constraints: The problem involves rotations, i.e., moving the leftmost character to the rightmost position. It's also mentioned that the two strings s and goal are of the same length.

// Observing examples: If we manually perform the rotations and observe the results, we may notice a pattern. For example, for s = "abcde", the rotations would be: "bcdea", "cdeab", "deabc", "eabcd", and back to "abcde".

// Noticing patterns and forming insights: From the examples, we might notice that all the rotated strings are substrings of s + s = "abcdeabcde". Thus, we can check if goal is a substring of s + s to see if s can be rotated to form goal.

// Verifying the insight: We can confirm this insight by trying various examples and corner cases, and seeing if this pattern holds true in every case.

******************************************************
  


class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.length();

        for(int i = 0; i < n; i++){
            
            string temp = s.substr(1);
            temp += s[0];

            if(temp == goal) return true;

            s = temp;
        }

        return false;
    }
};
