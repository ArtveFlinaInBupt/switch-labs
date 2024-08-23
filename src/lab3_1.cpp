#include <mplsconstant.h>

extern "C" _declspec(dllexport) ReqType
req_process(int cur_id, routertype cur_route) {
  struct ReqType request;

  request.iFirstNode = cur_id;
  request.iEndNode = cur_route.nexthop;
  request.ipaddress = cur_route.ipaddress;

  return request;
}
