# Write your MySQL query statement below


Select email from
(Select email,count(email)as num from Person group by email)as t
where num>1
