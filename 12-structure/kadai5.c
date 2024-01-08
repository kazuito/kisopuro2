// level 7

#include <handy.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN_SIZE 400.0
#define PAC_SIZE 20.0
#define PAC_STEP 4.0
#define BOX_COUNT 30
#define PENALTY 100

int lid, lid2;

typedef struct Rect {
  double x, y;
  double w, h;
} Rect;

typedef struct Pacman {
  Rect rect;
  double dx, dy;
  int score;
} Pacman;

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
  pac->rect.x += pac->dx;
  pac->rect.y += pac->dy;
}

void pacDraw(Pacman *pac) {
  HgWSetColor(lid, HG_RED);
  HgWSetFillColor(lid, HG_YELLOW);

  if (pac->dx < 0.0) {
    HgWFanFill(lid, pac->rect.x + pac->rect.w / 2, pac->rect.y + pac->rect.h / 2, pac->rect.w / 2, 1.25 * M_PI, 0.75 * M_PI, 0);
  } else {
    HgWFanFill(lid, pac->rect.x + pac->rect.w / 2, pac->rect.y + pac->rect.h / 2, pac->rect.w / 2, 0.25 * M_PI, 3.75 * M_PI, 0);
  }

  HgWSetFillColor(lid, HG_BLACK);

  if (pac->dx < 0.0) {
    HgWCircleFill(lid, pac->rect.x + pac->rect.w / 2 / 3.0, pac->rect.y + pac->rect.w / 2 / 2.0, pac->rect.w / 2 / 4.0, 0);
  } else {
    HgWCircleFill(lid, pac->rect.x - pac->rect.w / 2 / 3.0, pac->rect.y + pac->rect.w / 2 / 2.0, pac->rect.w / 2 / 4.0, 0);
  }
}

void drawBox(Rect *box) {
  HgWSetFillColor(lid, HG_BLUE);
  HgWBoxFill(lid, box->x, box->y, box->w, box->h, 0);
}

void drawBall(Rect *ball) {
  HgWSetFillColor(lid, HG_YELLOW);
  HgWCircleFill(lid, ball->x + ball->w / 2, ball->y + ball->h / 2, ball->w / 2, 0);
}

void drawScore(int score) {
  if (score < 0)
    HgWSetColor(lid, HG_RED);
  else
    HgWSetColor(lid, HG_WHITE);

  HgWText(lid, 12, WIN_SIZE - 24, "SCORE: %d", score);
}

void drawFailMessage() {
  HgWSetColor(lid2, HG_WHITE);
  HgWSetFont(lid2, HG_GB, 24.0);
  HgWText(lid2, 130.0, 220.0, "GAME OVER");
}

int hitWall(Rect *rect) {
  if (((rect->x < rect->w) || (WIN_SIZE - rect->w < rect->x)) ||
      ((rect->y < rect->h) || (WIN_SIZE - rect->h < rect->y))) {
    return 1;
  }

  return 0;
}

int rectHit(Rect *r1, Rect *r2) {
  double r1cx = r1->x + r1->w / 2.0;
  double r1cy = r1->y + r1->h / 2.0;
  double r2cx = r2->x + r2->w / 2.0;
  double r2cy = r2->y + r2->h / 2.0;

  double distanceX = fabs(r1cx - r2cx);
  double distanceY = fabs(r1cy - r2cy);

  if (distanceX < (r1->w + r2->w) / 2.0 &&
      distanceY < (r1->h + r2->h) / 2.0) {
    return 1;
  }

  return 0;
}

int randInt(int min, int max) {
  return random() % (max - min + 1) + min;
}

Rect generateBall(Rect boxes[BOX_COUNT]) {
  Rect ball = {0, 0, 0, 0};

  while (1) {
    int collision = 0;

    ball.w = PAC_SIZE;
    ball.h = PAC_SIZE;
    ball.x = randInt(0, (int)(WIN_SIZE / PAC_SIZE)) * PAC_SIZE;
    ball.y = randInt(0, (int)(WIN_SIZE / PAC_SIZE)) * PAC_SIZE;

    if (hitWall(&ball)) {
      continue;
    }

    for (int i = 0; i < BOX_COUNT; i++) {
      if (rectHit(&ball, &boxes[i])) {
        collision = 1;
        break;
      }
    }

    if (!collision) {
      break;
    }
  }

  return ball;
}

int main() {
  HgOpen(WIN_SIZE, WIN_SIZE);
  HgSetEventMask(HG_KEY_DOWN);
  HgWSetFillColor(0, HG_BLACK);
  HgWBoxFill(0, 0, 0, WIN_SIZE, WIN_SIZE, 0);

  doubleLayer layers = HgWAddDoubleLayer(0);
  lid2 = HgWAddLayer(0);

  srandom(time(NULL));

  struct Pacman pac = {{0, 0, PAC_SIZE, PAC_SIZE}, PAC_STEP, 0.0, 0};
  struct Rect boxes[BOX_COUNT] = {};

  while (1) {
    // pacとboxの初期位置を決める
    while (1) {
      pac.rect.x = randInt(0, 400);
      pac.rect.y = randInt(0, 400);

      if (hitWall(&pac.rect)) {
        continue;
      }

      int boxHit = 0;

      for (int i = 0; i < BOX_COUNT; i++) {
        struct Rect box = {0, 0, 0, 0};

        box.w = randInt(1, 2) * PAC_SIZE;
        box.h = randInt(1, 2) * PAC_SIZE;
        box.x = randInt(0, (int)(WIN_SIZE / PAC_SIZE)) * PAC_SIZE;
        box.y = randInt(0, (int)(WIN_SIZE / PAC_SIZE)) * PAC_SIZE;

        boxHit = rectHit(&box, &pac.rect);

        if (boxHit) break;

        boxes[i] = box;
      }

      if (!boxHit) {
        break;
      }
    }

    struct Rect ball = generateBall(boxes);

    int frameCount = 0;

    // メインループ
    while (1) {
      lid = HgLSwitch(&layers);

      HgLClear(lid);
      HgLClear(lid2);

      int hit = 0;

      packKeyIn(&pac);
      pacMove(&pac);

      // pacを描画
      pacDraw(&pac);

      // boxを描画
      for (int i = 0; i < BOX_COUNT; i++) {
        drawBox(&boxes[i]);
      }

      // ballを描画
      drawBall(&ball);
      // drawBox(&ball);

      // scoreを描画
      drawScore(pac.score);

      if (frameCount == 1) {
        HgWSetFont(lid2, HG_GB, 12.0);
        HgWSetColor(lid2, HG_WHITE);
        HgWText(lid2, 127.0, 200.0, "TYPE ANY KEY TO START");
        HgGetChar();
      }

      // 壁との当たり判定
      if (hitWall(&pac.rect)) {
        hit++;
      } else {
        // boxとの当たり判定
        for (int i = 0; i < BOX_COUNT; i++) {
          if (rectHit(&boxes[i], &pac.rect)) {
            hit++;
            break;
          }
        }
      }

      // ballとの当たり判定
      if (rectHit(&ball, &pac.rect)) {
        pac.score += 1000;
        ball = generateBall(boxes);
      }

      if (hit) {
        drawFailMessage();
        break;
      }

      HgSleep(0.05);
      frameCount++;
    }

    HgWSetColor(lid2, HG_WHITE);
    HgWSetFont(lid2, HG_GB, 12.0);
    HgWText(lid2, 127.0, 180.0, "TYPE ANY KEY TO RETRY");
    HgSleep(0.5);
    HgEvent();
  }

  HgClose();
  return 0;
}
