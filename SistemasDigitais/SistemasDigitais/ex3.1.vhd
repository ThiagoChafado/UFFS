LIBRARY IEEE;
USE ieee.std_logic_1164.ALL;

ENTITY smart_house IS
  PORT (
    -- INPUTS:

    -- open = 1 or closed = 0
    status_window : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
    -- (0): open = 1 or closed = 0
    -- (1): locked = 0 or unlocked = 1
    status_door : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    -- enabled = 1 or disabled = 0
    secure_mode : IN STD_LOGIC;
    -- night = 1 or day = 0
    daylight_sensor : IN STD_LOGIC;
    -- raining = 1 or not raining = 0
    weather_sensor : IN STD_LOGIC;
    -- temperature sensors (-20°C to 50°C in binary)
    temperature_sensor_1 : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    temperature_sensor_2 : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    -- (0001 - 25%, 0011 - 50%, 0111 - 75%, 1111 - 100%)
    level_tankA : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    -- max = 1 or not max = 0
    max_tankB : IN STD_LOGIC;

    -- OUTPUTS:

    security_alert : OUT STD_LOGIC;
    window_open_warning : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
    window_open_security_mode : OUT STD_LOGIC;
    window_open_at_night_alert : OUT STD_LOGIC;
    window_door_open_rain_alert : OUT STD_LOGIC;
    water_pump : OUT STD_LOGIC;
    electrovalve : OUT STD_LOGIC
  );
END smart_house;

ARCHITECTURE arch_smart_house OF smart_house IS

  COMPONENT security IS
    PORT (
      status_window : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
      status_door : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
      secure_mode : IN STD_LOGIC;
      security_alert : OUT STD_LOGIC;
      window_open_warning : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
      window_open_security_mode : OUT STD_LOGIC
    );
  END COMPONENT security;

  COMPONENT crepuscular_system IS
    PORT (
      status_window : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
      daylight_sensor : IN STD_LOGIC;
      window_open_at_night_alert : OUT STD_LOGIC
    );
  END COMPONENT crepuscular_system;

  COMPONENT weather_system IS
    PORT (
      weather_sensor : IN STD_LOGIC;
      status_window : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
      status_door : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
      window_door_open_rain_alert : OUT STD_LOGIC
    );
  END COMPONENT weather_system;

  COMPONENT water_system IS
    PORT (
      level_tankA : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      max_tankB : IN STD_LOGIC;
      water_pump : OUT STD_LOGIC;
      electrovalve : OUT STD_LOGIC
    );
  END COMPONENT water_system;

BEGIN

  security_comp : security
  PORT MAP(
    status_window(0) => status_window(0),
    status_window(1) => status_window(1),
    status_window(2) => status_window(2),
    status_door(0) => status_door(0),
    status_door(1) => status_door(1),
    secure_mode => secure_mode,
    security_alert => security_alert,
    window_open_warning(0) => window_open_warning(0),
    window_open_warning(1) => window_open_warning(1),
    window_open_warning(2) => window_open_warning(2),
    window_open_security_mode => window_open_security_mode
  );

  crepuscular_comp : crepuscular_system
  PORT MAP(
    status_window(0) => status_window(0),
    status_window(1) => status_window(1),
    status_window(2) => status_window(2),
    daylight_sensor => daylight_sensor,
    window_open_at_night_alert => window_open_at_night_alert
  );

  weather_comp : weather_system
  PORT MAP(
    weather_sensor => weather_sensor,
    status_window(0) => status_window(0),
    status_window(1) => status_window(1),
    status_window(2) => status_window(2),
    status_door(0) => status_door(0),
    status_door(1) => status_door(1),
    window_door_open_rain_alert => window_door_open_rain_alert
  );

  water_comp : water_system
  PORT MAP(
    level_tankA(0) => level_tankA(0),
    level_tankA(1) => level_tankA(1),
    level_tankA(2) => level_tankA(2),
    level_tankA(3) => level_tankA(3),
    max_tankB => max_tankB,
    water_pump => water_pump,
    electrovalve => electrovalve
  );

END arch_smart_house; -- arch_smart_house

-- -- -- ===========================================================================================

LIBRARY IEEE;
USE ieee.std_logic_1164.ALL;

ENTITY security IS
  PORT (
    status_window : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
    status_door : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    secure_mode : IN STD_LOGIC;
    security_alert : OUT STD_LOGIC;
    window_open_warning : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
    window_open_security_mode : OUT STD_LOGIC
  );
END security;

ARCHITECTURE arch_security OF security IS

BEGIN

  PROCESS (secure_mode, status_window, status_door)
    VARIABLE enable_security_alert : STD_LOGIC;
  BEGIN
    enable_security_alert := '0';
    IF (secure_mode = '1') THEN
      IF (status_window(0) = '1') OR (status_window(1) = '1') OR (status_window(2) = '1') THEN
        enable_security_alert := '1';
      END IF;
    END IF;

    IF (status_door(0) = '1') AND (NOT(status_door(1)) = '0') THEN
      enable_security_alert := '1';
    END IF;

    IF (secure_mode = '1') AND (NOT(status_door(1)) = '0') AND ((status_window(0) = '1') OR (status_window(1) = '1') OR (status_window(2) = '1')) THEN
      window_open_security_mode <= '1';
    ELSE
      window_open_security_mode <= '0';
    END IF;

    security_alert <= enable_security_alert;

    IF (status_window(0) = '1') THEN
      window_open_warning(0) <= '1';
    ELSE
      window_open_warning(0) <= '0';
    END IF;

    IF (status_window(1) = '1') THEN
      window_open_warning(1) <= '1';
    ELSE
      window_open_warning(1) <= '0';
    END IF;

    IF (status_window(2) = '1') THEN
      window_open_warning(2) <= '1';
    ELSE
      window_open_warning(2) <= '0';
    END IF;
  END PROCESS;

END arch_security; -- arch_security

-- ===========================================================================================

LIBRARY IEEE;
USE ieee.std_logic_1164.ALL;

ENTITY crepuscular_system IS
  PORT (
    status_window : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
    daylight_sensor : IN STD_LOGIC;
    window_open_at_night_alert : OUT STD_LOGIC
  );
END crepuscular_system;

ARCHITECTURE arch_crepuscular_system OF crepuscular_system IS

BEGIN

  PROCESS (daylight_sensor, status_window)
    VARIABLE alert : STD_LOGIC := '0';
  BEGIN
    alert := '0';
    FOR window IN 0 TO 2 LOOP
      IF (daylight_sensor = '1') AND (status_window(window) = '1') THEN
        alert := '1';
      END IF;
    END LOOP;
    IF (alert = '1') THEN
      window_open_at_night_alert <= '1';
    ELSE
      window_open_at_night_alert <= '0';
    END IF;
  END PROCESS;

END arch_crepuscular_system; -- arch_crepuscular_system

-- -- ===========================================================================================

LIBRARY IEEE;
USE ieee.std_logic_1164.ALL;

ENTITY weather_system IS
  PORT (
    weather_sensor : IN STD_LOGIC;
    status_window : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
    status_door : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    window_door_open_rain_alert : OUT STD_LOGIC
  );
END weather_system;

ARCHITECTURE arch_weather_system OF weather_system IS

BEGIN

  -- Window with rain alert
  PROCESS (weather_sensor, status_window, status_door)
    VARIABLE alert : STD_LOGIC := '0';
  BEGIN
    alert := '0';
    FOR window IN 0 TO 2 LOOP
      IF (weather_sensor = '1') AND ((status_door(1) = '1') OR (status_window(window) = '1')) THEN
        alert := '1';
      END IF;
    END LOOP;
    IF (alert = '1') THEN
      window_door_open_rain_alert <= '1';
    ELSE
      window_door_open_rain_alert <= '0';
    END IF;
  END PROCESS;

  -- -- Window open low temperature alert
  -- PROCESS ()
  -- BEGIN

  -- END PROCESS;

END arch_weather_system; -- arch_weather_system

-- -- ===========================================================================================
LIBRARY IEEE;
USE ieee.std_logic_1164.ALL;

ENTITY water_system IS
  PORT (
    level_tankA : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    max_tankB : IN STD_LOGIC;
    water_pump : OUT STD_LOGIC;
    electrovalve : OUT STD_LOGIC
  );
END water_system;

ARCHITECTURE arch_water_system OF water_system IS

BEGIN

  -- Water pump activation
  PROCESS (level_tankA, max_tankB)
  BEGIN
    IF (level_tankA(0) = '1') AND (max_tankB = '0') THEN
      water_pump <= '1';
    ELSE
      water_pump <= '0';
    END IF;
  END PROCESS;

  -- Electrovalve activation
  PROCESS (level_tankA)
  BEGIN
    IF (level_tankA(0) = '0') THEN
      electrovalve <= '1';
    ELSIF (level_tankA(3) = '1') THEN
      electrovalve <= '0';
    END IF;
  END PROCESS;
END arch_water_system;