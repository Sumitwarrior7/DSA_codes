/*
Enter your query here.
*/
select s.hacker_id as hid, h.name as hnm, s.submission_id as sbid, max(s.score) as mxscr
from Submissions as s
left join Hackers as h
on s.hacker_id = h.hacker_id
group by s.challenge_id;