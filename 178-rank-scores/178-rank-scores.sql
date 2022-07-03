# Write your MySQL query statement below
Select 
Score,(SELECT 
count(distinct Score) 
FROM Scores where Score>=s.Score) 'rank'
From Scores as s
Order by Score DESC