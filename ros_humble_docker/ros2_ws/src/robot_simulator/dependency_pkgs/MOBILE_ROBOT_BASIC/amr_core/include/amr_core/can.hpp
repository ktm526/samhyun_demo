#include <linux/can.h>      
#include <linux/can/raw.h>
#include <sys/socket.h>    
#include <net/if.h>      
#include <sys/ioctl.h>
#include <thread>
#include <boost/thread/thread.hpp> 

class CAN_{
public:
    CAN_();
    ~CAN_();
private:
    void Init();
    bool sendCan(int id, char* data);
    void receiveCanMessages();

    boost::thread can_receive_thread_;
    int can_socket_;
    bool running_;
};