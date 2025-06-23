# Write your MySQL query statement below


select id, movie, description, rating from Cinema WHERE (id%2) !=0 AND description!='boring' order by rating desc