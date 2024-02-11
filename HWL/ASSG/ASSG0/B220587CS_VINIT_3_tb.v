module B220587CS_VINIT_3_tb;

	reg [7:0] x;
	reg [7:0] y;
	reg [1:0] selector;
	wire [7:0]cout;

    B220587CS_VINIT_3 uut(x,y,selector,cout);

    integer i,j,k;


initial begin
    for(i=0;i<257;i=i+1)
	 begin
        for(j=0;j<257;j=j+1) 
		  begin
            for(k=0;k<4;k=k+1)
				begin
					selector = k;
						x = i;
						y = j;
						#20;
            end
        end
    end
end

endmodule
