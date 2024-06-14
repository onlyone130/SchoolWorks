library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity td_xor is
end td_xor;

architecture Behavioral of td_xor is
    component xor_gate
        port(X: in std_logic;
            Y: in std_logic;
            F: out std_logic);
    end component;
    signal X: std_logic;
    signal Y: std_logic;
    signal F: std_logic;
begin
uut: xor_gate port map(X => X, Y => Y, F => F);
    stimulus: process
    begin 
        wait for 100 ps;
        X <= ‘0’;
        Y <= ‘0’;
        wait for 100 ps;
        X <= '0';
        Y <= '1';
        wait for 100 ps;
        X <= '1';
        Y <= '0';
        wait for 100 ps;
        X <= '1';
        Y <= '1';
        wait for 100 ps;
        X <= ‘0’;
        Y <= ‘0’;
        wait for 100 ps;
        X <= '0';
        Y <= '1';
        wait for 100 ps;
        X <= '1';
        Y <= '0';
        wait for 100 ps;
        X <= '1';
        Y <= '1';
        wait for 100 ps;
        X <= ‘0’;
        Y <= ‘0’;
        wait for 100 ps;
        X <= '0';
        Y <= '1';
        wait for 100 ps;
        X <= '1';
        Y <= '0';
        wait for 100 ps;
        X <= '1';
        Y <= '1';
        wait;
    end process;      
end Behavioral;
