#ifndef _ELECTRONICS_H_
#define _ELECTRONICS_H_

using namespace std;

class Electronics
{
  private:
    int length;
    int width;
    bool usage;
    bool charging;
  public:
    Electronics(int length, int width);
    virtual ~Electronics();
    bool get_usage();
    void set_usage(bool flag);
    bool get_charging();
    void set_charging(bool flag);
    virtual void charge();
    virtual void poweron();
    void poweroff();
    virtual void run();
};

#endif