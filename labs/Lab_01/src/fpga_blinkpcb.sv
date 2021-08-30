/*
  FPGA Test Module
  Brief:
    Success:
      1) LED[0] flashes at 1 Hz on MAX1000 board
      2) PB0 in the bar LED toggles at 1 Hz on MAX1000 shield
      
  Pin assignments:
    PIN_H6:  clk_in, 12MHz clock
    PIN_L12: blink_out, ~1Hz clock output to MCU (D2/PA10)
    PIN_J10: blink_echo, ~1Hz echoed clock input from MCU (D7/PA8)
    PIN_A8:  led_out, BLINK_GOOD output
  
  If the microcontroller has failed, the echoed clock will not appear on blink_echo,
  and mcu_out will remain high
  
  If the FPGA has failed, mcu_out will remain low.
*/

module fpga_blinkpcb (
              input logic clk_in,
              input logic blink_echo,
              output logic blink_out,
              output logic led_out
              );
  
  assign blink_out = clk_divide[23];
  assign led_out = blink_echo;
  
    
  logic [24:0] clk_divide;
  always @(posedge clk_in) 
  begin
    clk_divide <= clk_divide + 1
  end
  

endmodule
