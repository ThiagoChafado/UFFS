drop table class;

create table if not exists class(
    id SERIAL PRIMARY KEY,
    classname VARCHAR(50),
    descr VARCHAR(50)
);

insert into class (classname,descr) values ('Medicina','Aprender a fazer curativo');
insert into class (classname,descr) values ('Ciência da Computação','Fazer programa');
insert into class (classname,descr) values ('Agronomia','Tratar boi');
insert into class (classname,descr) values ('Enfermagem','Injeção');
insert into class (classname,descr) values ('Filosofia','Pensamentos');
