Two possible solution:
​
my approach:
if vowel at index i make last as last+i+1(last indicates the total vowels occured for last character).
add it to prefix

​
discussion approach:
for each vowel at i it can be present at 0<=x<=i ||i<=y<n
Therefore **(i+1) * (n-i)** choices for a vowel to occur in the string.(**thats why it was called maths**).
simply add it to result.
​
