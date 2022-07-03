# Write your MySQL query statement below


SELECT e1.name 'Employee' from   Employee e1,Employee e2
where e1.managerId=e2.id && e1.salary>e2.salary