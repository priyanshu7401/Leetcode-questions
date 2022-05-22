class Solution {
public:
    int countSubstrings(string s)
    {
        int count=0,len=s.length();
        
     for(int i=0;i<len;i++)//for substrings with only 1 character as palindromic subcentre
     {
         count+=1;//increment in counter as after every increment we are getting single palindromic character
         int j=i-1;
         int k=i+1;
         while(j>=0&&k<len)
         {
             if(s[j]==s[k])
             {
                 count++;
                 j--;
                 k++;
             }
             else
             {
                 break;
             }
         }
         //----------------------------------------------------------------------//
         if(s[i+1]==s[i])//for the checking strings with even length  as they are palindromic or not
          {
             count+=1;
             int j=i-1;
             int k=i+2;
             while(j>=0&&k<len)
             {
                 if(s[j]==s[k])
                 {
                     count++;
                     j--;
                     k++;
                 }
                 else
                 {
                     break;
                 }
             }
         }
     }

        return count;
    }
};