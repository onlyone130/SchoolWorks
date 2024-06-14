library IEEE;
use IEEE.STD_LOGIC_1164.all;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity tb_or_and is 
end tb_or_and;

architecture Behavioral of tb_or_and is
    component or_and_gate 	
       port(A, B, C: in std_logic;
		   E: out std_logic); 
    end component;
    signal A, B, C: std_logic;
    signal E: std_logic;

begin
    uut: or_and_gate port map(A => A, B => B, 
			C => C, E => E);
    stimulus: process
    begin 
    	wait for 100 ps;
        	A <= '0';
        	B <= '0';
		C <= '0';
    	wait for 100 ps;
        	A <= '0';
		B <= '0';
		C <= '1';
    	wait for 100 ps;
        	A <= '0';
        	B <= '1';
		C <= '0';
    	wait for 100 ps;
        	A <= '0';
        	B <= '1';
		C <= '1';
    	wait for 100 ps;
        	A <= '1';
        	B <= '0';
		C <= '0';
    	wait for 100 ps;
        	A <= '1';
        	B <= '0';
		C <= '1';
    	wait for 100 ps;
        	A <= '1';
        	B <= '1';
		C <= '0';
    	wait for 100 ps;
        	A <= '1';
        	B <= '1';
		C <= '1';
    	wait;
	end process;
end Behavioral; 
