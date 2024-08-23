#include <bconstant.h>
#include <stdlib.h>
#include <string.h>

extern "C" _declspec(dllexport) void scanfor200(
    int line_state_200ms_ago[LINEMAX], int line_state[LINEMAX], UpOnnode *head,
    UpOnnode *end
) {
  for (int i = 0; i < LINEMAX; ++i) {
    if (line_state[i] != line_state_200ms_ago[i]) {
      UpOnnode *cur = new UpOnnode;

      cur->phonestate = line_state[i] ? ehandup : ehandon;
      cur->linenum = i;
      cur->next = NULL;

      end->next = cur;
      end = cur;
    }
  }

  memcpy(line_state_200ms_ago, line_state, sizeof(int) * LINEMAX);
}

// 此函数不需修改
extern "C" _declspec(dllexport) void freenode(UpOnnode *node) {
  delete node;
}
