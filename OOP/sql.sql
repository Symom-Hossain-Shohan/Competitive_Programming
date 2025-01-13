create table instructor(
    id char(5), 
    nam varchar(20),
    dept_name varchar(20),
    salary numeric(8,2),
)


create table instructor(
    id char(5) not null,
    nam varchar(20) not null,
    dept_name varchar(20), 
    salary numeric(8, 2), 

    primary key(id),
    foreignt key (dept_name) references department(dept_name), 
)

insert into instructor values('10101', 'Srinivasan', 'Comp. Sci.', 65000.00)

delete from instructor    

drop table instructor

alter table instructor add email varchar(20)

alter table instructor drop email

select * 
from instructor
where dept_name = 'Comp. Sci.'

select id, nam, salary/12 as monthly_salary
from instructor


select nam 
from instructor
where salary > 70000


select nam, id
from instructor
where dept_name = 'Comp. Sci.' and salary > 70000

select nam, instructor_id

from instructor, teaches 
where instructor.id = teaches.id  


select nam, instructor_id
from instructor, teaches 
where instructor.id = teaches.id and dept_name = 'Art'


select distinct T.name 
from instructor as T, instructor as S
where T.salary > S.salary and s.dept_name = 'Comp. Sci.'


select name 
from instructor 
where name like '%in'


select name 
from instructor 
where name like 'in%'


select name 
from instructor 
where name like '%in%'


select distinct name 
from instructor 
order by name


(select course_id 
from course 
where semseter = 'Fall' and year = 2017 )
union 
(select course_id
from course 
where semseter = 'Spring' and year = 2018)

(select course_id
from course 
where semseter = 'Fall' and year = 2017 )
intersect
(select course_id
from course 
where semseter =  'Spring' and year = 2018)

(select course_id
from course 
where semseter = 'Fall' and year = 2017 )
except
(select course_id
from course 
where semseter = 'Spring' and year = 2018)


select avg(salary)
from instructor
where dept_name = 'Comp. Sci.'

select count (distinct id)
from instructor 
where dept_name = 'Comp. Sci.'


select dept_name, avg(salary) as avg_salary
from instructor 
group by dept_name


select dept_name, avg (salary) as avg_salary
from instructor 
group by dept_name
having avg(salary) > 42000

select distinct course_id
from section
where semester = 'Fall' and year = 2017 and 
    course_id in (select course_id
                  from section
                  where semester = 'Spring' and year = 2018)

select distinct course_id
from section
where semseter = 'Fall' and year = 2017 and 
    course_id not in (select course_id
                      from section
                      where semester = 'Spring' and year = 2018)


select name 
from instructor
where name not in ('Einstein', 'Feynman', 'Gauss')


select course_id
from section S
where semester = 'Fall' and year = 2017 and 
    exists (select course_id
                      from section as T
                      where semester = 'Spring' and year = 2018 and 
                          S.course_id = T.course_id)


select distinct S.id, S.name
from student as S 
where not exists ((select * 
                  from course  
                  where dept_name = 'biology')
                  except
                  (select course_id
                  from takes as T 
                  where S.id = T.id))
                  
-- //Find the average instructors’ salaries of those departments where the average
-- salary is greater than $42,000.

select dept_name, avg(salary) as avg_salary
from (select dept_name, avg(salary) as avg_sal 
      from instructor 
      group by dept_name) as T
where T.avg_sal > 42000 

-- Find all departments with the maximum budget

with max_budget(value) as
(select max(budget) 
 from department)


select department.dept_name
from department, max_budget
where department.budget = max_budget.value