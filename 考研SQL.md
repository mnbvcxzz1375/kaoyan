## 考研SQL

```mysql
CREATE DATABASE kaoyan
    CHARACTER SET utf8mb4
    COLLATE utf8mb4_unicode_ci;

use kaoyan;


create table if not exists Class(
    ClassID char(8) primary key ,
    ClassName varchar(20) not null ,
    Monitor char(8),
    StudentNum int check ( StudentNum>0 ),
    DepartmentID char(4) ,
    foreign key (DepartmentID) references Department(DepartmentID)
);

create table if not exists Student(
    StudentID  char(12)  primary key,
    StudentName char(8) not null,
    Sex char(2) not null check(Sex in ('男','女')),
    Birth date not null ,
    HomeAddr varchar(80),
    EntranceTime date default (CURRENT_DATE),
    ClassID char(8),
    foreign key (ClassID) references Class(ClassID)
);


create table if not exists  Course(
    CourseID char(8) primary key ,
    CourseName varchar(60) not null ,
    BookName varchar(80) not null ,
    `Period` int not null,
    Credit int not null
);


create table if not exists Grade(
    CourseID char(8) ,
    StudentID char(12),
    Semester int not null ,
    SchoolYear int,
    Grade numeric(5,1) check(Grade>=0),
    primary key (CourseID,StudentID),
    foreign key (CourseID) references Course(CourseID),
    foreign key (StudentID) references Student(StudentID)
);


create table if not exists  Department(
    DepartmentID char(4) primary key ,
    DepartmentName varchar(20) not null unique ,
    DepartmentHeader varchar(8) not null ,
    TeacherNum int
);


create table if not exists Teacher(
    TeacherID char(8) primary key ,
    TeacherName char(8) not null ,
    Sex char(2) not null check ( Sex in('男','女') ),
    Birth DATE,
    Profession char(8) check(Profession in('教授','副教授','讲师','助教')),
    Telephone varchar(20),
    HomeAddr varchar(50),
    DepartmentID char(4),
    foreign key (DepartmentID) references Department(DepartmentID)
);

create table if not exists Schedule(
    TeacherID char(8),
    CourseID char(8),
    ClassID char(8),
    Semester int not null ,
    SchoolYear int not null ,
    Scheduledent varchar(40) not null ,
    Classroom varchar(20) not null,
    primary key (TeacherID,CourseID,ClassID),
    foreign key (TeacherID) references Teacher(TeacherID),
    foreign key (CourseID) references  Course(CourseID),
    foreign key (ClassID) references  Class(ClassID)
);


insert into student(StudentID, StudentName, Sex, Birth, HomeAddr,EntranceTime, ClassID)
values ('20240001','柚子哥','男','2002-5-12','北京市',(current_date),'cs101');

insert into Course(courseid, coursename, bookname, period, credit)
values('CS2024','数据结构','数据结构与算法',45,4);

insert into Class(ClassID, ClassName, Monitor, StudentNum, DepartmentID)
values ('CS101','计算机科学班','李四',35,'CS');

insert into Department(DepartmentID, DepartmentName, DepartmentHeader, TeacherNum)
VALUES ('CS','计算机系','王教授',50);

insert into Teacher(TeacherID, TeacherName, Sex, Birth, Profession, Telephone, HomeAddr, DepartmentID)
values ('T101','王教授','男','2000-1-1','教授','19876546543','北京市','CS');

insert into Grade(CourseID, StudentID, Semester, SchoolYear, Grade)
values('CS2024','20240001',1,2024,85.0);

insert into Schedule(TeacherID, CourseID, ClassID, Semester, SchoolYear, Scheduledent, Classroom)
values ('T101','CS2024','CS101',1,2024,'S101','101教室');


update Student
set Sex='男'
where StudentName='李平';

update department
set TeacherNum=80
where DepartmentName='计算机系';

update course
set period=80
where Credit>=4;

update Student
set EntranceTime=(current_time)
where HomeAddr like'%北京市%';

update Grade
set Grade=Grade+5
where CourseID in (select CourseID from course where CourseName='JAVA');

update Teacher
set HomeAddr='宿舍1栋110'
where DepartmentID in (select DepartmentID from Department where DepartmentName='计算机系' )&&Sex='男';

update Grade
set Grade=60
where Grade<60&& StudentID in (select StudentID from Student where StudentName='张宏');


delete from Student where year(curdate())-year(Birth)=18;

delete from Teacher where Profession='助教'and Sex='男';

delete from Class where StudentNum<30;

delete from Teacher where DepartmentID in (select DepartmentID from Department where DepartmentName='计科系');

DELETE Teacher
FROM Teacher
JOIN Department ON Teacher.DepartmentID = Department.DepartmentID
WHERE Department.DepartmentName = '计科系';


delete from Student where ClassID in (select ClassID from Class where DepartmentID='IM');

delete from Grade where  Grade<60;



select TeacherID,TeacherName,Sex,Birth from Teacher;

select distinct DepartmentID from Teacher;

select ClassID,ClassName,StudentNum from Class where StudentNum>10;

select TeacherName as '姓名',year(curdate())-year(birth) as '年龄' from Teacher;

select Monitor from class where ClassName='19软件技术1班';

select TeacherName,Birth from teacher
                         where TeacherName like'王%' or TeacherName like'刘%' or TeacherName like'胡%' ;

select * from Student
where  StudentName like '%丽%';

select * from class
order by StudentNum asc ;
/*按照班级人数排升序*/

select TeacherName,Birth from Teacher
order by Birth desc
limit 1;

select StudentID,Grade from Grade
where CourseID in (select CourseID from Course where CourseName='java程序设计')
order by Grade desc
limit 1;

select StudentName,Birth,HomeAddr from Student,Class
where ClassID in (select ClassID from Class where ClassName='19软件技术1班');

select StudentName,Birth,HomeAddr from Student join Class on  Student.ClassID=Class.ClassID
where ClassName='19软件技术1班';

select StudentName,CourseID,Grade from Grade join Student on Grade.StudentID = Student.StudentID
where ClassID in (select ClassID from Class where ClassName='计算机科学班');

select TeacherName,Sex from Teacher  join department
on Teacher.DepartmentID = department.DepartmentID
where DepartmentName='计算机系';

select Grade from Grade join Student  on Grade.StudentID = Student.StudentID
where StudentName='张宏' and CourseID in (select CourseID from Course where CourseName='java程序设计');

select StudentID,StudentName,Sex,Birth from Student
where StudentID not in (select distinct StudentID from Grade);

select TeacherName from teacher join schedule on teacher.TeacherID = schedule.TeacherID
where Scheduledent is null;

select StudentName from student s
join grade g on s.StudentID = g.StudentID
join course c on g.CourseID = c.CourseID
where  CourseName='JAVA程序设计';

select TeacherName from Teacher t
join schedule sc on t.TeacherID = sc.TeacherID
join course c on sc.CourseID = c.CourseID
where CourseName='java程序设计';

select TeacherName from Teacher t
join schedule on t.TeacherID = schedule.TeacherID
join course on schedule.CourseID = course.CourseID
join student on schedule.ClassID = Student.ClassID
where StudentName='张宏';

select * from Class
where ClassID not in (select distinct ClassID from student);



select TeacherName from Teacher
where DepartmentID in (select DepartmentID from department where Teacher.TeacherName='王平');

select TeacherName,Sex from Teacher
where DepartmentID in (select DepartmentID from  department where DepartmentName='信管系');

select ClassName from Class
where DepartmentID in (select DepartmentID from department where DepartmentName='计算机系');

select CourseName from course
where Credit>all(select Credit from course where coursename in ('电子商务物流管理','计算机应用基础'));

select StudentName from student
where (year(curdate())-year(Birth))
          >all(select (year(curdate())-year(Birth)) from student
                                                    where StudentName in ('张宏','姜明凡'));

select studentname from student
join class on student.ClassID = class.ClassID
join department on class.DepartmentID = department.DepartmentID
where DepartmentName in ('计算机系','信息系');

select Student.StudentName from student
where classid in(
    select  classid from class
                    where DepartmentID in (
                        select  DepartmentID from department
                                             where DepartmentName in ('计算机系','信息系')
                        )
    );


UPDATE Grade g
JOIN Student s ON s.StudentID = g.StudentID
SET g.Grade = 60
WHERE s.StudentName = '柚子' AND g.Grade < 60;


select s.StudentID,s.StudentName,c.CourseName,g.Grade,
case
    when g.Grade>=90 then '优'
    when g.Grade>=80 then '良'
    when g.Grade>=70 then '中'
    when g.Grade>=60 then '及格'
    else '不及格'
    end as '成绩等级'
from grade g
join student s on g.StudentID = s.StudentID
join course c on g.CourseID = c.CourseID;


select CourseName from Grade g
join course c on g.CourseID = c.CourseID
where StudentID is null;


select
    count(distinct s.StudentID) as '总人数',
    avg(g.Grade) as '平均分',
    max(g.Grade) as '最高分',
    min(g.Grade) as '最低分'
from Student s
join grade  g on s.StudentID = g.StudentID
where year(curdate())-year(Birth)<20;

SELECT
    COUNT(IF(s.Sex = '男', 1, NULL)) AS '男生人数',
    COUNT(IF(s.Sex = '女', 1, NULL)) AS '女生人数',
    AVG(IF(s.Sex = '男', g.Grade, NULL)) AS '男生平均分',
    AVG(IF(s.Sex = '女', g.Grade, NULL)) AS '女生平均分'
FROM student s
JOIN grade g ON s.StudentID = g.StudentID
JOIN class c ON s.ClassID = c.ClassID;


select
    c.ClassName as '班级名称',
    sum(g.Grade) as'分数总和',
    max(g.Grade) as '最高分',
    min(g.Grade) as '最低分',
    count(distinct s.StudentID) as '总人数'
from class c
join student s on c.ClassID = s.ClassID
join grade g on s.StudentID = g.StudentID
group by c.ClassName ,c.ClassID;


select
    CourseName,c.CourseID,count(distinct StudentID)
from course c
join grade g on c.CourseID = g.CourseID
group by c.CourseName,c.CourseID;


select
    DepartmentName as '系名',
    sum(TeacherNum+StudentNum) as '人数'
from department d
join class c on d.DepartmentID = c.DepartmentID
group by DepartmentName;


select
    distinct TeacherName,CourseName
from teacher t
join schedule s on t.TeacherID = s.TeacherID
join course c on s.CourseID = c.CourseID
group by TeacherName;


select
    ClassName as '班名',
    c.CourseID as '课程名',
    max(g.Grade) as '最高成绩'
from course c
join schedule sc on c.CourseID = sc.CourseID
join class cl on sc.ClassID = cl.ClassID
join grade g on c.CourseID = g.CourseID
group by cl.ClassID,c.CourseID;



select
    CourseName as '课程名',
    max(g.Grade) as '最高成绩'
from grade g
join course c on g.CourseID = c.CourseID
group by c.CourseID;

select
    ClassName
from Grade g
join schedule sc on sc.CourseID=g.CourseID
join class on sc.ClassID = class.ClassID
group by ClassName
having avg(Grade)>80;

select
    CourseName as '课程名称',
    count(distinct g.StudentID) as '选修人数'
from course c
join grade g on c.CourseID = g.CourseID
group by CourseName,c.CourseID
having count(distinct g.StudentID)<5;



SELECT COUNT(*)
FROM (
    SELECT StudentName AS Name FROM student WHERE StudentName LIKE '%柚%'
    UNION
    SELECT TeacherName AS Name FROM teacher WHERE TeacherName LIKE '%柚%'
) AS combined;

```

