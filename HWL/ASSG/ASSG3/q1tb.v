module Register_tb;

    reg clk;
    reg reset;
    reg read_enable;
    reg write_enable;
    reg [15:0] write_data;
    wire [15:0] read_data;

    Register dut (
        .clk(clk),
        .reset(reset),
        .read_enable(read_enable),
        .write_enable(write_enable),
        .write_data(write_data),
        .read_data(read_data)
    );

    initial begin
        clk = 0;
        reset = 1;
        read_enable = 0;
        write_enable = 0;
        write_data = 16'b0;

        #10 reset = 0; // Deassert reset

        // Write operation
        write_enable = 1;
        write_data = 16'b1010101010101010;
        #20 write_enable = 0;

        // Read operation
        read_enable = 1;
        #10 read_enable = 0;

        // Add more test cases here if needed

        $finish;
    end

    always #5 clk = ~clk;

endmodule