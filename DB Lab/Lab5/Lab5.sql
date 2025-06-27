-- Create Departments table
CREATE TABLE Departments (
    DepartmentID INT PRIMARY KEY,
    DepartmentName NVARCHAR(50)
);

-- Create Employees table with DepartmentID as a foreign key
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    FirstName NVARCHAR(50),
    LastName NVARCHAR(50),
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID)
);

-- Insert sample data
INSERT INTO Departments VALUES (1, 'IT');
INSERT INTO Departments VALUES (2, 'HR');
INSERT INTO Departments VALUES (3, 'Marketing');

INSERT INTO Employees VALUES (101, 'John', 'Doe', 1);
INSERT INTO Employees VALUES (102, 'Jane', 'Smith', 2);
INSERT INTO Employees VALUES (103, 'Alice', 'Johnson', 1);
INSERT INTO Employees VALUES (104, 'Bob', 'Williams', 3);
INSERT INTO Employees VALUES (105, 'Eva', 'Brown', 2);
INSERT INTO Employees VALUES (106, 'Charlie', 'Miller', 1);
INSERT INTO Employees VALUES (107, 'Ali', 'Ahmad', 2);
INSERT INTO Employees VALUES (108, 'Bilal', 'Ahmad', 1);
INSERT INTO Employees VALUES (109, 'Saif', 'king', 3);
INSERT INTO Employees VALUES (100, 'Basil', 'Ahmad', 3);

--1.) Create a basic view (EmployeeView) with EmployeeID, FirstName, and LastName columns.
create view EmployeeView as
select EmployeeID,FirstName,LastName
from Employees

--2.)  Display all records from the EmployeeView.
select* from EmployeeView

--3.) Create a view (EmployeeDepartmentView) with EmployeeID, FirstName, 
--LastName, and DepartmentName by joining Employees and Departments.
create view EmployeeDepartmentView as
select E.EmployeeID,E.FirstName,E.LastName, D.DepartmentName
from Employees E
join Departments D on E.DepartmentID=D.DepartmentID

--4.) Display all records from the EmployeeDepartmentView.
select* from EmployeeDepartmentView

--5.) Update the first name of the employee with EmployeeID 101 through EmployeeView.
update EmployeeView
set FirstName='Umamah'
where EmployeeID=101

--Query 6: Drop EmployeeDepartmentView.
drop view EmployeeDepartmentView

--Query 7: Create a materialized view (mv_EmployeesWithDepartments) that includes 
--employee information along with department names.
create view mv_EmployeesWithDepartments as
select E.EmployeeID,E.FirstName,E.LastName,E.DepartmentID,D.DepartmentName
from Employees E
join Departments D on E.DepartmentID=D.DepartmentID

--Query 8: Find the total number of employees in each department 
--using the materialized view (mv_EmployeesWithDepartments).
select count(*) as TotalEmp
from mv_EmployeesWithDepartments

--Query 9: Drop the materialized view when it’s no longer needed.
drop view mv_EmployeesWithDepartments