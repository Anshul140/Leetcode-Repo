# Write your MySQL query statement below
SELECT DT.name as Department, ET.name as Employee, ET.Salary as Salary
FROM EMPLOYEE as ET JOIN DEPARTMENT as DT
ON ET.departmentId = DT.id
WHERE ET.salary = (SELECT MAX(salary) from Employee where departmentId = ET.departmentId)

                  