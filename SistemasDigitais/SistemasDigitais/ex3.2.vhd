library ieee;
use ieee.std_logic_1164.all;

entity desc is
    port(
        a,b,c:in std_logic;
        d,e: out std_logic
    );
    end desc;

    architecture arc_desc of desc is
        signal op1,op2,op3,op4: std_logic;

        begin
            op1 <=(NOT a) AND b;
            op2 <= (NOT a) AND c;
            op3 <= b AND c;
            op4 <= a XOR b;
        

            d <= op1 OR op2 OR op3;
            e <= op4 XOR c;
            

        end arc_desc;