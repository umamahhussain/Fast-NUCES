use [Assignment 1]

Create table Patient
(
PatientID int unique not null,
FirstName nvarchar(100),
LastName nvarchar(100),
DOB date,
Gender nvarchar(50),
Contact nvarchar(50),
Addresses nvarchar(100),
Email nvarchar(50)
)


create table Departments
(
DepID int not null unique,
DepName nvarchar(100)
)

create Table MedicalStaff
(
StaffID int unique not null,
FirstName nvarchar(100),
LastName nvarchar(100),
DOB Date,
Gender nvarchar(100),
Contact nvarchar(100),
Addresses nvarchar(100),
Roles nvarchar(100),
DepID int,
Department nvarchar(100),
)



create Table Appointments
(
AppointmentID int unique not null,
PatientID int,
StaffID int,
AppointmentDate date,
AppointmentTime time,
Statuses nvarchar(100),
)

create table Medications
(
MedicineID int unique not null,
MedicineName nvarchar(100),
Dosage int,
Instructions nvarchar(100)
)


create table Tests
(
TestID int unique not null,
TestName nvarchar(100),
TestDescription nvarchar(500),
Cost int
)


create Table MedicalRecords
(
RecordID int not null unique,
PatientID int,
StaffID int,
DateOfService date,
Diagnosis nvarchar(100),
Treatment nvarchar(100),
Prescription nvarchar(100),
TestID int,
MedID int,
Notes nvarchar(300),
)




create table Billing
(
BillID int unique not null,
PatientID int,
StaffID int,
DateOfBilling date,
TotalAmount decimal,
PaymentStatus nvarchar(50)
)



insert into Patient([PatientID],[FirstName],[LastName],[DOB],[Gender],[Contact],[Addresses],[Email])
values
(1,'Abby','William','2001-01-1','F','234789','Askari 11','abby@gmail.com'),
(2,'Becca','Heart','2002-02-2','F','145785','Askari 11','becca@gmail.com'),
(3,'Cathie','Strong','2003-03-3','F','124536','Askari 11','cathie@gmail.com'),
(4,'Darcy','William','1975-04-4','F','123455','DHA P11','darcy@gmail.com'),
(5,'Fawn','Jacobs','1955-06-12','M','126789','DHA P11','fawn@gmail.com'),
(6,'Geralt','Jacobs','2004-07-16','M','126780','Johar Town','geralt@gmail.com'),
(7,'Harry','Brown','2009-08-19','M','124892','Johar Town','harry@gmail.com'),
(8,'Indi', 'Wong','1989-09-21','M','125489','Johar Town','indi@gmail.com'),
(9,'James', 'Bree','2006-10-28','M','189481','Valencia','james@gmail.com'),
(10,'James', 'Falcon','2020-10-28','M','180421','Valencia','jamesfalcon@gmail.com')



insert into MedicalStaff([StaffID],[FirstName],[LastName],[DOB],[Gender],[Contact],[Addresses],[Roles],[DepID],[Department])
values
(1,'Nate', 'Strong','1990-05-01','M','156789','Johar Town','Doctor',1,'Cardiology'),
(2,'Edward', 'Jacobs','1990-05-01','M','356782','Johar Town','Doctor',2,'Dermatology'),
(3,'Lisa', 'Wang','1990-05-01','F','122789','Iqbal Town','Doctor',3,'Neurology'),
(4,'Sarah', 'William','1990-05-01','F','136784','Iqbal Town','Doctor',4,'Physiotherapy'),
(5,'Sydney', 'Sweenie','1998-05-01','F','123780','Lake City','Nurse',1,'Cardiology'),
(6,'Jennifer', 'Brown','1980-05-01','F','123351','Lake City','Nurse',2,'Dermatology')


insert into Departments([DepID],[DepName])
values
(1,'Cardiology'),
(2,'Dermatology'),
(3,'Neurology'),
(4,'Physiotherapy')


insert into Appointments([AppointmentID],[PatientID],[StaffID],[AppointmentDate],[AppointmentTime],[Statuses])
values
(1,1,1,'2023-9-13','10:20:14','Completed'),
(2,1,2,'2023-9-13','11:30:24','Completed'),
(3,3,3,'2023-9-14','12:40:34','Completed'),
(4,4,4,'2023-9-14','13:50:44','Completed'),
(5,5,5,'2023-9-15','14:25:54','Completed'),
(6,5,6,'2023-9-15','15:20:14','Completed'),
(7,7,1,'2023-9-15','1:20:34','Completed'),
(8,1,3,'2023-9-15','10:20:14','Completed'),
(9,1,4,'2023-9-15','11:30:24','Completed'),
(10,8,2,'2023-9-16','1:20:34','Scheduled'),
(11,9,3,'2023-9-17','1:20:34','Scheduled'),
(12,6,4,'2023-9-20','1:20:34','Scheduled'),
(13,2,5,'2023-9-20','1:20:34','Scheduled'),
(14,3,6,'2023-9-21','1:20:34','Scheduled'),
(15,4,1,'2023-9-22','1:20:34','Scheduled'),
(16,5,2,'2023-9-22','14:25:54','Scheduled'),
(17,1,4,'2023-9-22','15:20:14','Scheduled')

Insert into MedicalRecords([RecordID],[PatientID],[StaffID],[DateOfService],[Diagnosis],[Treatment],
[Prescription],[TestID],[MedID],[Notes])
values
(1,1,1,'2023-9-13','Heart Attack','Medication','Follow up',4,1,'Patient responded well to the prescribed medication. Advised to maintain a healthy lifestyle and follow up in a month.' ),
(2,1,2,'2023-9-13','Skin Infection','Medication','No Follow up',1,2,'Patient responded positively to the prescribed medication. No further follow-up needed.' ),
(5,5,5,'2023-9-15','Heart Stroke','Medication','Follow up',4,3,'Patient responded well to the prescribed medication. Advised to maintain a healthy lifestyle and follow up in a month.' ),
(3,3,3,'2023-9-14','Brain Damage','Rest','Follow up',2,null,'Patient is recovering with recommended rest. Scheduled for a follow-up next month.' ),
(4,4,4,'2023-9-14','Weak knees','Exercise','No Follow up',3,null,'Patient advised on appropriate exercises to strengthen knees. No further follow-up needed.' ),
(6,5,6,'2023-9-15','Skin Allergy','Rest','No Follow up',1,null,'Patient is recovering with recommended rest. No further follow-up needed.' ),
(7,7,1,'2023-9-15','Heart Stroke','Medication','Follow up',4,4,'Patient responded well to the prescribed medication. Advised to maintain a healthy lifestyle and follow up in a month.' ),
(8,1,3,'2023-9-15','Neural Damage','Medication','Follow up',3,3,'Patient responded well to the prescribed medication. Advised to maintain a healthy lifestyle and follow up in a month.'),
(9,1,4,'2023-9-15','Weak Arms','Exercise','No Follow up',1,null,'Patient advised on appropriate exercises to strengthen arms. No further follow-up needed.');

insert into Tests([TestID],[TestName],[Cost],[TestDescription])
values
(1,'X-Ray',2200,'An X-ray is a quick and painless procedure commonly used to produce images of the inside of the body. Its a very effective way of looking at the bones and can be used to help detect a range of conditions.'),
(2,'EMG',5000,'Electromyography (EMG) measures muscle response or electrical activity in response to a nerves stimulation of the muscle. The test is used to help detect neuromuscular abnormalities.'),
(3,'MRI',9000,'MRI, is a noninvasive medical imaging test that produces detailed images of almost every internal structure in the human body, including the organs, bones, muscles and blood vessels'),
(4,'ECG',4000,'An electrocardiogram (ECG) is a simple, non-invasive test that records the electrical activity of the heart. An ECG can help diagnose certain heart conditions, including abnormal heart rhythms and coronary heart disease');


insert into Billing([BillID],[PatientID],[StaffID],[DateofBilling],[TotalAmount],[PaymentStatus])
values
(1,1,1,'2023-9-13',2000,'UnPaid'),
(2,1,2,'2023-9-13',3000,'UnPaid'),
(3,3,3,'2023-9-14',4000,'UnPaid'),
(4,4,4,'2023-9-14',7000,'Paid'),
(5,5,5,'2023-9-15',9000,'Paid'),
(6,5,6,'2023-9-15',1000,'Paid'),
(7,7,1,'2023-9-15',500,'Paid'),
(8,1,3,'2023-9-15',1500,'UnPaid'),
(9,1,4,'2023-9-15',5500,'Paid')


insert into Medications([MedicineID],[MedicineName],[Dosage],[Instructions])
values
(1,'Panadol',2,'Oral Intake'),
(2,'Augmentin',2,'Oral Intake'),
(3,'Arinac',3,'Injection'),
(4,'Xanax',1,'IV Drip')



select* from Patient;
select* from Appointments;
select* from MedicalStaff;
select* from Departments
select* from MedicalRecords;
select* from Medications
select* from Billing;
select* from Tests;
-----------------------------------------------------------------------------------------------------------------------------------

--1.	List female patients whose contact number ends with 5 or 6 and were treated by “dr.sarah”
select P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName, P.Contact, M.StaffID,concat (M.FirstName, ' ',M.LastName ) as StaffName
from Patient P
inner join Appointments A on A.PatientID=P.PatientID 
inner join MedicalStaff M on M.StaffID=A.StaffID 
where M.FirstName='Sarah' and P.Gender='F' and (P.Contact like '%5' or P.Contact  like '%6')

--2.	list all nurses younger than 30
select M.StaffID, concat (M.FirstName, ' ',M.LastName ) as StaffName,M.Roles, M.DOB as age
from MedicalStaff M
where M.Roles='Nurse' and DATEDIFF(year,M.DOB,getdate())<30

--3.	Retrieve appointments with a "Scheduled" status for male patients (ordered by appointment date)
select P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName,P.Gender, A.Statuses ,A.AppointmentDate
from Patient P
inner join Appointments A on A.PatientID=P.PatientID
where A.Statuses='Scheduled' and P.Gender='M'
order by A.AppointmentDate asc

--4.	Retrieve the top 3 most expensive tests along with their descriptions 
select top(3) T.TestID, T.TestName,T.Cost,T.TestDescription
from Tests T
order by T.cost desc

--5.	Find all appointments scheduled for the future 
select* from Appointments A
where A.Statuses='Scheduled'

--6.	List patients who have the same last name as any medical staff (ordered by last name)
select concat (P.FirstName, ' ',P.LastName ) as PatientName, concat (M.FirstName, ' ',M.LastName ) as StaffName
from Patient P
inner join MedicalStaff M on M.LastName=P.LastName
order by P.LastName asc, M.LastName asc

--7.	Identify Patients Who Haven't Received a Bill
select A.PatientID
from Appointments A
except
select B.PatientID
from Billing B

select distinct P.PatientID ,concat (P.FirstName, ' ',P.LastName ) as PatientName
from Appointments A
inner join Patient P on P.PatientID=A.PatientID
left join Billing B on A.PatientID=B.PatientID where B.PatientID is null

--8.	List All Medications and Their Usage Instructions
select* from Medications

--10.	Find Patients Who Have Appointments But No Medical Records
select P.PatientID,concat (P.FirstName, ' ',P.LastName ) as PatientName
from Patient P
inner join Appointments A on A.PatientID=P.PatientID
left join MedicalRecords M on M.PatientID=A.PatientID where M.PatientID is null
order by P.PatientID asc

--11.	Find Patients Who Have Appointments, Medical Records, or Bills
select distinct P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName
from Patient P
right join Appointments A on A.PatientID=P.PatientID
left join MedicalRecords M on M.PatientID=P.PatientID
left join Billing B on B.PatientID=P.PatientID

select distinct P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName
from Appointments A, Patient P, Billing B, MedicalRecords M
where P.PatientID=A.PatientID OR P.PatientID=B.PatientID OR P.PatientID=M.PatientID

--12.	 Find all patients who have had appointments with doctors in the 'Cardiology' department.
select P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName, concat (M.FirstName, ' ',M.LastName ) as StaffName, M.Department
from Patient P
inner join Appointments A on A.PatientID=P.PatientID
inner join MedicalStaff M on M.StaffID=A.StaffID
where M.Department='Cardiology' and M.Roles='Doctor'

--13.	Find the doctors (medical staff) who have treated patients born after 1990 and have 'Paid' billing status.
select P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName, P.DOB ,concat (M.FirstName, ' ',M.LastName ) as StaffName, B.PaymentStatus
from Patient P
inner join Appointments A on P.PatientID=A.PatientID
inner join Billing B on A.PatientID=B.BillID
inner join MedicalStaff M on M.StaffID=A.StaffID
where B.PaymentStatus='Paid' and P.DOB>'1990-12-12'
order by P.PatientID asc

--14.	List all patients who have either 'Scheduled' or 'Completed' appointments.
select distinct P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName, A.StaffID,concat (M.FirstName, ' ',M.LastName ) as StaffName ,A.Statuses
from Patient P
inner join Appointments A on A.PatientID=P.PatientID
inner join MedicalStaff M on M.StaffID=A.StaffID
where A.Statuses='Scheduled' or A.Statuses='Completed'

select distinct P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName
from Patient P
inner join Appointments A on A.PatientID=P.PatientID
where A.Statuses='Scheduled' or A.Statuses='Completed'


--15.	 Find all patients who have both a medical record and a billing record.
select distinct P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName
from Patient P
right join MedicalRecords M on M.PatientID=P.PatientID
right join Billing B on B.PatientID=P.PatientID

select distinct P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName
from Patient P, MedicalRecords M, Billing B
where P.PatientID=M.PatientID and P.PatientID=B.PatientID

--16.	Get a list of patients who have undergone the 'X-ray' test or have been treated by 'Dr. Lisa Wang'
select P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName, concat (MS.FirstName, ' ',MS.LastName ) as StaffName,T.TestName
from Patient P
inner join MedicalRecords M on M.PatientID=P.PatientID
inner join MedicalStaff MS on M.StaffID=MS.StaffID
inner join Tests T on M.TestID=T.TestID
where MS.FirstName='Lisa' and MS.LastName='Wang' or T.TestName='X-ray'
order by PatientID asc


--17.	Find all patients who have had appointments with doctors in every department

select P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName
from Patient P
where
(
select count(distinct M.DepID) 
from MedicalStaff M
inner join Appointments A on A.StaffID=M.StaffID
where 
A.PatientID=P.PatientID
)=(select count(D.DepID) from Departments D)

--18.	Find patients who have received at least two different medications, 
--along with the list of medications they have received.

select P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName, count(M.MedID) as Meds
from Patient P
inner join MedicalRecords M on M.PatientID=P.PatientID 
group by P.PatientID,concat (P.FirstName, ' ',P.LastName )
having count(distinct M.MedID)>=2



--19.	List the names of patients who have scheduled appointments along with the department they are associated with
select P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName,concat (M.FirstName, ' ',M.LastName ) as StaffName,M.Department
from Patient P
inner join Appointments A on P.PatientID=A.PatientID
inner join MedicalStaff M on M.StaffID=A.StaffID




--20.	Retrieve the names of patients along with their medical records, including diagnosis and 
--treatment, and the names of the doctors who treated them
select P.PatientID, concat (P.FirstName, ' ',P.LastName ) as PatientName, concat (M.FirstName, ' ',M.LastName ) as StaffName,A.Diagnosis,A.Treatment
from Patient P
inner join MedicalRecords A on A.PatientID=P.PatientID
inner join MedicalStaff M on A.StaffID=M.StaffID