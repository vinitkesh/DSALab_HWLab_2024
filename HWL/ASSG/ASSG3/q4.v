// Design and implement a register file in Verilog for a simple processor with the following specifications:
// a.   	It should contain 8 registers, each capable of storing 8 bits of data.
// b.  	The register file should support reading from and writing to any register.
// c.   	It should have two read ports (read_port_1 and read_port_2) and one write port (write_port_1).
// d.  	The register file should be able to read data from two different registers simultaneously for parallel operations. However, only one kind of operation should be allowed on the register file: either read or write.
// Please note that you should define the module with appropriate input and output ports and ensure that it correctly handles read and write operations
module register_file (
    input wire [2:0] read_port_1,
    input wire [2:0] read_port_2,
    input wire [2:0] write_port_1,
    input wire write_enable,
    input wire [7:0] write_data,
    output wire [7:0] read_data_1,
    output wire [7:0] read_data_2
);

    reg [7:0] registers [0:7];

    always @(posedge clk) begin
        if (write_enable) begin
            registers[write_port_1] <= write_data;
        end
    end

    assign read_data_1 = registers[read_port_1];
    assign read_data_2 = registers[read_port_2];

endmodule