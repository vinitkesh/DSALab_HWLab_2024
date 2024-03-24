module CustomRegister (
    input wire clk,
    input wire reset,
    input wire read_port_1,
    input wire write_port_1,
    input wire write_port_2,
    output wire [15:0] data_out
);

    reg [15:0] register;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            register <= 16'b0;
        end 
        else if (write_port_1) begin
            register <= write_port_1;
        end 
        else if (write_port_2) begin
            register <= write_port_2;
        end
    end

    assign data_out = read_port_1 ? register : 16'b0;

endmodule
