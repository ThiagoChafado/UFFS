LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY elevator IS
    PORT (
        CLK, RST : IN STD_LOGIC;
        floor_btn : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        floor_out : OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
    );
END elevator;

ARCHITECTURE elevator_behav OF elevator IS

    TYPE state_type IS (T, A, B, C, M);
    TYPE behav_type IS (U, D);

    SIGNAL state : state_type;
    SIGNAL prev_state : state_type;
    SIGNAL behav_state : behav_type;
    SIGNAL stop_behav : STD_LOGIC;
BEGIN

    PROCESS (state)
    BEGIN
        CASE state IS
            WHEN T =>
                floor_out <= "0001";
            WHEN A =>
                floor_out <= "0010";
            WHEN B =>
                floor_out <= "0011";
            WHEN C =>
                floor_out <= "0100";
            WHEN M =>

        END CASE;
    END PROCESS;

    PROCESS (CLK, RST)
    BEGIN
        IF RST = '1' THEN
            state <= T;
        ELSIF (CLK'EVENT AND CLK = '1') THEN
            CASE state IS
                WHEN M =>
                    CASE prev_state IS
                        WHEN T =>
                            state <= A;
                        WHEN A =>
                            IF behav_state = D THEN
                                state <= T;
                            ELSIF behav_state = U THEN
                                state <= B;
                            END IF;
                        WHEN B =>
                            IF behav_state = D THEN
                                state <= A;
                            ELSIF behav_state = U THEN
                                state <= C;
                            END IF;
                        WHEN C =>
                            state <= B;
                        WHEN M =>
                    END CASE;
                WHEN T =>
                    IF floor_btn > floor_out THEN
                        prev_state <= state;
                        state <= M;
                    END IF;
                WHEN A =>
                    IF floor_btn > floor_out THEN
                        prev_state <= A;
                        behav_state <= U;
                        state <= M;
                    ELSIF floor_btn < floor_out THEN
                        prev_state <= A;
                        behav_state <= D;
                        state <= M;
                    END IF;
                WHEN B =>
                    IF floor_btn > floor_out THEN
                        prev_state <= B;
                        behav_state <= U;
                        state <= M;
                    ELSIF floor_btn < floor_out THEN
                        prev_state <= B;
                        behav_state <= D;
                        state <= M;
                    END IF;
                WHEN C =>
                    IF floor_btn > floor_out THEN
                        prev_state <= C;
                        behav_state <= U;
                        state <= M;
                    ELSIF floor_btn < floor_out THEN
                        prev_state <= C;
                        behav_state <= D;
                        state <= M;
                    END IF;
            END CASE;
        END IF;
    END PROCESS;

END elevator_behav;