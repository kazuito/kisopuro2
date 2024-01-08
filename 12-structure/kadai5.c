// level 7

#include <handy.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN_SIZE 400.0
#define PAC_SIZE 10.0
#define PAC_STEP 4.0
#define BOX_COUNT 5
#define PENALTY 100

int lid;

typedef struct Pacman {
  double x, y;
  double size;
  double dx, dy;
  int score;
} Pacman;

typedef struct Box {
  double x, y;
  double w, h;
} Box;

void packKeyIn(Pacman *pac) {
  hgevent *event = HgEventNonBlocking();

  int penalty = 0;

  if (event != NULL &&
      event->type == HG_KEY_DOWN) {
    switch (event->ch) {
      case 'i':
        if (pac->dy < 0)
          penalty = PENALTY * 10;
        else if (fabs(pac->dx) > 0)
          penalty = PENALTY;

        pac->dx = 0.0;
        pac->dy = PAC_STEP;
        break;
      case 'k':
        if (pac->dy > 0)
          penalty = PENALTY * 10;
        else if (fabs(pac->dx) > 0)
          penalty = PENALTY;

        pac->dx = 0.0;
        pac->dy = -PAC_STEP;
        break;
      case 'j':
        if (pac->dx > 0)
          penalty = PENALTY * 10;
        else if (fabs(pac->dy) > 0)
          penalty = PENALTY;

        pac->dx = -PAC_STEP;
        pac->dy = 0.0;
        break;
      case 'l':
        if (pac->dx < 0)
          penalty = PENALTY * 10;
        else if (fabs(pac->dy) > 0)
          penalty = PENALTY;

        pac->dx = PAC_STEP;
        pac->dy = 0.0;
        break;
    }
  }

  if (penalty > 0)
    pac->score -= penalty;
  else
    pac->score += 3;
}

void pacMove(Pacman *pac) {
  pac->x += pac->dx;
  pac->y += pac->dy;
}

void pacDraw(Pacman *pac) {
  HgWSetColor(lid, HG_RED);
  HgWSetFillColor(lid, HG_RED);

  if (pac->dx < 0.0) {
    HgWFanFill(lid, pac->x, pac->y, pac->size, 1.25 * M_PI, 0.75 * M_PI, 0);
  } else {
    HgWFanFill(lid, pac->x, pac->y, pac->size, 0.25 * M_PI, 3.75 * M_PI, 0);
  }

  HgWSetFillColor(lid, HG_WHITE);

  if (pac->dx < 0.0) {
    HgWCircleFill(lid, pac->x + pac->size / 3.0, pac->y + pac->size / 2.0, pac->size / 4.0, 0);
  } else {
    HgWCircleFill(lid, pac->x - pac->size / 3.0, pac->y + pac->size / 2.0, pac->size / 4.0, 0);
  }
}

void drawBox(Box *box) {
  HgWSetFillColor(lid, HG_GRAY);
  HgWRectFill(lid, box->x, box->y, box->w / 2, box->h / 2, 0, 0);
}

void drawScore(int score) {
  HgWSetColor(lid, HG_BLACK);
  HgWText(lid, 12, WIN_SIZE - 24, "SCORE: %d", score);
}

void drawFailMessage() {
  HgSetColor(HG_RED);
  HgText( 180.0, 120.0, "FAIL");
}

int hitWall(Pacman *pac) {
  if (((pac->x < pac->size) || (WIN_SIZE - pac->size < pac->x)) ||
      ((pac->y < pac->size) || (WIN_SIZE - pac->size < pac->y))) {
    return 1;
  }

  return 0;
}

int hitBox(Box *box, Pacman *pac) {
  if (PAC_SIZE / 2 + box->w / 2 > fabs(box->x - pac->x) &&
      PAC_SIZE / 2 + box->h / 2 > fabs(box->y - pac->y)) {
    return 1;
  }

  return 0;
}

int randInt(int min, int max) {
  return random() % (max - min + 1) + min;
}

int main() {
  HgOpen(WIN_SIZE, WIN_SIZE);
  HgSetEventMask(HG_KEY_DOWN);

  doubleLayer layers = HgWAddDoubleLayer(0);

  srandom(time(NULL));

  struct Pacman pac = {0, 0, PAC_SIZE, PAC_STEP, 0.0, 0};
  struct Box boxes[BOX_COUNT] = {};

  // pacとboxの初期位置を決める
  while (1) {
    pac.x = randInt(0, 400);
    pac.y = randInt(0, 400);

    if (hitWall(&pac)) {
      continue;
    }

    int boxHit = 0;

    for (int i = 0; i < BOX_COUNT; i++) {
      struct Box box = {0, 0, 0, 0};

      box.w = randInt(20, 100);
      box.h = randInt(20, 100);
      box.x = randInt(0 + box.w / 2, 400 - box.w / 2);
      box.y = randInt(0 + box.h / 2, 400 - box.h / 2);

      boxHit = hitBox(&box, &pac);

      if (boxHit) break;

      boxes[i] = box;
    }

    if (!boxHit) {
      break;
    }
  }

  // メインループ
  while (1) {
    lid = HgLSwitch(&layers);
    HgLClear(lid);

    int hit = 0;

    packKeyIn(&pac);
    pacMove(&pac);

    // pacを描画
    pacDraw(&pac);

    // boxを描画
    for (int i = 0; i < BOX_COUNT; i++) {
      drawBox(&boxes[i]);
    }

    // scoreを描画
    drawScore(pac.score);

    // 壁との当たり判定
    if (hitWall(&pac)) {
      hit++;
    } else {
      // boxとの当たり判定
      for (int i = 0; i < BOX_COUNT; i++) {
        if (hitBox(&boxes[i], &pac)) {
          hit++;
          break;
        }
      }
    }

    if (hit) {
      drawFailMessage();
      break;
    }

    HgSleep(0.05);
  }

  HgSetColor(HG_RED);
  HgText(180.0, 160.0, "END");
  HgGetChar();

  HgClose();
  return 0;
}
