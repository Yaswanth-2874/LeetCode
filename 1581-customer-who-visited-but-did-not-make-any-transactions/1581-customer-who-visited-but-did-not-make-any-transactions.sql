SELECT distinct 
customer_id, count(*) as count_no_trans 
from Visits 
where visit_id not in 
    (Select Distinct visit_id 
     from Transactions) 
group by customer_id;