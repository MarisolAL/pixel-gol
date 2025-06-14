#include <katsu/kt.h>
#include "gol.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int size = 12;

u8 live_tile[32] = {0x20, 0x02, 0x20, 0x02,
		    0x32, 0x22, 0x42, 0x44,
		    0x13, 0x23, 0x44, 0x54,
		    0x33, 0x31, 0x44, 0x76,
		    0x32, 0x23, 0x54, 0x77,
		    0x20, 0x42, 0x55, 0x07,
		    0x00, 0x52, 0x76, 0x00,
		    0x00, 0x60, 0x07, 0x00
};

u8 dead_tile[32] = {0x80, 0x08, 0xB0, 0x0B,
		    0x99, 0x89, 0xC8, 0xBB,
		    0x19, 0x88, 0xCC, 0xBC,
		    0xA9, 0x81, 0xDC, 0xDD,
		    0x9A, 0xA9, 0xDC, 0xFD,
		    0xA0, 0xDA, 0xDD, 0x0F,
		    0x00, 0xDD, 0xFF, 0x00,
		    0x00, 0xF0, 0x0F, 0x00
};

u8 color_palette_p[16*4] = {0,0,0, 0,
		      255, 255, 255, 0,
		      219, 95, 105, 0,
		      223, 115, 124, 0,
		      218, 90, 105, 0,
		      217, 81, 99, 0,
		      217, 69, 102, 0,
		      217, 42, 109, 0, //////
		      69, 40, 60, 0,
		      92, 66, 84, 0,
		      97, 83, 102, 0,
		      63, 60, 109, 0,
		      64, 69, 104, 0,
		      71, 92, 68, 0,
		      74, 103, 49, 0
};

void set_sprite(u32 x, u32 y, u32 tile_id, KTSpr *data) {
  data->pos = KT_SPR_POS(x, y);
  data->chr = KT_SPR_CHR(tile_id, KT_FLIP_NONE, KT_SIZE_8, KT_SIZE_8, 0);
}

KTSpr spr[400] = {0}; // WIP fix to use size

int main() {
  srand(time(NULL));
  int board[size][size];

  KTColor back_color = {0, 0, 0, 0}; // WIP Modify
  kt_Init();

  int x = 0;
  int y = 0;
  int state_tile_id = 1;
  int spr_id = 0;
  u32 tile_id = 1;


  kt_TilesetLoad(tile_id, 2, live_tile);
  kt_TilesetLoad(2, 2, dead_tile);
  kt_PaletteLoad(0, 16, color_palette_p);

  populate_board(size, board);

  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      x = i*8 + 2;
      y = j*8 + 2;
      spr_id = i*size + j;
      if (board[i][j]){
	state_tile_id = 1;
      } else {
	state_tile_id = 2;
      }
      set_sprite(x, y, state_tile_id, &spr[spr_id]);
    }
  }


  kt_LayerInitSprite(0, size*size, spr);

  while (1) {
    srand(time(NULL));
    kt_Poll();
    kt_BackColor(back_color);

    for (int i =0; i<size; i++){
      for (int j = 0; j < size; j++){
	x = i*8 + 5;
	y = j*8 + 5;
	spr_id = i*size + j;
	if (board[i][j]){
	  state_tile_id = 1;
	} else {
	  state_tile_id = 2;
	}
	set_sprite(x, y, state_tile_id, &spr[spr_id]);
      }
    }
    iterate_board(size, board, 1);

    //kt_PaletteLoad(0, 16, color_palette_p);

    kt_Draw();
  }


  return 0;
}
