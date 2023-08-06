library ieee;
use ieee.std_logic_1164.all;

entity half_adder is
port(
	a,b: in std_logic;
	carry,sum: out std_logic
);
end half_adder;

architecture behav_add of half_adder is
begin 
    carry <= a AND b;
    sum <= a XOR b;

    end behav_add;