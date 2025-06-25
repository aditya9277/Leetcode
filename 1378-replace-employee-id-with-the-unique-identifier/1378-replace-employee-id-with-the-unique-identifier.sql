# Write your MySQL query statement below


select eu.unique_id , e.name from Employees as e
LEFT JOIN EmployeeUNI as eu ON e.id = eu.id