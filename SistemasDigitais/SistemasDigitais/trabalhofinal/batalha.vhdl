library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity finalproject is
    port (
        SW : in std_logic_vector(9 downto 0); -- cordinates collection
        KEY : in std_logic_vector(3 downto 0); -- clock = key(0) & reset = key(3)

        LEDR : out std_logic_vector(9 downto 0); -- shot connected
        LEDG : out std_logic_vector(7 downto 0); -- shot missed
        HEX0 : out std_logic_vector(6 downto 0);
        HEX1 : out std_logic_vector(6 downto 0);
        HEX2 : out std_logic_vector(6 downto 0);
        HEX3 : out std_logic_vector(6 downto 0);
		  CLOCK_21 : out std_logic_vector(2 downto 0)
    );
end finalproject;

architecture finalproject_behav of finalproject is

	type state_type is (B, P1, P2, P3, S, V, L);
	
	signal state : state_type := B;
	signal bullets : integer range 0 to 6 := 6 ;
	signal boat1, boat2, boat3: std_logic_vector(3 downto 0);
	signal shotsHitted : std_logic_vector(3 downto 0) := "0000";
	
	function codify (
		coord_in : in std_logic_vector(3 downto 0))
		return std_logic_vector is
		variable code_out : std_logic_vector(3 downto 0);
	begin
		if coord_in = "0000" then
			code_out := "0101";
		elsif coord_in = "0001" then
			code_out := "0000";
		elsif coord_in = "0010" then
			code_out := "1111";
		elsif coord_in = "0011" then
			code_out := "1110";
		elsif coord_in = "0100" then
			code_out := "1010";
		elsif coord_in = "0101" then
			code_out := "0111";
		elsif coord_in = "0110" then
			code_out := "0100";
		elsif coord_in = "0111" then
			code_out := "1000";
		elsif coord_in = "1000" then
			code_out := "1100";
		elsif coord_in = "1001" then
			code_out := "0110";
		elsif coord_in = "1010" then
			code_out := "0010";
		elsif coord_in = "1011" then
			code_out := "1011";
		elsif coord_in = "1100" then
			code_out := "0001";
		elsif coord_in = "1101" then
			code_out := "1101";
		elsif coord_in = "1110" then
			code_out := "1001";
		elsif coord_in = "1111" then
			code_out := "0011";
		end if;
		return code_out;
	end function;
	
begin
	process(KEY)
		variable aux_boat : std_logic_vector(3 downto 0);
		variable coord_b : std_logic_vector(3 downto 0);
		variable auxshoots : std_logic_vector(3 downto 0);
		variable auxbullets : integer range 0 to 6;
	begin
		if KEY(0) = '0' then
			state <= B;
			LEDR <= "0000000000";
			LEDG <= "00000000";
			shotsHitted <="0000";
		elsif (KEY(1)'event and KEY(1) = '0') then
			case state is
				when B =>
					state <= P1;
					bullets <= 6;
					
				when P1 =>
					coord_b(0) := SW(0);
					coord_b(1) := SW(1);
					coord_b(2) := SW(2);
					coord_b(3) := SW(3);
					
					aux_boat := codify(coord_b);
					boat1 <= aux_boat;
					
					LEDR(0) <= aux_boat(0);
					LEDR(1) <= aux_boat(1);
					LEDR(2) <= aux_boat(2);
					LEDR(3) <= aux_boat(3);
					
					LEDG(7) <= '1';
					state <= P2;
					
				when P2 =>
					LEDR <= "0000000000";
					
					coord_b(0) := SW(0);
					coord_b(1) := SW(1);
					coord_b(2) := SW(2);
					coord_b(3) := SW(3);
					
					aux_boat := codify(coord_b);
					boat2 <= aux_boat;
					
					if(aux_boat = boat1) then
						LEDR <= "1111111111";
					else
						LEDR(0) <= aux_boat(0);
						LEDR(1) <= aux_boat(1);
						LEDR(2) <= aux_boat(2);
						LEDR(3) <= aux_boat(3);
						
						LEDG(6) <= '1';
						state <= P3;
					end if;
					
				when P3 =>
					LEDR <= "0000000000";
					
					coord_b(0) := SW(0);
					coord_b(1) := SW(1);
					coord_b(2) := SW(2);
					coord_b(3) := SW(3);
					
					aux_boat := codify(coord_b);
					boat3 <= aux_boat;
					
					if(aux_boat = boat1 or aux_boat = boat2) then
						LEDR <= "1111111111";
					else
						LEDR(0) <= aux_boat(0);
						LEDR(1) <= aux_boat(1);
						LEDR(2) <= aux_boat(2);
						LEDR(3) <= aux_boat(3);
						
						LEDG(5) <= '1';
						state <= S;
					end if;
					
				when S =>
					LEDR <= "0000000000";
					if bullets > 0 then
						coord_b(0) := SW(0);
						coord_b(1) := SW(1);
						coord_b(2) := SW(2);
						coord_b(3) := SW(3);
						
						auxbullets := bullets;
						auxshoots := shotsHitted;
						if coord_b = boat1 then
							auxshoots(0) := '1';
							LEDG(7) <= '0';
							if auxbullets = 1 then auxbullets := auxbullets + 1; end if;
						elsif coord_b = boat2 then
							auxshoots(1) := '1';
							LEDG(6) <= '0';
							if auxbullets = 1 then auxbullets := auxbullets + 1; end if;
						elsif coord_b = boat3 then
							auxshoots(2) := '1';
							LEDG(5) <= '0';
							if auxbullets = 1 then auxbullets := auxbullets + 1; end if;
						else
							LEDR <= "1111111111";
						end if;
						
						auxbullets := auxbullets - 1;
					end if;
					
					bullets <= auxbullets;
					shotsHitted <= auxshoots;
					
					if shotsHitted = "0111" then
						state <= V;
					elsif bullets < 1 then
						state <= L;
					end if;
					
				when V =>
					state <= B;
				when L =>
					state <= B;
			end case;
		end if;
 	end process;

	process(state)
	begin
		case state is
			when B =>
				HEX3(0) <= '1';
				HEX3(1) <= '1';
				HEX3(2) <= '1';
				HEX3(3) <= '1';
				HEX3(4) <= '1';
				HEX3(5) <= '1';
				HEX3(6) <= '0';
				
				HEX2(0) <= '1';
				HEX2(1) <= '1';
				HEX2(2) <= '1';
				HEX2(3) <= '1';
				HEX2(4) <= '1';
				HEX2(5) <= '1';
				HEX2(6) <= '0';
				
				HEX0(0) <= '1';
				HEX0(1) <= '1';
				HEX0(2) <= '1';
				HEX0(3) <= '1';
				HEX0(4) <= '1';
				HEX0(5) <= '1';
				HEX0(6) <= '0';
				
				HEX1(0) <= '1';
				HEX1(1) <= '1';
				HEX1(2) <= '1';
				HEX1(3) <= '1';
				HEX1(4) <= '1';
				HEX1(5) <= '1';
				HEX1(6) <= '0';

			when P1 =>
				HEX3(0) <= '1';
				HEX3(1) <= '1';
				HEX3(2) <= '1';
				HEX3(3) <= '1';
				HEX3(4) <= '1';
				HEX3(5) <= '1';
				HEX3(6) <= '0';
				
				HEX2(0) <= '1';
				HEX2(1) <= '0';
				HEX2(2) <= '0';
				HEX2(3) <= '1';
				HEX2(4) <= '1';
				HEX2(5) <= '1';
				HEX2(6) <= '1';
				
			when P2 =>
				HEX3(0) <= '1';
				HEX3(1) <= '1';
				HEX3(2) <= '1';
				HEX3(3) <= '1';
				HEX3(4) <= '1';
				HEX3(5) <= '1';
				HEX3(6) <= '0';
				
				HEX2(0) <= '0';
				HEX2(1) <= '0';
				HEX2(2) <= '1';
				HEX2(3) <= '0';
				HEX2(4) <= '0';
				HEX2(5) <= '1';
				HEX2(6) <= '0';
				
			when P3 =>
				HEX3(0) <= '1';
				HEX3(1) <= '1';
				HEX3(2) <= '1';
				HEX3(3) <= '1';
				HEX3(4) <= '1';
				HEX3(5) <= '1';
				HEX3(6) <= '0';
				
				HEX2(0) <= '0';
				HEX2(1) <= '0';
				HEX2(2) <= '0';
				HEX2(3) <= '0';
				HEX2(4) <= '1';
				HEX2(5) <= '1';
				HEX2(6) <= '0';
			when S =>
				HEX2 <= "1111111";
				case bullets is
					when 0 =>
						HEX3(0) <= '0';
						HEX3(1) <= '0';
						HEX3(2) <= '0';
						HEX3(3) <= '0';
						HEX3(4) <= '0';
						HEX3(5) <= '0';
						HEX3(6) <= '1';
						
						HEX2(0) <= '1';
						HEX2(1) <= '1';
						HEX2(2) <= '1';
						HEX2(3) <= '1';
						HEX2(4) <= '1';
						HEX2(5) <= '1';
						HEX2(6) <= '0';
						
					when 1 =>
						HEX2(0) <= '1';
						HEX2(1) <= '1';
						HEX2(2) <= '1';
						HEX2(3) <= '1';
						HEX2(4) <= '1';
						HEX2(5) <= '1';
						HEX2(6) <= '0';
						
						HEX3(0) <= '1';
						HEX3(1) <= '0';
						HEX3(2) <= '0';
						HEX3(3) <= '1';
						HEX3(4) <= '1';
						HEX3(5) <= '1';
						HEX3(6) <= '1';
					when 2 =>
						HEX2(0) <= '1';
						HEX2(1) <= '1';
						HEX2(2) <= '1';
						HEX2(3) <= '1';
						HEX2(4) <= '1';
						HEX2(5) <= '1';
						HEX2(6) <= '0';
						HEX3(0) <= '0';
						HEX3(1) <= '0';
						HEX3(2) <= '1';
						HEX3(3) <= '0';
						HEX3(4) <= '0';
						HEX3(5) <= '1';
						HEX3(6) <= '0';
					when 3 =>
					
						HEX2(0) <= '1';
						HEX2(1) <= '1';
						HEX2(2) <= '1';
						HEX2(3) <= '1';
						HEX2(4) <= '1';
						HEX2(5) <= '1';
						HEX2(6) <= '0';
						HEX3(0) <= '0';
						HEX3(1) <= '0';
						HEX3(2) <= '0';
						HEX3(3) <= '0';
						HEX3(4) <= '1';
						HEX3(5) <= '1';
						HEX3(6) <= '0';
					when 4 =>
						HEX2(0) <= '1';
						HEX2(1) <= '1';
						HEX2(2) <= '1';
						HEX2(3) <= '1';
						HEX2(4) <= '1';
						HEX2(5) <= '1';
						HEX2(6) <= '0';
						HEX3(0) <= '1';
						HEX3(1) <= '0';
						HEX3(2) <= '0';
						HEX3(3) <= '1';
						HEX3(4) <= '1';
						HEX3(5) <= '0';
						HEX3(6) <= '0';
					when 5 =>
						HEX2(0) <= '1';
						HEX2(1) <= '1';
						HEX2(2) <= '1';
						HEX2(3) <= '1';
						HEX2(4) <= '1';
						HEX2(5) <= '1';
						HEX2(6) <= '0';
						HEX3(0) <= '0';
						HEX3(1) <= '1';
						HEX3(2) <= '0';
						HEX3(3) <= '0';
						HEX3(4) <= '1';
						HEX3(5) <= '0';
						HEX3(6) <= '0';
					when 6 =>
						HEX2(0) <= '1';
						HEX2(1) <= '1';
						HEX2(2) <= '1';
						HEX2(3) <= '1';
						HEX2(4) <= '1';
						HEX2(5) <= '1';
						HEX2(6) <= '0';
						HEX3(0) <= '0';
						HEX3(1) <= '1';
						HEX3(2) <= '0';
						HEX3(3) <= '0';
						HEX3(4) <= '0';
						HEX3(5) <= '0';
						HEX3(6) <= '0';
				end case;

			when V =>
				HEX3(0) <= '1';
				HEX3(1) <= '0';
				HEX3(2) <= '0';
				HEX3(3) <= '0';
				HEX3(4) <= '0';
				HEX3(5) <= '0';
				HEX3(6) <= '1';
				
				HEX2(0) <= '1';
				HEX2(1) <= '1';
				HEX2(2) <= '1';
				HEX2(3) <= '1';
				HEX2(4) <= '1';
				HEX2(5) <= '1';
				HEX2(6) <= '1';
				
				HEX1(0) <= '1';
				HEX1(1) <= '1';
				HEX1(2) <= '1';
				HEX1(3) <= '1';
				HEX1(4) <= '1';
				HEX1(5) <= '1';
				HEX1(6) <= '1';
				
				HEX0(0) <= '1';
				HEX0(1) <= '1';
				HEX0(2) <= '1';
				HEX0(3) <= '1';
				HEX0(4) <= '1';
				HEX0(5) <= '1';
				HEX0(6) <= '1';
			when L =>
				HEX3(0) <= '1';
				HEX3(1) <= '0';
				HEX3(2) <= '0';
				HEX3(3) <= '0';
				HEX3(4) <= '0';
				HEX3(5) <= '1';
				HEX3(6) <= '0';
				
				HEX2(0) <= '1';
				HEX2(1) <= '1';
				HEX2(2) <= '1';
				HEX2(3) <= '1';
				HEX2(4) <= '1';
				HEX2(5) <= '1';
				HEX2(6) <= '1';
				
				HEX1(0) <= '1';
				HEX1(1) <= '1';
				HEX1(2) <= '1';
				HEX1(3) <= '1';
				HEX1(4) <= '1';
				HEX1(5) <= '1';
				HEX1(6) <= '1';
				
				HEX0(0) <= '1';
				HEX0(1) <= '1';
				HEX0(2) <= '1';
				HEX0(3) <= '1';
				HEX0(4) <= '1';
				HEX0(5) <= '1';
				HEX0(6) <= '1';
			end case;
	end process;
end finalproject_behav;
