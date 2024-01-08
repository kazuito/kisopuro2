/*
 PACMAN
 縺溘□繧ｭ繝｣繝ｩ繧ｯ繧ｿ繝ｼ繧呈桃菴懊☆繧九□縺�
 */

#include <handy.h>
#include <math.h>
#include <stdio.h>

#define WIN_SIZE 400.0  // 繧ｦ繧｣繝ｳ繝峨え縺ｮ螟ｧ縺阪＆
#define PAC_SIZE 10.0   // 繧ｭ繝｣繝ｩ繧ｯ繧ｿ繝ｼ縺ｮ螟ｧ縺阪＆�亥濠蠕�ｼ�
#define PAC_STEP 4.0    // 荳繧ｹ繝�ャ繝励〒騾ｲ繧霍晞屬

int main() {
  double x, y;
  double size;
  double dx, dy;

  HgOpen(WIN_SIZE, WIN_SIZE);

  HgSetEventMask(HG_KEY_DOWN);

  x = WIN_SIZE / 4.0;
  y = WIN_SIZE / 2.0;
  size = PAC_SIZE;
  dx = PAC_STEP;
  dy = 0.0;  // 蜿ｳ縺ｫ遘ｻ蜍�

  while (1) {
    HgClear();  // 逕ｻ髱｢繧呈ｶ亥悉

    hgevent *event = HgEventNonBlocking();
    if (event != NULL &&
        event->type == HG_KEY_DOWN) {
      switch (event->ch) {
        case 'i':
          dx = 0.0;
          dy = PAC_STEP;
          break;  // 荳�
        case 'k':
          dx = 0.0;
          dy = -PAC_STEP;
          break;  // 荳�
        case 'j':
          dx = -PAC_STEP;
          dy = 0.0;
          break;  // 蟾ｦ
        case 'l':
          dx = PAC_STEP;
          dy = 0.0;
          break;  // 蜿ｳ
      }
    }

    x += dx;
    y += dy;  // 遘ｻ蜍�

    // 繧ｭ繝｣繝ｩ繧ｯ繧ｿ繝ｼ繧呈緒縺�
    HgSetColor(HG_RED);  // 襍､濶ｲ縺ｧ霄ｫ菴薙ｒ謠上￥
    HgSetFillColor(HG_RED);
    if (dx < 0.0) {
      HgFanFill(x, y, size, 1.25 * M_PI, 0.75 * M_PI, 0);  // 蟾ｦ蜷代￠縺ｮ蟋ｿ繧呈緒縺�
    } else {
      HgFanFill(x, y, size, 0.25 * M_PI, 3.75 * M_PI, 0);  // 蜿ｳ蜷代￠縺ｮ蟋ｿ繧呈緒縺�
    }
    HgSetFillColor(HG_WHITE);  // 逋ｽ濶ｲ縺ｧ逶ｮ邇峨ｒ謠上￥
    if (dx < 0.0) {
      HgCircleFill(x + size / 3.0, y + size / 2.0, size / 4.0, 0);  // 逶ｮ繧貞ｰ代＠蜿ｳ縺ｫ縺壹ｉ縺励※蜈･繧後ｋ
    } else {
      HgCircleFill(x - size / 3.0, y + size / 2.0, size / 4.0, 0);  // 逶ｮ繧貞ｰ代＠蟾ｦ縺ｫ縺壹ｉ縺励※蜈･繧後ｋ
    }

    // 陦晉ｪ∝愛螳�
    if (((x < size) || (WIN_SIZE - size < x)) ||
        ((y < size) || (WIN_SIZE - size < y))) {  // 螢√↓蠖薙◆縺｣縺�
      HgSetColor(HG_RED);
      HgText(180.0, 120.0, "FAIL");
      break;  // 繧｢繝九Γ繝ｼ繧ｷ繝ｧ繝ｳ繝ｫ繝ｼ繝励ｒ謚懊￠縺ｦ邨ゆｺ�
    }

    HgSleep(0.05);  // 蟆代＠蠕�▽
  }
  // 繝励Ο繧ｰ繝ｩ繝�邨ゆｺ�
  HgSetColor(HG_RED);
  HgText(180.0, 160.0, "END");
  HgGetChar();

  HgClose();
  return 0;
}
