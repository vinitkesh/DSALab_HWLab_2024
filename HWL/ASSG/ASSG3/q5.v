// Design and implement a highly efficient and optimized register file in Verilog for a complex multi-core                  processor's architecture with the following specifications:
// a.   	It should contain 32 register, each capable of storing 64 bits of data.
// b.  	The register file should support simultaneous read and write operations across multiple ports.
// c.   	It should have four read ports (read_port_1, read_port_2, read_port_3 and read_port_4) and two write ports (write_port_1 and write_port_2).
// d.  	The register file should implement a priority-based access mechanism where read and write operations from different ports have different priority levels, and write operations should not interfere with read operations. The smaller the port number, the higher the priority.
// e.   	Each read port should be able to access data from any register simultaneously, without any read conflicts.
// f.        Write operations from different ports should be able to write data to different registers simultaneously, without any write conflicts.
// Please note that you should define the module with appropriate input and output ports and ensure that it correctly handles read and write operations.
module register_file (
    input wire clk,
    input wire reset,

    input wire [4:0] read_port_1,
    input wire [4:0] read_port_2,
    input wire [4:0] read_port_3,
    input wire [4:0] read_port_4,

    input wire [4:0] write_port_1,
    input wire [4:0] write_port_2,
    input wire [63:0] write_data_1,
    input wire [63:0] write_data_2,
    
    output wire [63:0] dataRead_1,
    output wire [63:0] dataRead_2,
    output wire [63:0] dataRead_3,
    output wire [63:0] dataRead_4
);

    reg [63:0] file [31:0];

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < 32; i = i + 1) begin
                file[i] <= 0;
            end
        end else begin
            if (write_port_1 != 0) begin
                file[write_port_1] <= write_data_1;
            end
            if (write_port_2 != 0) begin
                file[write_port_2] <= write_data_2;
            end
        end
    end

    assign data_read_1 = (read_port_1 != 0) ? file[read_port_1] : 0;
    assign data_read_2 = (read_port_2 != 0) ? file[read_port_2] : 0;
    assign data_read_3 = (read_port_3 != 0) ? file[read_port_3] : 0;
    assign data_read_4 = (read_port_4 != 0) ? file[read_port_4] : 0;

endmodule   