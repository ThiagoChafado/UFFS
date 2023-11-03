create table type(
  idt integer not null,
  descr varchar(20) not null,
  constraint pk_type primary key (idt));
--
create table station(
  ids integer not null,
  names varchar(20) not null,
  constraint pk_station primary key (ids));
--
create table route(
  idsfrom integer not null,
  idsto   integer not null,
  dist numeric(5,2) not null,
  constraint pk_route primary key (idsfrom, idsto),
  constraint fk_route_stationf foreign key (idsfrom) references station(ids),
  constraint fk_route_stationt foreign key (idsto) references station(ids)
);
--
create table train(
  idtr integer not null,
  nametr varchar(20) not null,
  capac integer not null,
  typet integer not null,
  constraint pk_train primary key (idtr),
  constraint fk_train_type foreign key (typet) references type(idt)
);
--
create table train_route (
   idtr integer not null,
   idsfrom integer not null,
   idsto integer not null,
   datet date not null,
   constraint pk_train_route primary key (idtr,idsfrom,idsto),
   constraint fk_train_route_train foreign key (idtr) references train(idtr),
   constraint fk_train_route_route foreign key (idsfrom,idsto) references route(idsfrom, idsto)
);

insert into type (idt,descr) values (1,'Steam'), (2,'Diesel'),(3,'Eletric');
--
insert into station (ids,names) values (1,'Batcity'),(2,'Supercity'),(3,'Mycounty'),(4,'Dragonpolis'),(5,'Giants'),
                                       (6,'Edgar Codd'), (7,'Boyce');
--
insert into train (idtr,nametr,capac,typet) values (1,'Coral',120,1),(2,'Transalpes',100,2),(3,'Border',89,2),
                                                   (4,'New',100,1), (5,'Brave',55,1);
--
insert into route (idsfrom,idsto,dist) values (1,4,34.5), (2,5,23.5), (2,3,12.4), (3,5,8.7), (1,3,17.7),
                                              (6,7,10), (5,7,13.2);
--
insert into train_route(idtr,idsfrom,idsto,datet) values (1,1,4,'10/05/2021'), (1,2,3,'11/05/2022'),(2,1,3,'12/12/2021'),
                                                         (3,3,5,'11/11/2011'),(5,6,7,'11/11/2011'),(5,5,7,'11/11/2011');

/*
Atividades:
1. Retornar as rotas cadastradas no formato:
Estação Origem	Estação Destino	Distância
Resultado (sem a rota cadastrada acima):
from		to			distance		
Batcity		Dragonpolis	34.5
Supercity	Giants		23.5
Supercity	Mycounty	12.4
Batcity		Mycounty	17.7
Mycounty	Giants		8.7	
Edgar Codd	Boyce		10.0
Giants		Boyce		13.2

2. Incluir um novo trem:
Name: Arrow Passangers: 95 Type: Diesel

3. Incluir uma nova estação:
Name: Candy Jar

4. Incluir uma nova rota:
Edgar Codd -> Candy Jar Distance: 33

5. Incluir uma nova linha para a rota recem criada:
Train: Arrow Data: 01/11/2023

6. Implementar uma consulta que retorne no formato:
Estação Origem	Estação Destino	Distância	Nome Trem	Tipo Trem	Data Partida
Resultado da consulta (sem a rota incluída acima):
from		to			distance	train_name	train_type	departure
Batcity		Dragonpolis	34.5		Coral		Steam		2021-05-10
Supercity	Mycounty	12.4		Coral		Steam		2022-05-11
Batcity		Mycounty	17.7		Transalpes	Diesel		2021-12-12
Mycounty	Giants		8.7			Border		Diesel		2021-11-11
Edgar Codd	Boyce		10.0		Brave		Steam		2021-11-11
Giants		Boyce		13.2		Brave		Steam		2021-11-11
*/
