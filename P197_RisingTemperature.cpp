# Write your MySQL query statement below
select w1.Id as Id 
from Weather as w1,Weather as w2 
where w1.RecordDate=AddDate(w2.RecordDate,1) and w1.Temperature>w2.Temperature
