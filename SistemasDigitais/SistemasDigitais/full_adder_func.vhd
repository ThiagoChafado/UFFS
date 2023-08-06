
library ieee;
use ieee.std_logic_1164.all;

--------------------------------------------------

entity adder4bits is
port(	
    a,b: in std_logic_vector(3 downto 0);
    carry_in : in std_logic;
	carry: out std_logic;
    sum_out: out std_logic_vector(3 downto 0)
);
end adder4bits;  

--------------------------------------------------

architecture behav_4bits of adder4bits is
    component half_adder is
        port(	
            a,b: in std_logic;
            carry, sum_out: out std_logic
        );
        end component half_adder;  

    signal x,y,z :std_logic;
begin

    carry <= z OR Y;

    ha1: half_adder
            PORT MAP (
                a => a, 
                b => b, 
                sum => x, 
                carry => y
            );

    ha2: half_adder
        PORT MAP (
            a => x,
            b => carry_in,
            sum => sum,
            carry => z
        );

end behav_4bits;

-------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;



entity half_adder is
    port(	
        a,b: in std_logic;
        carry, sum: out std_logic
    );
    end half_adder;  
    
    --------------------------------------------------
    
    architecture behav_add of half_adder is
    begin
    
        carry <= a AND b;
        sum <= a XOR b;
    
    end behav_add;
    
    --------------------------------------------------
    
    
    


--------------------------------------------------



--------------------------------------------------



library ieee;
use ieee.std_logic_1164.all;

--------------------------------------------------

entity full_adder is
port(	
    a,b: in std_logic;
    carry_in : in std_logic;
	carry, sum: out std_logic
);
end full_adder;  

--------------------------------------------------

architecture behav1 of full_adder is
    component half_adder is
        port(	
            a,b: in std_logic;
            carry, sum: out std_logic
        );
        end component half_adder;  

    signal x,y,z :std_logic;
begin

    carry <= z OR Y;

    ha1: half_adder
            PORT MAP (
                a => a, 
                b => b, 
                sum => x, 
                carry => y
            );

    ha2: half_adder
        PORT MAP (
            a => x,
            b => carry_in,
            sum => sum,
            carry => z
        );

end behav1;

-------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;



entity half_adder is
    port(	
        a,b: in std_logic;
        carry, sum: out std_logic
    );
    end half_adder;  
    
    --------------------------------------------------
    
    architecture behav_add of half_adder is
    begin
    
        carry <= a AND b;
        sum <= a XOR b;
    
    end behav_add;
    
    --------------------------------------------------
    
    
    


--------------------------------------------------
