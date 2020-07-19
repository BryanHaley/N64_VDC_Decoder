#include "VN64_VDC_Decoder.h"

#include "rapidcsv.h"

#include <verilated.h>
#include <allegro5/allegro.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define COL_CLOCK 0
#define COL_DSYNC 1
#define COL_D0    2
#define COL_D1    3
#define COL_D2    4
#define COL_D3    5
#define COL_D4    6
#define COL_D5    7
#define COL_D6    8

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel_t;

bool tb_initialized;
void tb_display_decoded_frame(VN64_VDC_Decoder vdc, rapidcsv::Document csv, int &dIndex);
void tb_skip_to_first_valid_frame(rapidcsv::Document csv, int &dIndex);
void tb_tick_clock(rapidcsv::Document csv, int &dIndex);

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc,argv);

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *queue;

    al_init();

    display = al_create_display(640, 480);
    queue = al_create_event_queue();

    al_install_keyboard();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));

    VN64_VDC_Decoder vdc = new VN64_VDC_Decoder;

    rapidcsv::Document test_data("N64_VDC_Input_Quake_1s.csv");
    int dIndex = 0;

    tb_skip_to_first_valid_frame(test_data, &dIndex);

    bool active = true;
    while (active)
    {
        tb_display_decoded_frame(vdc, test_data, &dIndex);

        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        { active = false; }
    }

    al_destroy_display(display);
    return 0;
}


void tb_display_decoded_frame(VN64_VDC_Decoder vdc, rapidcsv::Document csv, int &dIndex)
{
    //al_draw_pixel(x, y, al_map_rgb(255,255,255));

    while (!(vdc->dsync == 0 && vdc->vsync == 1))
    {
        std::vector<int> data = csv.GetRow<int>(dIndex);
        vdc->vdc_clk = data[COL_CLOCK];
        vdc->vdc_dsync = data[COL_DSYNC];
        vdc->vdc_bus = data[COL_D0]<<6 & data[COL_D1]<<5 & data[COL_D2]<<4 & 
            data[COL_D3]<<3 & data[COL_D4]<<2 & data[COL_D5]<<1 & data[COL_D6];

        vdc->eval();

        al_draw_pixel(vdc->pix_x, vdc->pix_y, al_map_rgb(vdc->pix_r,vdc->pix_g,vdc->pix_b));

        tb_tick_clock(csv, dIndex);
    }
}

void tb_skip_to_first_valid_frame(rapidcsv::Document csv, int &dIndex)
{
    //Find the first cell after dsync == 0 and vdc_bus[3] == 0 (vsync pulse)

    int dsync = -1;
    int vsync = -1;

    while (!(dsync == 0 && vsync == 0))
    {
        std::vector<int> columns = csv.GetRow<int>(dIndex);
        dsync = columns[COL_DSYNC];
        vsync = columns[COL_D3];

        dIndex++;
    }

    while (!(dsync == 0 && vsync == 1))
    {
        std::vector<int> columns = csv.GetRow<int>(dIndex);
        dsync = columns[COL_DSYNC];
        vsync = columns[COL_D3];

        dIndex++;
    }
}

// Find negative edge of clock signal
void tb_tick_clock(rapidcsv::Document csv, int &dIndex)
{
    int clock = -1;

    // Find next positive edge
    while (clock != 1)
    {
        std::vector<int> columns = csv.GetRow<int>(dIndex);
        clock = columns[COL_CLOCK];
        dIndex++;
    }

    // Find next negative edge
    while (clock != 0)
    {
        std::vector<int> columns = csv.GetRow<int>(dIndex);
        clock = columns[COL_CLOCK];
        dIndex++;
    }
}