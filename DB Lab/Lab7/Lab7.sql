create table Products
(
prodID int primary key,
prodName nvarchar(55),
categoryID int foreign key references Categories(categoryID),
price decimal,
proddesc nvarchar(55)
)

create table Inventory
(
prodID int foreign key references Products(prodID),
quantity decimal
)

create table Categories
(
categoryID int primary key,
categoryName nvarchar(55)
)

drop table Categories
drop table Products
drop table Inventory


insert into Products([prodID],[prodName],[categoryID],[price],[proddesc])
values
(1	, 'Chair',			1 , 100	,	'for sitting'),
(2	, 'Table',			1 , 400	,	'multi-use'),
(3	, 'Bed'  ,			1 , 800	,	'for sleeping'),
(4	, 'Computer',		2 , 900	,	'educational purposes '),
(5	, 'Curler ',		2 , 300	,	'styling purposes'),
(6	, 'Blowdryer',		2 , 200	,	'styling purposes'),
(7	, 'Laptop',			2 , 900	,	'educational purposes '),
(8	, 'Sofa',			1 , 100	,	'for sitting'),
(9	, 'Coffee Table',	1 , 400	,	'multi-use'),
(10	, 'Counter'  ,		1 , 800	,	'multi-use'),
(11	, 'Ipad',			2 , 900	,	'educational purposes '),
(12	, 'Straightener',	2 , 300	,	'styling purposes'),
(13	, 'Permer',			2 , 200	,	'styling purposes'),
(14	, 'Phone',			2 , 900	,	'educational purposes '),
(15	, 'Plate',			3 , 100	,	'For Eating '),
(16	, 'Glass',			3 , 400	,	'For Eating '),
(17	, 'Cup'  ,			3 , 800	,	'For Eating '),
(18	, 'Spoon',			3 , 900	,	'For Eating '),
(19	, 'Fork',			3 , 300	,	'For Eating '),
(20	, 'Knife',			3 , 200	,	'For Eating '),
(21	, 'Tops',			4 , 900	,	'styling purposes'),
(22	, 'TShirts',		4 , 100	,	'styling purposes'),
(23	, 'Jeans',			4 , 400	,	'styling purposes'),
(24	, 'Skirts' ,		4 , 800	,	'styling purposes'),
(25	, 'Frocks',			4 , 900	,	'styling purposes'),
(26	, 'Pants ',			4 , 300	,	'styling purposes'),
(27	, 'Earrings',		5 , 200	,	'styling purposes'),
(28	, 'Necklace',		5 , 900	,	'styling purposes'),
(29	, 'Bracelet',		5 , 100	,	'styling purposes'),
(30	, 'Pins',			5 , 400	,	'styling purposes')




insert into Inventory([prodID],[quantity])
values
(1	,50),
(2	,30),
(3	,40),
(4	,70),
(5	,40),
(6	,10),
(7	,90),
(8	,50),
(9	,30),
(10	,40),
(11	,70),
(12	,40),
(13	,10),
(14	,90),
(15	,50),
(16	,30),
(17	,40),
(18	,70),
(19	,40),
(20	,10),
(21	,90),
(22	,50),
(23	,30),
(24	,40),
(25	,70),
(26	,40),
(27	,10),
(28	,90),
(29	,50),
(30	,30)


insert into Categories([categoryID],[categoryName])
values
(1, 'Furniture'),
(2, 'Electronics'),
(3, 'Crockery'),
(4, 'Clothes'),
(5, 'Jewellery')

-----------------------------------------------------

create view SalesProductView as
select P.prodID, P.prodName, P.price,I.quantity
from Products P
join Inventory I on P.prodID=I.prodID

drop view SalesProductView
-------------------------------------------------------

CREATE PROCEDURE UpdateProductPrice
    @prodID INT,
    @NewPrice INT
AS
BEGIN
    UPDATE SalesProductView
    SET price = @NewPrice
    WHERE prodID = @prodID
END;

EXEC UpdateProductPrice 4,9000
select* from SalesProductView
