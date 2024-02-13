```v
module B220587CS_VINIT_2(input [7:0]x,
	input [7:0]y,
	input cin,
	output reg c,
	output reg[7:0]sub
);
	
	always@(x or y or cin)
	begin
		{c,sub}=x+y+cin;
	end
endmodule
```