#include <mplsconstant.h>

extern "C" _declspec(dllexport) LabelledDataPack
pack_process(routertype cur_route, libtype cur_entry, int cur_id) {
  LabelledDataPack datapack;

  datapack.iFirstNode = cur_id;
  datapack.iEndNode = cur_route.nexthop;
  datapack.DataInfo.ipaddress = cur_route.ipaddress;
  datapack.DataInfo.labelvalue = cur_entry.outlabel;

  return datapack;
}
