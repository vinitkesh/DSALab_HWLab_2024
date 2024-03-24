
module Q3 #(parameter DATA_WIDTH = 8) (
    input wire clk,
    input wire reset,
    input wire read_enable,
    input wire write_enable,
    input wire [DATA_WIDTH-1:0] write_port_1,
    output wire [DATA_WIDTH-1:0] read_port_1
);

    reg [DATA_WIDTH-1:0] reg_data;

    always @(posedge clk or posedge reset) begin
        if (reset)
            reg_data <= 0;
        else if (write_enable) //if write is enabled
            reg_data <= write_port_1; 
    end

    assign read_port_1 = read_enable ? reg_data : 0; //if read is enabled

endmodule
