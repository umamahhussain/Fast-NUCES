--QUESTION 1
--TASK 1

create table Users
(
users_id int not null,
username nvarchar(50),
registration_date date
)

create table songs
(
song_id int not null,
song_title nvarchar(50),
artist_id int,
release_date date,
genre nvarchar(50)
)

create table artists
(
artist_id int not null,
artist_name nvarchar(50)
)

create table playlist
(
playlist_id int not null,
playlist_name nvarchar(50),
users_id int,
creation_date date 
)


alter table playlist add constraint pk_playlist_id primary key(playlist_id)
alter table Users add constraint pk_user_id primary key(users_id)
alter table artists add constraint pk_artist_id primary key(artist_id)
alter table songs add constraint pk_songs_id primary key(song_id)

alter table songs add constraint FK_artist_id foreign key(artist_id) references artists(artist_id)
alter table playlist add constraint FK_user_id foreign key(users_id) references Users(users_id)


insert into Users([users_id],[username],[registration_date])
VALUES
(1	,	'abc	'	,'2023-4-1	'),
(2	,	'def	'	,'2023-4-3	'),
(3	,	'ghi	'	,'2023-4-7	'),
(4	,	'jkl	'	,'2023-5-1	'),
(5	,	'mno	'	,'2023-7-12	'),
(6	,	'pqr	'	,'2023-2-9	'),
(7	,	'stu	'	,'2023-9-3	'),
(8	,	'vwz	'	,'2023-1-21	'),
(9	,	'yza	'	,'2023-7-5	'),
(10	,	'uwu	'	,'2023-8-4	')

INSERT INTO songs([song_id],[song_title],[artist_id],[release_date],[genre])
VALUES
(1	,	'hello		'	,	1	,	'2023-4-1	',	'pop	'),
(2	,	'lovely		'	,	1	,	'2023-4-2	',	'pop	'),
(3	,	'tv			'	,	1	,	'2023-4-3	',	'pop	'),
(4	,	'bye		'	,	1	,	'2023-4-4	',	'pop	'),
(5	,	'world		'	,	2	,	'2023-4-5	',	'pop	'),
(6	,	'love		'	,	3	,	'2023-4-6	',	'rock	'),
(7	,	'hate		'	,	4	,	'2023-4-8	',	'rock	'),
(8	,	'temp		'	,	5	,	'2023-4-8	',	'rock	'),
(9	,	'data		'	,	1	,	'2023-4-9	',	'rock	'),
(10	,	'wonder		'	,	4	,	'2023-4-10	',	'rock	'),
(11	,	'hey 		'	,	1	,	'2023-4-1	',	'pop	'),
(12	,	'skrt		'	,	1	,	'2023-4-2	',	'pop	'),
(13	,	'eyes		'	,	1	,	'2023-4-3	',	'pop	'),
(14	,	'apocalypse	'	,	1	,	'2023-4-4	',	'pop	'),
(15	,	'Kris		'	,	1	,	'2023-4-5	',	'pop	')




insert into artists([artist_id],[artist_name])
VALUES
(1	,	'A	'	),
(2	,	'B	'	),
(3	,	'C	'	),
(4	,	'D	'	),
(5	,	'E	'	),
(6	,	'F	'	),
(7	,	'G	'	),
(8	,	'H	'	),
(9	,	'I	'	),
(10	,	'J	'	)


insert into playlist([playlist_id],[playlist_name],[users_id],[creation_date])
values
(1	,	'playlistA	'	,1	,	'2023-6-1	'),
(2	,	'playlistB	'	,2	,	'2023-6-12	'),
(3	,	'playlistC	'	,3	,	'2023-6-13	'),
(4	,	'playlistD	'	,4	,	'2023-6-14	'),
(5	,	'playlistE	'	,1	,	'2023-6-15	'),
(6	,	'playlistF	'	,5	,	'2023-6-16	'),
(7	,	'playlistG	'	,7	,	'2023-6-17	'),
(8	,	'playlistH	'	,4	,	'2023-6-18	'),
(9	,	'playlistI	'	,9	,	'2023-6-19	'),
(10	,	'playlistJ	'	,6	,	'2023-6-20	')


--------------------------------------------------------------------------------
--TASK 2

select U.users_id, U.username
from Users U, Artists A
where U.users_id in
(
select P.users_id
from playlist P
where DATEDIFF(YEAR,creation_date,getdate())<180 
) AND A.artist_id in
(
select S.artist_id
from songs S
group by S.artist_id
having count(S.artist_id)>10
)

-------------------------------------------------------------------------------------------------------------
--TASK 3

SELECT distinct U.users_id, P.playlist_name, P.creation_date
FROM Users U 
right join playlist P on U.users_id=P.users_id
group by  U.users_id, P.playlist_name, P.creation_date












---------------------QUESTION 2----------------------------------------------------------------------------------------------------
-- Create the Authors table
CREATE TABLE Authors (
    author_id INT PRIMARY KEY,
    author_name VARCHAR(255),
    birth_year INT
);

-- Insert data into the Authors table
INSERT INTO Authors (author_id, author_name, birth_year) VALUES
    (1, 'Jack', 1980),
    (2, 'Williams', 1975),
    (3, 'Mark', 1990),
    (4, 'Hennry', 1985),
    (5, 'James', 1970);

-- Create the Books table with a foreign key reference to Authors
CREATE TABLE Books (
    book_id INT PRIMARY KEY,
    title VARCHAR(255),
    author_id INT,
    publication_year INT,
    price DECIMAL(10, 2),
    FOREIGN KEY (author_id) REFERENCES Authors(author_id)
);

-- Insert data into the Books table
INSERT INTO Books (book_id, title, author_id, publication_year, price) VALUES
    (101, 'Becoming', 1, 2005, 69.99),
    (102, 'The Silent Patient', 2, 2010, 49.99),
    (103, 'A Promised Land', 3, 2020, 79.99),
    (104, 'Greenlights', 4, 2015, 55.99),
    (105, 'Normal People', 5, 2000, 45.99);

-- Create the Customers table
CREATE TABLE Customers (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(255),
    email VARCHAR(255)
);

-- Insert data into the Customers table
INSERT INTO Customers (customer_id, customer_name, email) VALUES
    (1001, 'Ahmed', 'ahmed1@gmail.com'),
    (1002, 'ALi', 'ali2@gmail.com'),
    (1003, 'Awais', 'awais3@gmail.com'),
    (1004, 'Bilal', 'bilal4@gmail.com'),
    (1005, 'Saad', 'saad5@gmail.com');

-- Create the Orders table with a foreign key reference to Customers
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    order_date DATE,
    FOREIGN KEY (customer_id) REFERENCES Customers(customer_id)
);

-- Insert data into the Orders table
INSERT INTO Orders (order_id, customer_id, order_date) VALUES
    (0011, 1001, '2023-01-15'),
    (0012, 1002, '2023-02-20'),
    (0013, 1003, '2023-03-05'),
    (0014, 1004, '2023-03-10'),
    (0015, 1005, '2023-04-08');

-- Create the OrderItems table with foreign key references to Orders and Books
CREATE TABLE OrderItems (
    item_id INT PRIMARY KEY,
    order_id INT,
    book_id INT,
    quantity INT,
    item_price DECIMAL(10, 2),
    FOREIGN KEY (order_id) REFERENCES Orders(order_id),
    FOREIGN KEY (book_id) REFERENCES Books(book_id)
);

-- Insert data into the OrderItems table
INSERT INTO OrderItems (item_id, order_id, book_id, quantity, item_price) VALUES
    (2001, 0011, 101, 2, 59.99),
    (2002, 0012, 103, 1, 79.99),
    (2003, 0013, 102, 3, 49.99),
    (2004, 0014, 104, 1, 55.99),
    (2005, 0015, 105, 2, 45.99);

	-----------------------------------------------------------------------------------------------------------
	--PART A

	create view HighPricedBooks as
	select B.book_id,B.title,A.author_name,B.price
	from Books B
	join Authors A on B.author_id=A.author_id
	where B.price>=50

	select *from HighPricedBooks
	drop view HighPricedBooks

	-------------------------------------------------------------------------------------------------------------
	--PART B

	create table PriceUpdateLog
	(
	log_id int primary key,
	book_id int,
	old_price decimal,
	new_price decimal,
	update_date datetime
    FOREIGN KEY (book_id) REFERENCES Books(book_id)
	);



create procedure UpdateBookPrice @book_id int, @new_price decimal
as
select B.book_id, B.price
from Books B
case when @book_id in B.book_id
	 then 
	 (
	 update PriceUpdateLog
	 set log_id=sum(+1)
	 where log_id=null

	 update PriceUpdateLog
	 set book_id=@book_id
	 where book_id=null

	  update PriceUpdateLog
	 set old_price=B.price
	 where old_price=null
	 
	 update PriceUpdateLog
	 set new_price=@new_price
	 where @new_price=null

	 update PriceUpdateLog
	 set update_date=GETDATE()
	 where update_date=NULL;

	 
	 update PriceUpdateLog
	 set old_price=B.price
	 where old_price=null

	 update Books
	 set price=@new_price
	 where book_id=@book_id
		
	 )
else 'The Book-ID does not exist'

exec UpdateBookPrice 101,59.99



create procedure UpdateBookPrice2 @book_id int, @new_price decimal
as
update Books
set price=@new_price
where book_id=@book_id

exec UpdateBookPrice2 101,59.99
-----------------------------------------------------------------------------------
--PART C



create procedure UpdateBookPrice2 @book_id int, @new_price decimal
as
update HighPricedBooks
set price=@new_price
where book_id=@book_id

EXEC UpdateProductPrice 4,9000
select* from SalesProductView

