class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int sum = 0;
        
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                string temp = s.substr(i, j - i + 1);
                sum += stoi(temp);
            }
        }
        
        return sum;
    }
};


[Better Approach] Using Dynamic Programming - O(n) Time and O(n) Space
We can solve this problem by using dynamic programming. We can write a summation of all substrings on basis of the digit at which they are ending in that case, 
Sum of all substrings = sumofdigit[0] + sumofdigit[1] + sumofdigit[2] … + sumofdigit[n-1] where n is length of string.
Where sumofdigit[i] stores the sum of all substring ending at ith index digit, in the above example, 

Example: s = "6759"

sumofdigit[0] = 6 = 6
sumofdigit[1] = 7 + 67  = 74
sumofdigit[2] = 5 + 75  + 675 = 755
sumofdigit[3] = 9 + 59  + 759 + 6759  = 7586
Result = 8421

Now we can get the relation between sumofdigit values and can solve the question iteratively. Each sumofdigit can be represented in terms of previous value as shown below, For above example,

sumofdigit[3] = 9 + 59  + 759 + 6759
                     = 9 + 50 + 9 + 750 + 9 + 6750 + 9
                     = 9*4 + 10*(5 + 75 + 675)
                     = 9*4 + 10*(sumofdigit[2])

In general, sumofdigit[i]  =  (i+1)*s[i] + 10*sumofdigit[i-1]

Follow the given steps to solve the problem:

Declare an array of size n to store the sum of previous digits, processed so far, and a variable result
Traverse over the string and for every character
Set sumOfDigit[i] = (i + 1) * toDigit(s[i]) + 10 * sumOfDigit[i-1]
Add the value of sumOfDigit[i] to result
Return result
