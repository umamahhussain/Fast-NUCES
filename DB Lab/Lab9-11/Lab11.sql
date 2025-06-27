create database transactionLab11;

use transactionlab11;

create table Students(
    RollNo varchar(7) primary key,
    Name varchar(30),
    WarningCount int,
    Department varchar(15)
);

INSERT INTO Students VALUES ('1', 'Ali', 0, 'CS');
INSERT INTO Students VALUES ('2', 'Bilal', 0, 'CS');
INSERT INTO Students VALUES ('3', 'Ayesha', 0, 'CS');
INSERT INTO Students VALUES ('4', 'Ahmed', 0, 'CS');
INSERT INTO Students VALUES ('5', 'Sara', 0, 'EE');
INSERT INTO Students VALUES ('6', 'Salman', 1, 'EE');
INSERT INTO Students VALUES ('7', 'Zainab', 2, 'CS');
INSERT INTO Students VALUES ('8', 'Danial', 1, 'CS');
INSERT INTO Students VALUES ('9', 'Zara', 0, 'EE');
INSERT INTO Students VALUES ('10', 'Kamran', 2, 'CS');

create table Courses (
    CourseID int primary key,
    CourseName varchar(40),
    PrerequisiteCourseID int,
    CreditHours int
);

INSERT INTO Courses VALUES (10, 'Database Systems', 20, 3);
INSERT INTO Courses VALUES (20, 'Data Structures', 30, 3);
INSERT INTO Courses VALUES (30, 'Programming', NULL, 3);
INSERT INTO Courses VALUES (40, 'Basic Electronics', NULL, 3);
INSERT INTO Courses VALUES (50, 'Advanced Database Systems', 10, 3);
INSERT INTO Courses VALUES (60, 'Algorithm Design', 20, 3);

Create table Instructors (
    InstructorID int Primary key,
    Name varchar(30),
    Department varchar(7)
);

INSERT INTO Instructors VALUES (100, 'Ishaq Raza', 'CS');
INSERT INTO Instructors VALUES (200, 'Zareen Alamgir', 'CS');
INSERT INTO Instructors VALUES (300, 'Saima Zafar', 'EE');
INSERT INTO Instructors VALUES (400, 'Ali Khan', 'EE');
INSERT INTO Instructors VALUES (500, 'Sadia Khan', 'CS');
INSERT INTO Instructors VALUES (600, 'Tariq Mehmood', 'EE');
INSERT INTO Instructors VALUES (700, 'Sara Ahmed', 'CS');

Create table Semester (
    Semester varchar(15) Primary key,
    [Status] varchar(10)
);

INSERT INTO Semester VALUES ('Fall2016', 'Complete');
INSERT INTO Semester VALUES ('Spring2016', 'Complete');
INSERT INTO Semester VALUES ('Spring2017', 'InProgress');
INSERT INTO Semester VALUES ('Summer2016', 'Cancelled');
INSERT INTO Semester VALUES ('Fall2017', 'Complete');
INSERT INTO Semester VALUES ('Spring2018', 'InProgress');

Create table Courses_Semester (
    InstructorID int Foreign key References Instructors(InstructorID),
    CourseID int Foreign key References Courses(CourseID),
    Semester varchar(15) Foreign key References Semester(Semester), 
    Section varchar(1),
    AvailableSeats int,
    Department varchar(2)
);

INSERT INTO Courses_Semester VALUES (200, 10, 'Spring2017', 'D', 45, 'CS');
INSERT INTO Courses_Semester VALUES (200, 10, 'Spring2017', 'C', 0, 'CS');
INSERT INTO Courses_Semester VALUES (100, 10, 'Spring2017', 'A', 6, 'CS');
INSERT INTO Courses_Semester VALUES (300, 40, 'Spring2017', 'A', 6, 'CS');
INSERT INTO Courses_Semester VALUES (300, 40, 'Spring2016', 'A', 6, 'CS');
INSERT INTO Courses_Semester VALUES (200, 10, 'Spring2016', 'A', 0, 'CS');
INSERT INTO Courses_Semester VALUES (600, 70, 'Fall2018', 'A', 25, 'EE');
INSERT INTO Courses_Semester VALUES (700, 80, 'Spring2019', 'B', 18, 'CS');

create table Registration (
    Semester varchar(15) Foreign key References Semester(Semester),
    RollNumber varchar(7) Foreign key References Students(RollNo),
    CourseID int Foreign key References Courses(CourseID), 
    Section varchar(1),
    GPA float
);

INSERT INTO Registration VALUES ('Fall2016', '1', 20, 'A', 3.3);
INSERT INTO Registration VALUES ('Fall2016', '2', 20, 'B', 4);
INSERT INTO Registration VALUES ('Spring2016', '1', 30, 'A', 1.0);
INSERT INTO Registration VALUES ('Fall2016', '6', 40, 'D', 0.0);
INSERT INTO Registration VALUES ('Spring2017', '6', 40, 'D', 1.0);
INSERT INTO Registration VALUES ('Fall2017', '11', 70, 'A', 3.5);
INSERT INTO Registration VALUES ('Spring2018', '12', 80, 'B', 3.8);

Create table ChallanForm (
    Semester varchar(15) Foreign key References Semester(Semester),
    RollNumber varchar(7) Foreign key References Students(RollNo),
    TotalDues int,
    [Status] varchar(10)
);

INSERT INTO ChallanForm VALUES ('Fall2016', '1', 100000, 'Paid');
INSERT INTO ChallanForm VALUES ('Fall2016', '2', 13333, 'Paid');
INSERT INTO ChallanForm VALUES ('Fall2016', '3', 5000, 'Paid');
INSERT INTO ChallanForm VALUES ('Fall2016', '4', 20000, 'Pending');
INSERT INTO ChallanForm VALUES ('Fall2018', '11', 110000, 'Paid');
INSERT INTO ChallanForm VALUES ('Spring2019', '12', 140000, 'Pending');

drop procedure EnrollingCourses;

create procedure EnrollingCourses
AS
BEGIN
    BEGIN TRANSACTION
    INSERT INTO Registration VALUES ('Fall2016', '1', 20, 'A', 3.3);
    INSERT INTO Registration VALUES ('Spring2017', '1', 10, 'A', 2.8);
    COMMIT TRANSACTION
END;

drop procedure StudentRegister;

create procedure StudentRegister
@CGPA float
AS
BEGIN
    IF @CGPA < 2.5
    BEGIN
        PRINT ' The person can only enroll in courses in which he/she can improve.';
        BEGIN TRANSACTION
        ROLLBACK TRANSACTION
    END
    ELSE
    BEGIN
        IF @CGPA > 2.5
        BEGIN
            EXEC EnrollingCourses
            SELECT * FROM Registration
        END
    END
END;

execute StudentRegister @CGPA = 2.0;
