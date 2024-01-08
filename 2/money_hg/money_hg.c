#include <handy.h>
#include <stdio.h>

#define WIN_W 800
#define WIN_H 640

int main() {
  int amount, original_amount;
  int coin_count = 6;
  int coins[] = {500, 100, 50, 10, 5, 1};
  int coin_nums[coin_count];
  int total_coin_nums = 0;

  scanf("%d", &amount);

  original_amount = amount;

  for (int i = 0; i < coin_count; i++) {
    coin_nums[i] = amount / coins[i];
    total_coin_nums += coin_nums[i];
    amount %= coins[i];
  }

  for (int i = 0; i < coin_count; i++) {
    printf("%d:%d", coins[i], coin_nums[i]);

    if (i < coin_count - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }

  HgOpen(WIN_W, WIN_H);

  int images[] = {
      HgImageLoad("img/coin_500.png"),
      HgImageLoad("img/coin_100.png"),
      HgImageLoad("img/coin_50.png"),
      HgImageLoad("img/coin_10.png"),
      HgImageLoad("img/coin_5.png"),
      HgImageLoad("img/coin_1.png")};

  hgsound register_sound = HgSoundLoad("SE/register.mp3");

  long double gap_500 = 20;
  long double x;

  do {
    x = 130 - (gap_500 / 2) * (coin_nums[0] / 20);
    gap_500 -= 0.001;
  } while (x < 64);

  HgSetFillColor(0x161617UL);
  HgBoxFill(0, 0, WIN_W, WIN_H, 0);
  HgSleep(0.5);

  for (int i = 0; i < coin_count; i++) {
    int y = 100;
    long double local_x = x;

    for (int j = 0; j < coin_nums[i]; j++) {
      if (j % 20 == 0) {
        local_x += gap_500;
        y = 100;
      }

      HgImagePut(local_x, y, images[i], 0.2, 0);
      y += 24;

      HgSleep(2.0 / total_coin_nums);
    }

    if (i == 0) {
      x += gap_500 * (coin_nums[0] / 20) + 8;
    } else if (i == 4) {
      x -= 10;
    }
    x += 106;
  }

  double text_w, text_h;
  HgSetFont(HG_GB, 40);
  HgSetColor(HG_WHITE);
  HgTextSize(&text_w, &text_h, "¥%d", original_amount);
  HgText((WIN_W - text_w) / 2, 340, "¥%d", original_amount);
  HgSoundPlay(register_sound);

  HgGetChar();
  HgClose();
  return 0;
}
