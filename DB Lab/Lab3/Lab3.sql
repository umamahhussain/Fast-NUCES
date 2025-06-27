use [Lab 3]

create table hotel
(
hotelno varchar(10) primary key,
hotelname varchar(20),
city varchar(20),
)

insert into hotel values('fb01', 'Grosvenor', 'London');
insert into hotel values('fb02', 'Watergate', 'Paris');
insert into hotel values('ch01', 'Omni Shoreham', 'London');
insert into hotel values('ch02', 'Phoenix Park', 'London');
insert into hotel values('dc01', 'Latham', 'Berlin');

 -- create a table named hotel

 create table room
(
roomno numeric(5),
hotelno varchar(10),
type varchar(10),
price decimal(5,2),
primary key (roomno, hotelno),
foreign key (hotelno) REFERENCES hotel(hotelno)
)

insert into room values(501, 'fb01', 'single', 19);
insert into room values(601, 'fb01', 'double', 29);
insert into room values(701, 'fb01', 'family', 39);
insert into room values(1001, 'fb02', 'single', 58);
insert into room values(1101, 'fb02', 'double', 86);
insert into room values(1001, 'ch01', 'single', 29.99);
insert into room values(1101, 'ch01', 'family', 59.99);
insert into room values(701, 'ch02', 'single', 10);
insert into room values(801, 'ch02', 'double', 15);
insert into room values(901, 'dc01', 'single', 18);
insert into room values(1001, 'dc01', 'double', 30);
insert into room values(1101, 'dc01', 'family', 35);

create table guest
(
guestno numeric(5),
guestname varchar(20),
guestaddress varchar(50),
primary key (guestno)
)

insert into guest values(10001, 'John Kay', '56 High St, London');
insert into guest values(10002, 'Mike Ritchie', '18 Tain St, London');
insert into guest values(10003, 'Mary Tregear', '5 Tarbot Rd, Aberdeen');
insert into guest values(10004, 'Joe Keogh', '2 Fergus Dr, Aberdeen');
insert into guest values(10005, 'Carol Farrel', '6 Achray St, Glasgow');
insert into guest values(10006, 'Tina Murphy', '63 Well St, Glasgow');
insert into guest values(10007, 'Tony Shaw', '12 Park Pl, Glasgow');

create table booking(
hotelno varchar(10),
guestno numeric(5),
datefrom date,
dateto date,
roomno numeric(5),
primary key (hotelno, guestno, datefrom),
foreign key (roomno, hotelno) REFERENCES room(roomno, hotelno),
foreign key (guestno) REFERENCES guest(guestno)
)


insert into booking values('fb01', 10001, '04-04-01', '04-04-08', 501);
insert into booking values('fb01', 10004, '04-04-15', '04-05-15', 601);
insert into booking values('fb01', 10005, '04-05-02', '04-05-07', 501);
insert into booking values('fb01', 10001, '04-05-01', null, 701);
insert into booking values('fb02', 10003, '04-04-05', '10-04-04', 1001);
insert into booking values('ch01', 10006, '04-04-21', null, 1101);
insert into booking values('ch02', 10002, '04-04-25', '04-05-06', 801);
insert into booking values('dc01', 10007, '04-05-13', '04-05-15', 1001);
insert into booking values('dc01', 10003, '04-05-20', null, 1001);


---------------------------------------------------------------------------------

--1. List all hotels which are in London. Order the result in descending order by hotel name.
select h.hotelno, h.hotelname, h.city
from hotel h
where h.city='London'
order by h.hotelname desc

--2. List all hotels whose name’s third alphabet has a ‘t’.
select* 
from hotel 
where hotelname like '__t%'

--3. List all bookings whose dateto column is NULL.
select* from booking B
where B.dateto is null

--4. List the guest name and guest address of those guests who are from Glasgow and
--their first name is Tony or last name is Farrel.
select* from guest G
where G.guestname like'Tony%' or G.guestname like '%Farrel' and G.guestaddress like '%Glasgow'

--5. List all the room nos. which were booked in the period 2005-2010. Also display the room’s
--hotel no.
select* from booking B
where B.datefrom>'2005-1-1' and B.datefrom<'2010-12-31'

--6. List all the rooms of hotel no. 1001 which are of single type and the price is between 20 to
--40
select* from room R
where R.roomno=1001 and R.type='single' and (R.price>20 and R.price<40)

--7. List the room no. along with its hotel no. whose price is maximum.
--Do the following question in 2 ways: Use ‘+’ operator as well as concat
--function.
select concat(R.roomno, ' ', R.hotelno) as HotelRoom, R.price as MaxPrice
from room R
where R.price= (select max(A.price) from room A);


--8. Show the data of hotel table as :
--The hotel whose id is (id) is in (city) and its name is (name).
--Example:
--The hotel whose is id isdc01 is in Berlin and its name is Latham.
select 'The hotel whose id is '+H.hotelno+' in city '+H.city+' and its name is '+h.hotelname
from hotel H;

--9. List all the hotels which have double as well as family type rooms.
select H.hotelno, H.hotelname, R.roomno, R.type
from hotel H
inner join room R on H.hotelno=R.hotelno
where R.type='double' or R.type='family'

--10. List all the hotels which have single as well as double type rooms but no family type room.
select H.hotelno, H.hotelname, R.roomno, R.type
from hotel H
inner join room R on H.hotelno=R.hotelno
where (R.type='single' or R.type='double') and R.type<>'family'


--11. List all the rooms which have been booked by either guest no. 10003 or by guest no.
--1007 but not by guest no 1001.
select B.hotelno, B.guestno, B.roomno
from booking B
where B.guestno=10003 or B.guestno=1007 and B.guestno<>1001
