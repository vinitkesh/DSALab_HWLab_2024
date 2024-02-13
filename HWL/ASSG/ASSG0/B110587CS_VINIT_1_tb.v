module B220587CS_VINIT_1_tb;
	reg [7:0]x,y;
	reg cin;
	wire c;
	wire [7:0]sub;
	integer i;
	B220587CS_VINIT_1 f(x,y,cin,c,sub);
	initial begin
	x=0;
	y=0;
	cin=0;

	for(i=0;i<262144;i=i+1)begin
		
		{x,y}=i;
		#20;
		end
	end
endmodule

