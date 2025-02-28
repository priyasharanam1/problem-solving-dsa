# Write your MySQL query statement below
select contest_id, round(count(distinct(r.user_id))/(select count(*) from Users )*100,2) as percentage
from Register r
left join Users u
on r.user_id=u.user_id
group by contest_id
order by percentage desc, contest_id asc