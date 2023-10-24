#ifndef TCP_RDT_SENDER_H
#define TCP_RDT_SENDER_H

#include "DataStructure.h"
#include "RdtSender.h"
#include <deque>

class TCPRdtSender : public RdtSender {
private:
  int nextseqnum;
  std::deque<Packet> window;
  int base;
  int window_len;
  int seq_len;
  int dup_num;

public:
  bool getWaitingState();
  bool send(
      const Message &
          message); // 发送应用层下来的Message，由NetworkServiceSimulator调用,如果发送方成功地将Message发送到网络层，返回true;如果因为发送方处于等待正确确认状态而拒绝发送Message，则返回false
  void
  receive(const Packet &ackPkt); // 接受确认Ack，将被NetworkServiceSimulator调用
  void timeoutHandler(
      int seqNum); // Timeout handler，将被NetworkServiceSimulator调用

public:
  TCPRdtSender();
  virtual ~TCPRdtSender();
};

#endif
