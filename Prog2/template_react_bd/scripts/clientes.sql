DROP TABLE clientes;

CREATE TABLE clientes
(
    id SERIAL PRIMARY KEY,
    nome VARCHAR,
    email VARCHAR
);
INSERT INTO clientes (nome, email) VALUES ('Edimar', 'edimar@uffs.edu.br');
INSERT INTO clientes (nome, email) VALUES ('Gian', 'gian@uffs.edu.br');

-- SELECT * FROM clientes;