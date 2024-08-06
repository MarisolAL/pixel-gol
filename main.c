#include <katsu/kt.h>
#include "gol.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int size = 12;

u8 live_tile[32] = {0xC1, 0x23, 0x45, 0x67,
		    0x89, 0xAB, 0xCD, 0xEF,
		    0xEE, 0xEE, 0xEE, 0xEE,
		    0x55, 0xE1, 0x48, 0xA2,
		    0xDD, 0xDD, 0xCC, 0xCC,
		    0x9B, 0x9B, 0x75, 0x75,
		    0x68, 0x68, 0x86, 0x86,
		    0xD1, 0xDF, 0x1F, 0xF1
};

u8 dead_tile[32] = {0x33, 0x33, 0x33, 0x33,
		    0x53, 0x49, 0x94, 0x35,
		    0x53, 0x94, 0x49, 0x35,
		    0x53, 0x49, 0x94, 0x35,
		    0x53, 0x94, 0x94, 0x35,
		    0x63, 0x49, 0x49, 0x35,
		    0x53, 0x94, 0x49, 0x35,
		    0x33, 0x33, 0x33, 0x33
};

u8 color_palette_p[16*4] = {0, 0, 0, 0,
		      206, 243, 68, 0,
		      50, 36, 77, 0,
		      243, 237, 204, 0,
		      100, 31, 114, 0,
		      187, 1, 112, 0,
		      38, 28, 107, 0,
		      208, 55, 108, 0,
		      43, 26, 123, 0,
		      82, 24, 53, 0,
		      198, 36, 15, 0,
		      77, 21, 24, 0,
		      32, 143, 202, 0,
		      164, 142, 48, 0,
		      216, 91, 30, 0,
		      240, 206, 33, 0
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
