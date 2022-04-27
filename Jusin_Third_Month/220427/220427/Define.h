#pragma once

#define WINCX 800
#define WINCY 600

#define OUTGAMESIZE 25
#define GAMESIZE 50

#define LEGSIZE 40.f

#define PURE =0

#define PI 3.1415926535f
#define DEGREE (PI / 180.f)
#define nLog sqrtf(2.f)

#define Diagonal(x,y) sqrtf((x * x) + (y * y))

#define ACOSF(x,y) acosf(x / sqrtf((x * x) + (y * y)))
#define ASINF(x,y) asinf(y / sqrtf((x * x) + (y * y)))