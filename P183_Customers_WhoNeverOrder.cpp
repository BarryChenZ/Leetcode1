# Write your MySQL query statement below
select Name as Customers from
Customers as a
left join
Orders as b
on a.Id = b.CustomerId
where b.CustomerId is null