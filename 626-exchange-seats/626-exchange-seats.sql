# Write your MySQL query statement below


select 
    (case 
        when mod(id,2)!=0 && id!=counts then id+1
        when mod(id,2)!=0 && id=counts then id
       else id-1
        end )id,
       
student 
from 
    seat,
    (select count(*)'counts' from Seat) as seat_counts

order by id ASC;