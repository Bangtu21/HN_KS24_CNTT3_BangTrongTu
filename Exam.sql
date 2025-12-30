create database it202exam;
use it202exam;

create table Student (
	student_id int primary key auto_increment,
    student_name varchar(50) not null,
    student_email varchar(100) not null unique,
    student_phone char(10) not null
);

create table Course (
	course_id int primary key auto_increment,
    course_name varchar(100) not null,
    course_credit int check(course_credit > 0)
);

create table enrollment (
	student_id int,
    course_id int,
    
    gradle decimal(4, 2) check (gradle between 0 and 10) default(0),
    
    primary key (student_id, course_id),
    foreign key (student_id) references Student(student_id),
    foreign key (course_id) references Course(course_id)
);

insert into Student (student_name, student_email, student_phone)
values
	('Bàng Trọng Tú', 'tu@gmail.com', '0987654321'),
    ('Nguyễn Văn Anh', 'anh@gmail.com', '0112233445'),
    ('Đặng Minh Bình', 'binh@gmail.com', '0998877665'),
    ('Phạm Minh Cường', 'cuong@gmail.com', '0556677889'),
    ('Hà Quốc Duy', 'duy@gmail.com', '0192837465');
    
insert into Course (course_name, course_credit)
values
	('Lập trình C', 10),
    ('Lập trình java', 12),
    ('Lập trình python', 24),
    ('Lập trình C++', 17),
    ('Lập trình Frontend', 27);
    
insert into enrollment (student_id, course_id, gradle)
values
	(1, 1, 9.5),
    (2, 3, 7.75),
    (3, 4, 7),
    (4, 5, 8.25),
    (5, 2, 9);
    
update enrollment 
set gradle = 9
where student_id = 2 and course_id = 3;

select student_name, student_email, student_phone from Student;

delete from Course where course_id = 101; 
-- Hệ thống báo xóa thành công nhưng trong bảng Course không có id là 101 nên không có sự thay đổi
    


