module B220587CS_VINIT_ 4(
    input [7:0] d,
    input enable,
    input rst,
    output reg [7:0] q
);

always@(*)
begin
    if(!rst)
        q<=0;
    else
        if(enable)
            q<=d;
end
endmodule

