# Write your MySQL query statement below


SELECT d.name as Department,e.name as Employee,e.salary as Salary
FROM employee  e
 JOIN (
    SELECT departmentId,MAX(salary) as salary
FROM  employee 
GROUP BY departmentId
) x
ON e.departmentId=x.departmentId AND e.salary=x.salary
JOIN Department as d
ON d.id=e.departmentId





