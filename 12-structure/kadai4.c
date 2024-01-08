#include <handy.h>
#include <math.h>
#include <stdio.h>

#define WIN_SIZE 400.0
#define PAC_SIZE 10.0
#define PAC_STEP 4.0

typedef struct Pacman {
  double x, y;
  double size;
  double dx, dy;
} Pacman;

Pacman packKeyIn(Pacman pac) {
  hgevent *event = HgEventNonBlocking();

  if (event != NULL &&
      event->type == HG_KEY_DOWN) {
    switch (event->ch) {
      case 'i':
        pac.dx = 0.0;
        pac.dy = PAC_STEP;
        break;
      case 'k':
        pac.dx = 0.0;
        pac.dy = -PAC_STEP;
        break;
      case 'j':
        pac.dx = -PAC_STEP;
        pac.dy = 0.0;
        break;
      case 'l':
        pac.dx = PAC_STEP;
        pac.dy = 0.0;
        break;
    }
  }

  return pac;
}

Pacman pacMove(Pacman pac) {
  pac.x += pac.dx;
  pac.y += pac.dy;

  return pac;
}

void pacDraw(Pacman pac) {
  HgSetColor(HG_RED);
  HgSetFillColor(HG_RED);

  if (pac.dx < 0.0) {
    HgFanFill(pac.x, pac.y, pac.size, 1.25 * M_PI, 0.75 * M_PI, 0);
  } else {
    HgFanFill(pac.x, pac.y, pac.size, 0.25 * M_PI, 3.75 * M_PI, 0);
  }

  HgSetFillColor(HG_WHITE);

  if (pac.dx < 0.0) {
    HgCircleFill(pac.x + pac.size / 3.0, pac.y + pac.size / 2.0, pac.size / 4.0, 0);
  } else {
    HgCircleFill(pac.x - pac.size / 3.0, pac.y + pac.size / 2.0, pac.size / 4.0, 0);
  }
}

int hitWall(Pacman pac) {
  if (((pac.x < pac.size) || (WIN_SIZE - pac.size < pac.x)) ||
      ((pac.y < pac.size) || (WIN_SIZE - pac.size < pac.y))) {
    HgSetColor(HG_RED);
    HgText(180.0, 120.0, "FAIL");

    return 1;
  } else {
    return 0;
  }
}

int main() {
  HgOpen(WIN_SIZE, WIN_SIZE);
  HgSetEventMask(HG_KEY_DOWN);

  struct Pacman pac = {WIN_SIZE / 4.0, WIN_SIZE / 2.0, PAC_SIZE, PAC_STEP, 0.0};

  while (1) {
    HgClear();

    pac = packKeyIn(pac);
    pac = pacMove(pac);
    pacDraw(pac);

    if (hitWall(pac) == 1) break;

    HgSleep(0.05);
  }

  HgSetColor(HG_RED);
  HgText(180.0, 160.0, "END");
  HgGetChar();

  HgClose();

  return 0;
}
