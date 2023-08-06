library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity BatalhaNaval is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           navio1_pos : in  STD_LOGIC_VECTOR (3 downto 0);
           navio2_pos : in  STD_LOGIC_VECTOR (3 downto 0);
           navio3_pos : in  STD_LOGIC_VECTOR (7 downto 0);
           tiro_pos : in  STD_LOGIC_VECTOR (3 downto 0);
           tiro_acerto : out STD_LOGIC);
end BatalhaNaval;

architecture Behavioral of BatalhaNaval is

    type State is (N1, N2, N3, Tiros);
    signal current_state, next_state : State;
    signal navio1_foi_colocado, navio2_foi_colocado, navio3_foi_colocado : STD_LOGIC;
    signal tabuleiro : STD_LOGIC_VECTOR (15 downto 0);
    signal tiro_pos_reg, tiro_pos_next : STD_LOGIC_VECTOR (3 downto 0);
    signal tiro_acerto_reg : STD_LOGIC := '0';
    signal tiro_pos_encoded : STD_LOGIC_VECTOR (3 downto 0);

begin

<<<<<<< HEAD

=======
  
>>>>>>> d02aaaffcabfbaa33c56537dbccc50cfdcaccf7c
    process (clk, reset)
    begin
        if reset = '1' then
            current_state <= N1;
        elsif rising_edge(clk) then
            current_state <= next_state;
        end if;
    end process;

<<<<<<< HEAD

=======
    
>>>>>>> d02aaaffcabfbaa33c56537dbccc50cfdcaccf7c
    process (current_state, navio1_foi_colocado, navio2_foi_colocado, navio3_foi_colocado, tiro_pos_reg)
    begin
        next_state <= current_state;
        navio1_foi_colocado <= '0';
        navio2_foi_colocado <= '0';
        navio3_foi_colocado <= '0';
        
        tiro_acerto_reg <= '0';

        case current_state is
            when N1 =>
                if navio1_pos /= "0000" then
                    next_state <= N2;
                    navio1_foi_colocado <= '1';
                end if;

            when N2 =>
                if navio2_pos /= "0000" then
                    next_state <= N3;
                    navio2_foi_colocado <= '1';
                end if;

            when N3 =>
                if navio3_pos(3 downto 0) /= "0000" and navio3_pos(7 downto 4) /= "0000" then
                    next_state <= Tiros;
                    navio3_foi_colocado <= '1';
                end if;

            when Tiros =>
<<<<<<< HEAD
                if tiro_pos_encoded /= "0000" then
                    if tiro_pos_encoded = navio1_pos then
                        tiro_acerto_reg <= '1';
                    elsif tiro_pos_encoded = navio2_pos then
                        tiro_acerto_reg <= '1';
                    elsif tiro_pos_encoded = navio3_pos(3 downto 0) or tiro_pos_encoded = navio3_pos(7 downto 4) then
                        tiro_acerto_reg <= '1';
=======
                if tiro_pos_reg /= "0000" then
                    if tiro_pos_reg = navio1_pos then
                        tiro_acerto_reg <= '1'; 
                    elsif tiro_pos_reg = navio2_pos then
                        tiro_acerto_reg <= '1'; 
                    elsif tiro_pos_reg = navio3_pos then
                        tiro_acerto_reg <= '1'; 
>>>>>>> d02aaaffcabfbaa33c56537dbccc50cfdcaccf7c
                    end if;
                end if;

        end case;
    end process;

    -- Processo para codificar o valor de tiro_pos
    process (tiro_pos)
    begin
        case tiro_pos is
            when "0000" =>
                tiro_pos_encoded <= "0001";
            when "0001" =>
                tiro_pos_encoded <= "1100";
            when "0010" =>
                tiro_pos_encoded <= "1010";
            when "0011" =>
                tiro_pos_encoded <= "1111";
            when "0100" =>
                tiro_pos_encoded <= "0110";
            when "0101" =>
                tiro_pos_encoded <= "0000";
            when "0110" =>
                tiro_pos_encoded <= "1001";
            when "0111" =>
                tiro_pos_encoded <= "0101";
            when "1000" =>
                tiro_pos_encoded <= "0111";
            when "1001" =>
                tiro_pos_encoded <= "1110";
            when "1010" =>
                tiro_pos_encoded <= "0100";
            when "1011" =>
                tiro_pos_encoded <= "1011";
            when "1100" =>
                tiro_pos_encoded <= "1000";
            when "1101" =>
                tiro_pos_encoded <= "1101";
            when "1110" =>
                tiro_pos_encoded <= "0011";
            when "1111" =>
                tiro_pos_encoded <= "0010";
            when others =>
                tiro_pos_encoded <= "0000";
        end case;
    end process;

    -- Processo para atualizar o tabuleiro
    process (clk, reset, current_state, navio1_foi_colocado, navio2_foi_colocado, navio3_foi_colocado, tiro_pos_reg)
    begin
        if reset = '1' then
            tabuleiro <= (others => '0');
            tiro_pos_next <= (others => '0');
        elsif rising_edge(clk) then
<<<<<<< HEAD
            tabuleiro <= tabuleiro;
            tiro_pos_reg <= tiro_pos_next;
=======
            tabuleiro <= tabuleiro; 
            tiro_pos_reg <= tiro_pos_next; 
>>>>>>> d02aaaffcabfbaa33c56537dbccc50cfdcaccf7c
            case current_state is
                when N1 =>
                    if navio1_foi_colocado = '1' then
                        tabuleiro(to_integer(unsigned(navio1_pos))) <= '1';
                    end if;

                when N2 =>
                    if navio2_foi_colocado = '1' then
                        tabuleiro(to_integer(unsigned(navio2_pos))) <= '1';
                    end if;

                when N3 =>
                    if navio3_foi_colocado = '1' then
                        tabuleiro(to_integer(unsigned(navio3_pos(3 downto 0)))) <= '1';
                        tabuleiro(to_integer(unsigned(navio3_pos(7 downto 4)))) <= '1';
                    end if;

                when Tiros =>
                    
<<<<<<< HEAD
                    tiro_pos_next <= tiro_pos_encoded;
=======
                    tiro_pos_next <= tiro_pos;
>>>>>>> d02aaaffcabfbaa33c56537dbccc50cfdcaccf7c

            end case;
        end if;
    end process;

<<<<<<< HEAD

=======
    
>>>>>>> d02aaaffcabfbaa33c56537dbccc50cfdcaccf7c
    tiro_acerto <= tiro_acerto_reg;

end Behavioral;