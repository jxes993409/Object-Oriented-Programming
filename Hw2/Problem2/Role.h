#ifndef _ROLE_H_
#define _ROLE_H_

#define Len 12

class Role
{
  private:
    int hp;
    int attack;
    int defense;
    int speed;
    bool isDefense;
  public:
    Role();
    Role(int hp, int attack, int defense, int speed);
    virtual ~Role();
    virtual void showInfo();
    virtual int Attack();
    virtual int magic_Attack();
    virtual float hp_Steal();
    int getHp();
    int getAttack();
    int getDefense();
    int getSpeed();
    bool getisDefense();
    void setHp(int);
    void setDefense(int);
    virtual const char* _S(int, int);
    virtual const char* _LA(int, int);
    virtual const char* _SA(int, int);
    virtual const char* _D(int, int);
};

#endif