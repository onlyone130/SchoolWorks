library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity or_and_gate is
    Port (A,B,C: in std_logic; 
           E: out std_logic );
end or_and_gate;

architecture Behavioral of or_and_gate is
begin
    F <= (A or B) and C;
end Behavioral;
