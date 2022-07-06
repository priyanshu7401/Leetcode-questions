# Write your MySQL query statement below


select 
      request_at "Day",Round(count(if(status!='completed',true,null))/count(*),2)'Cancellation Rate'
from 
    Trips as t 
where t.client_id in (select users_id from Users where banned!='Yes')
and t.driver_id in (select users_id from Users where banned!='Yes')
and request_at between "2013-10-01" and "2013-10-03"
group by
    request_at