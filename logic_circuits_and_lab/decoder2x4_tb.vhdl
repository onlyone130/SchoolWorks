library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity decoder2x4_tb is 
end decoder2x4_tb;

architecture bench of decoder2x4_tb is
    component decoder2x4 	
       port(x: in std_logic_vector(1 downto 0);
            out0, out1, out2, out3: out std_logic); 
    end component;
    signal x: std_logic_vector(1 downto 0);
    signal out0, out1, out2, out3: std_logic;
begin
    uut: decoder2x4 port map(x => x, out0 => out0, 
			out1 => out1, out2 => out2, out3 => out3);
    stimulus: process
    begin 
    	wait for 30 ns;
        	x <= "00";
    	wait for 30 ns;
        	x <= "01";
    	wait for 30 ns;
        	x <= "10";
    	wait for 30 ns;
        	x <= "11";
    	wait;
	end process;
end bench; 
