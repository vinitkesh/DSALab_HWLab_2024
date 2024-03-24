
module Q4 (
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
