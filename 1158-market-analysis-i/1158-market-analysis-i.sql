# Write your MySQL query statement below



select user_id'buyer_id',join_date,sum( case   
                                    when order_date between "2019-01-01" and "2019-12-31" then 1
                                    else 0
                              end )'orders_in_2019'
# select *
from 
     Users u left join Orders o  on buyer_id=user_id
group by u.user_id
# having o.order_date between "2019-01-01" and "2019-12-31"

# select u.user_id as buyer_id, join_date, sum(case when left(order_date,4) = '2019' then 1 else 0 end) as orders_in_2019
# from Users u left join Orders o on u.user_id = o.buyer_id
# group by u.user_id

