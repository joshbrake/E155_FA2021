/*
  FPGA Test Module
  Brief:
    Success:
      1) LED1 and LED2 flash at 1 Hz on MAX1000 board
      2) PB0 in the bar LED toggles at 1 Hz on MAX1000 shield
    Failure:
      1) If neither LED1 or LED2 is blinking, then you have an issue with the
         FPGA. You don't have enough information at this point to know if the
         MCU is working or not.
      2) If LED1 is blinking but LED2 is not, then this indicates that
        something is wrong with your MCU.
      
  Pin assignments:
    PIN_H6:  clk_in, 12MHz clock
    PIN_L12: blink_out, ~1Hz clock output to MCU (D2/PA10)
    PIN_A8:  blink_out_copy, Mirror of clock output to MCU for debugging.
    PIN_J10: blink_echo, ~1Hz echoed clock input from MCU (D7/PA8)
    PIN_A9:  led_out, output of echoed blinking from MCU.
*/

module fpga_blinkpcb (
              input  logic clk_in,
              input  logic blink_echo,
              output logic blink_out,
              output logic blink_out_copy
              output logic led_out
              );
  
  assign blink_out = clk_divide[23];
  assign blink_out_copy = clk_divide[23];
  assign led_out = blink_echo;
  
    
  logic [24:0] clk_divide;
  always @(posedge clk_in) 
  begin
    clk_divide <= clk_divide + 1;
  end
  

endmodule
