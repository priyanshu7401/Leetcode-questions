class Solution {
public:
    string intToRoman(int n) 
    {
    string ONES[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string TENS[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string HUNDREDS[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string THOUSANDS[4]={"","M","MM","MMM"};
    string ans="";
    ans+=THOUSANDS[n/1000];
    n%=1000;
    ans+=HUNDREDS[n/100];
    n%=100;
    ans+=TENS[n/10];
    n%=10;
    ans+=ONES[n];
    return ans;    
    }
};