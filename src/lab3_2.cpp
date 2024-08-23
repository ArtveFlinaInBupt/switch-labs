#include <mplsconstant.h>

static const int CUSTOM_LABEL_IN = 5;

extern "C" _declspec(dllexport) funcusedtype
label_process(routertype cur_route, int label_out, int cur_id) {
  funcusedtype info;

  info.libinfo.ipaddress = cur_route.ipaddress;
  info.libinfo.inpoint = cur_route.inpoint;
  info.libinfo.outpoint = cur_route.outpoint;
  info.libinfo.inlabel = CUSTOM_LABEL_IN;
  info.libinfo.outlabel = label_out;

  info.labelinfo.iFirstNode = cur_id;
  info.labelinfo.iEndNode = cur_route.lasthop;
  info.labelinfo.labelvalue = CUSTOM_LABEL_IN;

  return info;
}
