# Write your MySQL query statement below
Select d.Name as Department, e.Name as Employee, e.salary as Salary
from Employee e
Join Department d
on e.DepartmentId = d.id
join (
Select
e.DepartmentId, max(e.salary) salary
from Employee e
group by e.Departmentid ) as t
on e.departmentId = t.departmentId and e.salary = t.salary
