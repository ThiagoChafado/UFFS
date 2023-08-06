library ieee;
use ieee.std_logic_1164.all;

entity or4 is
    port (
        a: in std_logic_vector(3 downto 0);
        s: out std_logic
    );
    end or4;
    
    architecture behav_or of or4 is
        begin
            s <= a(0) or a(1) or a(2) or a(3);
        end behav_or;