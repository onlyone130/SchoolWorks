library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity xor_gate is 
	port(X, Y: in std_logic;
		  F: out std_logic); 
end xor_gate;

architecture Behavioral of xor_gate is
begin
   F <= X xor Y;
end Behavioral;
