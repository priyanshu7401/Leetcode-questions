# Write your MySQL query statement below


SELECT DISTINCT num as 'ConsecutiveNums' from logs l1

where (SELECT num from logs l2 where l2.id=l1.id+1)=num and (SELECT num from logs l3 where l3.id=l1.id+2)=num 