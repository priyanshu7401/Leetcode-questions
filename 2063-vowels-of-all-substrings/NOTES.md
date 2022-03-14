Two possible solution:
​
my approach:
1) if vowel at index i make last as last+i+1(last indicates the total vowels occured for last character).
2) add it to prefix

​
discussion approach:
1) for each vowel at i it can be present at 0<=x<=i ||i<=y<n.

2)Therefore **(i+1) * (n-i)** choices for a vowel to occur in the string.(**thats why it was called maths**).

3)simply add it to result.
​
