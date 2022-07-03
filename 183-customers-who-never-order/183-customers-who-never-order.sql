# Write your MySQL query statement below


select 
    name 'Customers'
from
    Customers
where 
    id  not in (select Customers.id from Customers JOIN Orders on Customers.id=Orders.customerId)