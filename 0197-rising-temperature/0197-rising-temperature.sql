# Write your MySQL query statement below
select a.id
from Weather a, Weather b
where a.recordDate = b.recordDate + interval 1 day and a.temperature > b.temperature