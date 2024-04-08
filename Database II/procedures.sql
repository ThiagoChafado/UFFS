CREATE TABLE product(
    pid integer not null primary key,
    name varchar(30) not null,
    pqty integer not null
);

CREATE TABLE sale (
    sid integer not null primary key,
    sdate date not null
);

CREATE TABLE sale_item (
	sid integer not null,
	pid integer not null,
	sqty integer not null,
	CONSTRAINT pk_sale_item PRIMARY KEY (sid,pid),
	CONSTRAINT fk_sale_item_sale FOREIGN KEY (sid) REFERENCES sale(sid),
	CONSTRAINT fk_sale_item_product FOREIGN KEY (pid) REFERENCES product(pid)
);


CREATE OR REPLACE PROCEDURE insert_product(qttuple int)
AS $$
declare 
counter int:=1;
pr_tup product%rowtype;


begin
    loop
        exit when counter >qttuple;
        pr_tup.pid=(random()*10000)::int;
        if not exists (select 1 from product where pid=pr_tup.pid)
        then
            pr_tup.name=left(md5(random()::text),30);
            insert into product values (pr_tup.pid,pr_tup.name,3);
            counter:=counter +1;
        end if;
    end loop;
 end;
$$
LANGUAGE plpgsql;
