
module B220587CS_VINIT_3 (
	input [7:0] x , 
	input [7:0] y , 
	input [1:0] selector,
	
	output reg [7:0] cout
);	
	always @(*)
	begin
		case(selector)
			2'b00: cout = x+y;
			2'b01: cout = x-y;            
			2'b10: cout = x^y;
			2'b11: cout = x<<1;
		default: cout=0;
	  endcase
	end
endmodule

