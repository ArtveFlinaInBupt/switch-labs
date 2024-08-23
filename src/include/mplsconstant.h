#ifndef _MPLSCONSTANT_H
#define _MPLSCONSTANT_H

// define to nothing for non-windows
#ifndef _MSC_VER
#  define _declspec(_)
#endif

#define TOIPADDR 197.42

// 实验一Mpls1InMain的状态
enum mainstatetype1 {
  ready1,
  lspmaking1,
  lspfinished1,
  waitingfordisplaying1,
  datatransmitting1,
  displaydisconnect1
};

// 实验一Mpls1Ler1的状态
enum ler1statetype1 {
  e1_ready1,
  e1_displayreq1,
  e1_waitinglabel1,
  e1_readyfordata1,
  e1_displaypack1,
  e1_datafinished1
};

// 实验一Mpls1Lsr1的状态
enum lsrstatetype1 {
  s_ready1,
  s_displayreq1,
  s_displaylabel1,
  s_waitinglabel1,
  s_readyfordata1,
  s_displaypack1,
  s_datafinished1
};

// 实验一Mpls1Ler2的状态
enum ler2statetype1 {
  e2_ready1,
  e2_displaylabel1,
  e2_readyfordata1,
  e2_displaypack1,
  e2_datafinished1
};

// 实验二Mpls1InMain的状态
enum mainstatetype2 {
  ready2,
  lspmaking2,
  lspfinished2,
  readyfordata2,
  displaypack2,
  datatransmitting2,
  datafinished2
};

// 实验二Mpls1Ler1的状态
enum ler1statetype2 {
  e1_ready2,
  e1_displayreq2,
  e1_waitinglabel2,
  e1_waitinglibanswer2,
  e1_readyfordata2,
  e1_waitingpackanswer2,
  e1_displaypack2,
  e1_datafinished2
};

// 实验二Mpls1Lsr1的状态
enum lsrstatetype2 {
  s_ready2,
  s_displayreq2,
  s_displaylabel2,
  s_waitinglabel2,
  s_waitinglibanswer2,
  s_readyfordata2,
  s_waitingpackanswer2,
  s_displaypack2,
  s_datafinished2
};

// 实验二Mpls1Ler2的状态
enum ler2statetype2 {
  e2_ready2,
  e2_waitinglibanswer2,
  e2_displaylabel2,
  e2_readyfordata2,
  e2_displaypack2,
  e2_datafinished2
};

// 标记分组类型
struct MessageType {
  double ipaddress;
  int labelvalue;
};

// 发送到系统界面的请求信息包类型
struct ReqType {
  int iFirstNode;
  int iEndNode;
  double ipaddress;
};

// 发送到系统界面的网络层分组信息包类型
struct DataPack {
  int iFirstNode;
  int iEndNode;
  double ipaddress;
};

// 发送到系统界面的标记分组信息包类型
struct LabelledDataPack {
  int iFirstNode;
  int iEndNode;
  struct MessageType DataInfo;
};

// 发送到系统界面的标记信息包
struct LabelPack {
  int iFirstNode;
  int iEndNode;
  int labelvalue;
};

// 路由表
struct routertype {
  double ipaddress; // 网络层目的地址前缀
  int nexthop; // 下一跳交换设备，每个交换设备分别用一个整型数表示，具体定义见《MPLS模块与系统平台接口的设计》
  int lasthop;
  int inpoint;  // 入端口号，具体定义见《初步设计》文档
  int outpoint; // 出端口号，具体定义见《初步设计》文档
};

// 标记信息表
struct libtype {
  double ipaddress; // 网络层目的地址前缀
  int inpoint;      // 入端口号
  int outpoint;     // 出端口号
  int inlabel;      // 入标记值
  int outlabel;     // 出标记值
};

struct funcusedtype {
  struct libtype libinfo;
  struct LabelPack labelinfo;
};

#endif
