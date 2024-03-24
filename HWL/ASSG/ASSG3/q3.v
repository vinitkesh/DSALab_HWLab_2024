// Design and implement a register in Verilog for a custom processor's architecture with the following specifications:
// a.   	It should be parameterized to support different data widths ranging from 8 bits to 32 bits.
// b.  	It should have one read port (read_port_1) and one write port (write_port_1).
// c.   	Both operations, read or write, are allowed at a time on the register.
// d.  	If both operations are performed on the register, then the write operation has more priority over read operation.
// Please note that you should define the module with appropriate input and output ports and ensure that it meets all the specified requirements above.
module Register #(parameter DATA_WIDTH = 8) (
    input wire clk,
    input wire reset,
    input wire read_enable,
    input wire write_enable,
    input wire [DATA_WIDTH-1:0] write_data,
    output wire [DATA_WIDTH-1:0] read_data
);

    reg [DATA_WIDTH-1:0] reg_data;

    always @(posedge clk or posedge reset) begin
        if (reset)
            reg_data <= 0;
        else if (write_enable)
            reg_data <= write_data;
    end

    assign read_data = read_enable ? reg_data : 0;

endmodule