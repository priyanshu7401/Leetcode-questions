# Write your MySQL query statement below

select 
    d.name 'Department',
    e.name 'Employee',
    e.salary 'Salary'
from 
    Employee e,
    Department d
where 
    e.DepartmentId=d.Id
AND
    (e.DepartmentId,Salary) IN (Select DepartmentId,Max(Salary)
    From 
    Employee 
    Group by departmentId)