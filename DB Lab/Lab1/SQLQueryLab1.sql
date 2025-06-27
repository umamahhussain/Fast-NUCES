create table Student
(
Rollnum nvarchar(255) primary key,
Names varchar(255),
Gender varchar(255),
Phone nvarchar(255)
);

create table Teacher
(
ID int primary key,
Names varchar(255),
Designation varchar(255),
Department nvarchar(255)
);

create table ClassVenue
(
ID int primary key,
Building varchar(255),
RoomNum int,
TeacherID int
);

create table Attendance
(
Rollnum varchar(255) primary key,
Dates varchar(255),
Stattus varchar(255),
ClassVenue varchar(255)
);

Insert into Attendance([Rollnum],[Dates],[Stattus],[ClassVenue])
values
('L164123','2-22-2016','P','2'),
('L164124','2-23-2016','A','1'),
('L164125','3-4-2016','P','2')

Insert into Student([Rollnum],[Names],[Gender],[Phone])
values
('L161423','Ali Ahmad','Male','0333-3333333'),
('L164124','Rafia Ahmad','Female','0333-3456789'),
('L164125','Basit Junaid','Male','0345-3243567')

Insert into ClassVenue([ID],[Building],[RoomNum],[TeacherID])
values
(1,'CS',2,1),
(2,'Civil',7,2)

Insert into Teacher([ID],[Names],[Designation],[Department])
values
(1,'Ali Ahmad','Assisstant Prof','Computer Science'),
(2,'Rafia Ahmad','Lecturer','Civil Eng'),
(3,'Bilal Haider','Professor','Electrical Eng')

select* from Student
select* from Teacher
select* from Attendance
select* from ClassVenue