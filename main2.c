#include <katsu/kt.h>
#include <stdio.h>

u8 mi_tile[32] = {0xC1, 0x23, 0x45, 0x67,
		  0x89, 0xAB, 0xCD, 0xEF,
		  0xEE, 0xEE, 0xEE, 0xEE,
		  0x55, 0xE1, 0x48, 0xA2,
		  0xDD, 0xDD, 0xCC, 0xCC,
		  0x9B, 0x9B, 0x75, 0x75,
		  0x68, 0x68, 0x86, 0x86,
		  0xD1, 0xDF, 0x1F, 0xF1
};

u8 mi_paleta[16*4] = {0, 0, 0, 0,
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


KTSpr spr[4] = {0};

int main() {
  KTColor b_color = {0, 0x80, 0, 0};

  if (kt_Init()) {
    return 0;
  }
  u32 x = 5;
  u32 y = 100;

  kt_Init();
  u32 tile_id = 1;

  kt_TilesetLoad(tile_id, 1, mi_tile);
  kt_PaletteLoad(0, 16, mi_paleta);

  spr[0].pos = KT_SPR_POS(x, y);
  spr[0].chr = KT_SPR_CHR(tile_id, KT_FLIP_NONE, KT_SIZE_8, KT_SIZE_8, 0);

  spr[1].pos = KT_SPR_POS(x+100, y+10);
  spr[1].chr = KT_SPR_CHR(tile_id, KT_FLIP_NONE, KT_SIZE_8, KT_SIZE_8, 0);

  spr[2].pos = KT_SPR_POS(x, y+50);
  spr[2].chr = KT_SPR_CHR(tile_id, KT_FLIP_NONE, KT_SIZE_8, KT_SIZE_8, 0);

  set_sprite(x, y+90, tile_id, &spr[3]); // TODO Fix

  //spr[3].pos = KT_SPR_POS(x+34, y-50);
  //spr[3].chr = KT_SPR_CHR(tile_id, KT_FLIP_NONE, KT_SIZE_8, KT_SIZE_8, 0); // Dibuja 4

  kt_LayerInitSprite(0, 4, spr);

  while (1) {
    kt_Poll();

    KTColor bcolor_alt = {0x99, 0x99, 0x99, 0};
    kt_BackColor(bcolor_alt);

    mi_paleta[5] = (mi_paleta[5] + 1) % 255;
    mi_paleta[10] = (mi_paleta[10] + 1) % 255;
    mi_paleta[13] = (mi_paleta[13] + 1) % 255;

    kt_PaletteLoad(0, 16, mi_paleta);

    kt_Draw();
  }
  return 0;
}
