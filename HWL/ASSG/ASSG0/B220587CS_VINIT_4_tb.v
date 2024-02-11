module B220587CS_VINIT_4_tb;

    reg [7:0] d;
    reg enable;
    reg rst;

    wire [7:0] q;

    B220587CS_VINIT_4 a1(d,enable,rst,q);

    integer i,j,k;

initial begin
    for(i=0;i<256;i=i+1)begin
        for(j=0;j<2;j=j+1) begin
            for(k=0;k<2;k=k+1)begin

                d = i;
                rst = j;
                enable = i;
                #10;
            end
        end
    end

end

endmodule

