# Write your MySQL query statement below

# how many employess are there having distinct salary greater than that employee



select  
    d.name'Department',e1.name 'Employee',e1.salary 'Salary'
from
    employee e1 join 
    department d on e1.departmentId=d.id
where 
    (select
        count(distinct e2.salary)
     from    
        Employee e2
     where 
        e2.salary>e1.salary and e1.departmentId=e2.departmentId)<3;