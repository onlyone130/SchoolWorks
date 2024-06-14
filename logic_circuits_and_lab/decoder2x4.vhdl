library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decoder2x4 is 
	port(x: in std_logic_vector(1 downto 0);
           out0, out1, out2, out3: out std_logic);
end decoder2x4;

architecture Dataflow of decoder2x4 is
begin  
      out0 <= not x(1) and not x(0);
      out1 <= not x(1) and x(0);
      out2 <= x(1) and not x(0);
      out3 <= x(1) and x(0);
end Dataflow;
