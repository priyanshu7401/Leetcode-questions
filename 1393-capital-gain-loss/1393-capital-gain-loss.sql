# Write your MySQL query statement below


select 
    s.stock_name,(SellPrice-BuyPrice)'capital_gain_loss'
    
from
(select 
    stock_name, sum(price)'BuyPrice'
from
    Stocks
where 
    operation='Buy'
Group by
    stock_name) as b join
    
(select 
    stock_name, sum(price)'SellPrice'
from
    Stocks
where 
    operation='Sell'
Group by
    stock_name) as s

where s.stock_name=b.stock_name




