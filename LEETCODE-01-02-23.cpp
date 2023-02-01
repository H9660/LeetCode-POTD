// Problem: https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
 
        string ans="",finalstring="";
        for(int i=0;i<str1.length();i++)
        {
             ans+=str1[i];
//           At every stage I will check if I can from the two strings with the given GCD. If yes then I can store the answer in a 
//           final variable. I keep flag variable to see if I cannot get any gcd.
             string one="", two="";
             for(int i=0;i<str1.length()/ans.length();i++)
                 one+=ans;
             
              for(int i=0;i<str2.length()/ans.length();i++)
                 two+=ans;
               
             if(one==str1 && two==str2)
             finalans=ans;
        } 
        
        if()
        if(finalans!=str1)
        return "";
       
    }
};

