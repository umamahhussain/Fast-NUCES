use [Task 4];

create Table Patients
(
PatientID int unique not null,
FirstName nvarchar(100),
LastName nvarchar(100),
DOB date,
Gender nvarchar(100),
Addresses nvarchar(100),
PhoneNum nvarchar(100)
)

create Table Doctors
(
DoctorID int unique not null,
FirstName nvarchar(100),
LastName nvarchar(100),
Specialization nvarchar(100),
PhoneNum nvarchar(100)
)

create Table Appointments
(
AppointmentID int unique not null,
PatientID int,
DoctorID int,
AppointmentDate nvarchar(100),
AppointmentTime nvarchar(100)
)

create Table MedicalRecords
(
RecordID int not null unique,
PatientID int,
DoctorID int,
Diagnosis nvarchar(100),
Treatment nvarchar(100),
RecordDate nvarchar(100)
)

Insert into Patients([PatientID],[FirstName],[LastName],[DOB],[Gender],[Addresses],[PhoneNum])
values
(1,'Ahmed','Rana','2004-10-6','M','DHA','123456'),
(2,'Umamah','Hussain','2002-02-14','F','DHA','234567'),
(3,'Sadia','Hussain','1976-9-6','F','Muridke','345678'),
(4,'Aisha','Umer','1990-12-1','F','Judicial Complex','567895'),
(5,'Saima','Imran','1980-5-11','F','Bahria Town','364741'),
(6,'Eshaal','Umer','2007-1-17','F','Johar Town','102932'),
(7,'Aiza','Khurram','2006-3-18','F','Johar Town','102542')


Insert into Doctors([DoctorID],[FirstName],[LastName],[Specialization],[PhoneNum])
values
(1,'Ali','Ishfaq','Psychiatrist','345'),
(2,'Sadaf','Aleem','Cardiologist','567'),
(3,'Malaika','Imran','Opthamologist','789'),
(4,'Ali','Ahmed','Psychiatrist','785'),
(5,'Hamza','Imran','Opthamologist','785')

Insert into Appointments([AppointmentID],[PatientID],[DoctorID],[AppointmentDate],[AppointmentTime])
values
(1,1,1,'7-8-23','1:50 pm'),
(2,2,2,'7-8-23','2:50 pm'),
(3,3,3,'8-8-23','3:50 pm'),
(4,4,4,'8-8-23','4:50 pm'),
(5,5,5,'12-8-23','5:50 pm'),
(6,6,1,'14-8-23','1:50 pm'),
(7,1,2,'18-8-23','8:50 pm'),
(8,6,1,'12-8-23','1:50 pm'),
(9,5,2,'14-8-23','2:50 pm'),
(10,4,3,'13-8-23','3:50 pm'),
(11,3,4,'13-8-23','4:50 pm'),
(12,2,5,'7-8-23','5:50 pm'),
(13,1,1,'8-8-23','1:50 pm'),
(14,1,2,'18-8-23','8:50 pm')

Insert into MedicalRecords([RecordID],[PatientID],[DoctorID],[Diagnosis],[Treatment],[RecordDate])
values
(1,1,1,'HyperTension','Medication','7-8-23'),
(2,2,2,'Heart Attack','Medication','7-8-23'),
(3,3,3,'Allergy','Medication','8-8-23'),
(4,4,4,'OCD','Medication','8-8-23'),
(5,5,5,'Allergy','Medication','12-8-23'),
(6,6,1,'HyperTension','Medication','14-8-23'),
(7,1,2,'Stress','Medication','18-8-23'),
(8,6,1,'HyperTension','Medication','12-8-23'),
(9,5,2,'Heart Stroke','Medication','14-8-23'),
(10,4,3,'Infection','Medication','13-8-23'),
(11,3,4,'OCD','Medication','13-8-23'),
(12,2,5,'Infection','Medication','7-8-23'),
(13,1,1,'HyperTension','Medication','8-8-23'),
(14,1,2,'OCD','Medication','18-8-23')

select * from Patients;
select* from Appointments;
select* from Doctors;
select* from MedicalRecords;


--Find the total number of appointments for each doctor
select A.DoctorID,  concat(D.FirstName, ' ', D.LastName) as DoctorName, count(*) as TotalAppointments
from Appointments A
inner join Doctors D on A.DoctorID=D.DoctorID
group by A.DoctorID, concat(D.FirstName, ' ', D.LastName)

--Retrieve a list of doctors and their specializations, along with the number of patients they have 
--seen.
select  A.DoctorID,  concat(D.FirstName, ' ', D.LastName) as DoctorName, D.Specialization, count(*) as TotalAppointments
from Appointments A
inner join Doctors D on A.DoctorID=D.DoctorID
group by A.DoctorID, D.Specialization, concat(D.FirstName, ' ', D.LastName)

--Find the average age of patients who have visited each doctor
select  A.DoctorID, concat(D.FirstName,' ',D.LastName) as DoctorName, count(*) as TotalPatients, avg(datediff(year, P.DOB, getdate())) as AverageAge
from Doctors D, Patients P, Appointments A
where A.DoctorID=D.DoctorID and  A.PatientID=P.PatientID
group by A.DoctorID, concat(D.FirstName,' ',D.LastName)
order by A.DoctorID asc

--Find patients who have the same diagnosis from the same doctor and list their names along with 
--the common diagnosis.
select 
M.DoctorID, concat(D.FirstName,' ',D.LastName) as DoctorName, 
concat(P.FirstName,' ',P.LastName) as PatientName, M.Diagnosis
from MedicalRecords M
inner join Doctors D on M.DoctorID=D.DoctorID
inner join Patients P on P.PatientID=M.PatientID
group by M.DoctorID,M.Diagnosis, concat(D.FirstName,' ',D.LastName), concat(P.FirstName,' ',P.LastName)
having count(*) > 1;

--Retrieve the top 5 doctors with the highest number of appointments
select Top(5) A.DoctorID,  concat(D.FirstName, ' ', D.LastName) as DoctorName, count(*) as TotalAppointments
from Appointments A
inner join Doctors D on A.DoctorID=D.DoctorID
group by A.DoctorID,  concat(D.FirstName, ' ', D.LastName)

--Find the total number of appointments for each patient who has had more than 3 
--appointments, and list them in ascending order of appointment count
select A.PatientID, concat(P.FirstName,' ',P.LastName) as PatientName, count(*) as TotalAppointments
from Appointments A
inner join Patients P on P.PatientID=A.PatientID
group by A.PatientID, concat(P.FirstName,' ',P.LastName) 
having count(*)>3

--Retrieve the list of doctors who have seen at least 10 different patients, ordered by the number 
--of different patients seen in descending order
select A.DoctorID, concat(D.FirstName, ' ', D.LastName) as DoctorName,count(*) as DiffPatients
from Appointments A
inner join Doctors D on A.DoctorID=D.DoctorID
group by A.DoctorID, concat(D.FirstName, ' ', D.LastName)
having count(distinct A.PatientID)>1
order by DiffPatients desc



