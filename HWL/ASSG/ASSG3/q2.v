//     Design and implement a register in Verilog for a custom processor's architecture with the following specifications:
// a.   	It should be a 16-bit register.
// b.  	It should have one read port (read_port_1) and two write port (write_port_1 and write_port_2).
// c.   	Only one operation, either read or write, can be performed at a time on the register. 
//      However, write operations can be performed from write ports alternatively, i.e., if a previous
//       write is done using write_port_1, then the next write will be done using write_port_2, and vice versa.
// d.  	Each read port should be able to access data from the register without any conflicts with write operations.
// Please note that you should define the module with appropriate input and output ports and ensure that it meets 
// `all the specified requirements above.

    
   module custom_register (
    input [15:0] write_address_1, //input writing into 1
    input [15:0] write_address_2, // input writing into 2
    input read_enable,
    input write_enable,

    output reg [15:0] data_out
);

reg [15:0] reg_file;
reg choice = -1;

always @(posedge write_enable or read_enable) begin
    if(read_enable) begin
        data_out <= reg_file;
    end 
    else if(write_enable) begin
        if(choice == -1) begin
            reg_file <= write_address_1;
            choice <= 1;
        end 
        else if(choice == 0) begin
            reg_file <= write_address_1;
        end 
        else begin
            reg_file <= write_address_2;
        end
        
    end

    data_out <= reg_file;
end

endmodule

