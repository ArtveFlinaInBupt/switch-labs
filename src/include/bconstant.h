#ifndef _BCONSTANT_H
#define _BCONSTANT_H

// define to nothing for non-windows
#ifndef _MSC_VER
#  define _declspec(_)
#endif

#define LINEMAX      4
#define TIMESLICEMAX 32
#define SchTabLen    20
#define SchTabWdh    3

enum UporOn { ehandup, ehandon };

enum Userstate {
  caller_ehandup,
  caller_calledbusy,
  theother_firstehandon,
  dial_timer_timeout,
  recvnum_timer_timeout,
  connect_timer_timeout,
  nulltone_timer_timeout,
  ringback_timer_timeout,
  busytone_timer_timeout,
  caller_callednull,
  called_onecallin,
  caller_callconnected
};

struct UpOnnode {
  UporOn phonestate;
  int linenum;
  struct UpOnnode *next;
};

struct Digitnode {
  int num;
  int linenum;
  struct Digitnode *next;
};

#endif
