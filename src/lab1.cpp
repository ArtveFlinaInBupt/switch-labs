#include <bconstant.h>

extern "C" _declspec(dllexport) void
initSchTable(int ScheduleTable[SchTabLen][SchTabWdh]) {
  static const int SLOC = 10;
  static const int TIME[] = {200, 10, 100};

  for (int i = 0; i < SchTabLen; ++i)
    for (int j = 0; j < SchTabWdh; ++j)
      ScheduleTable[i][j] = (i % (TIME[j] / SLOC) == 0);
}
