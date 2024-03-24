// Design and implement a register in Verilog for a custom processor's architecture with the following specifications:
// a.   	It should be a 16-bit register.
// b.  	It should have one read port (read_port_1) and one write port (write_port_1).
// c.   	Only one operation, either read or write, can be performed at a time on the register.
// d.  	Each read port should be able to access data from the register without any conflicts with write operations.
// Please note that you should define the module with appropriate input and output ports and ensure that it meets all the specified requirements above.
module Register (
    input wire clk,
    input wire reset,
    input wire read_enable,
    input wire write_enable,
    input wire [15:0] write_data,
    output wire [15:0] read_data
);

    reg [15:0] register;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            register <= 16'b0;
        end else if (write_enable) begin
            register <= write_data;
        end
    end

    assign read_data = read_enable ? register : read_data;

endmodule