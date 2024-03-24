
    
   module Q2(
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

