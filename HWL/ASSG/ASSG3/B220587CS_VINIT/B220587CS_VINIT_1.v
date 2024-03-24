
module Q1 (
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
