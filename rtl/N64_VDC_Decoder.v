`default_nettype none

module N64_VDC_Decoder (
    input wire      vdc_clk,
    input wire      vdc_dsync,
    input wire[6:0] vdc_bus,

    output reg[9:0] pix_x,
    output reg[9:0] pix_y,
    output reg[7:0] pix_r,
    output reg[7:0] pix_g,
    output reg[7:0] pix_b,

    output wire hsync,
    output wire vsync
    );

    reg[23:0] pix_rgb_buff;
    reg[1:0] dsync_count;

    always @(negedge vdc_clk) begin
        if (vdc_dsync == 0) begin
            { pix_r, pix_g, pix_b } <= pix_rgb_buff;
            pix_x <= pix_x + 1;
            dsync_count <= 0;

            // hsync
            if (vdc_bus[1] == 0) begin
                pix_x <= 0;
                pix_y <= pix_y + 1;
                hsync <= 1;
            end

            // vsync
            if (vdc_bus[3] == 0) begin
                pix_x <= 0;
                pix_y <= 0;
                vsync <= 1;
            end
        end else begin
            case (dsync_count)
                0: pix_rgb_buff <= { vdc_bus, 1'b1, 16'b0 };
                1: pix_rgb_buff <= pix_rgb_buff & { 8'b0, vdc_bus, 1'b1, 8'b0 };
                2: pix_rgb_buff <= pix_rgb_buff & { 16'b0, vdc_bus, 1'b1 };
            endcase

            dsync_count <= dsync_count + 1;
            hsync <= 0;
            vsync <= 0;
        end
    end

endmodule