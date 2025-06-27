create table Books
(
BookID int not null unique,
Title nvarchar(255),
Author nvarchar(255),
PublicationYear int,
ISBN nvarchar(255)
)

Insert into Books([BookID],[Title],[Author],[PublicationYear],[ISBN])
values
(1,'To Kill a Mocking Bird','Harper Lee',1960,'9780061120084'),
(2,'1984','George Orwell',1949,'978045152493'),
(3,'The Great Gatsby','F.Scott Fitzgerald',1925,'9780743273565'),
(4,'Pride and Prejudice','Jane Austen',1813,'9780141439518')

--/Insert a value
Insert into Books([BookID],[Title],[Author],[PublicationYear],[ISBN])
values
(5,'The Catcher in the Rye','J.D Salinger',1951,'9780316769174')

--/Retrieve the details
select* from Books

--/update the title
update Books
set Title='Catcher in the Rye 2'
where ISBN='9780316769174'

--/delete book with specific ISBN
delete from Books
where ISBN='9780316769174'

--//////////////////////////////////////////////////////////////////////////////////--

create table Products
(
ProductID int not null unique,
ProductName nvarchar(255),
Category nvarchar(255),
Price int
)

Insert into Products([ProductID],[ProductName],[Category],[Price])
values
(1,'Laptop','Electronics',800),
(2,'Desk Chair','Furniture',120),
(3,'Smart Phone','Electronics',500),
(4,'Office Desk','Furniture',250),
(5,'Wireless Mouse','Electronics',20),
(6,'Bookshelf','Furniture',150),
(7,'Headphones','Electronics',100)

select* from Products

--Retrieve the names of all products that contain the word "Chair" anywhere in their name.
select ProductID,ProductName,Price
from Products
where ProductName like '%Chair%'

--Retrieve the names and prices of all products in the "Electronics" category.
select* from Products
where Category='Electronics'

--Retrieve the names and prices of all products with a price less than $200.
select* from Products
where Price<200

--Retrieve the names and categories of products that contain the word "Desk" anywhere in their name.
select  ProductID,ProductName,Price
from Products
where ProductName like '%Desk%'

--////////////////////////////////////////////////////////////////////////////////////--

create table Orders
(
OrderID int not null unique,
CustomerID int,
OrderDate nvarchar(255),
TotalAmount Decimal
)

Insert into Orders([OrderID],[CustomerID],[OrderDate],[TotalAmount])
values
(1,101,'2023-09-01',150.50),
(2,102,'2023-09-02',75.20),
(3,103,'2023-09-03',200.00),
(4,104,'2023-09-04',80.75),
(5,105,'2023-09-05',300.30)

select* from Orders

--Calculate the total revenue generated from all orders in the orders table.
select sum(TotalAmount)from Orders

--Find the average order amount in the orders table.
select avg(TotalAmount)from Orders

--Update the total_amount column to increase all order amounts by 10%.
select OrderID,CustomerID,OrderDate,TotalAmount, 1.1*TotalAmount as UpdatedAmount
from Orders

--Select orders where the total amount is greater than $500.
select* from Orders
where TotalAmount>500

--Calculate the sum of total amounts for orders placed in 2023
select sum(TotalAmount)from Orders
where OrderDate like '2023%'

--///////////////////////////////////////////////////////////////////////////////////////

create table employees
(
EmployeeID int not null unique,
FirstName nvarchar(255),
LastName nvarchar(255),
DepID int
)

Insert into employees([EmployeeID],[FirstName],[LastName],[DepID])
values
(1,'John','Smith',101),
(2,'Sarah','Johanson',102),
(3,'Michael','Williams',103),
(4,'Emily','Davis',104),
(5,'David','Lee',105),
(7,'Anna','Woo',null)



create table departments
(
DepID int not null unique,
DepName nvarchar(255)
)

insert into departments([DepID],[DepName])
values
(101,'Sales'),
(102,'Marketing'),
(103,'Finance'),
(104,'Human Resources'),
(105,'Research and Development')

select* from employees;
select* from departments;

--Perform a union operation between the employees and departments tables to get a combined list of employees and department names.
select E.EmployeeID,E.FirstName,E.LastName,D.DepID,D.DepName
from employees E, departments D
where D.DepID=E.DepID

select E.EmployeeID,E.FirstName,E.LastName,D.DepID,D.DepName
from employees E
join departments D on D.DepID=E.DepID

--Find the employees who are not assigned to any department using the set difference operation.
select A.EmployeeID,A.FirstName,A.LastName,A.DepID
from employees A
where  A.DepID is null

--Determine the common department(s) between two sets of employees using the intersection operation.
select distinct A.EmployeeID,A.FirstName,A.LastName,A.DepID
from employees A, employees B
where A.DepID=B.DepID and A.EmployeeID<>B.EmployeeID

--List all departments and the number of employees in each department using a join and grouping.
select distinct E.EmployeeID,E.FirstName,E.LastName,E.DepID,D.DepName
from employees E
left join departments D
on E.DepID=D.DepID

--Find the departments that have no employees assigned to them.
select * from departments D
join employees E on E.DepID=D.DepID and D.DepID is null
