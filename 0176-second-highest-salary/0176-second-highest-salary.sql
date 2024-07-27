# Write your MySQL query statement below
Select max(salary) as SecondHighestSalary from
(select salary from employee where salary < (select max(salary) from employee)) emp;