**Approach1**
1)**Type**:problem looks like that of backtracking (because of constraints).
2)**states :**[need,i]
3) i is for current offer.
4) for every i decrease the needs - j*(elements we can get in offer)
​
**Approach2**
1)no need for i. we can simply use need as the state only and every time check for all possible values of i. see the code
​