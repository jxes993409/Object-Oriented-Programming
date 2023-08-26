#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "Role.h"

class Vampire: public Role
{
  private:
    int id;
    float lifeSteal;
    float hpSteal;
    const char S1[5][Len] =
    {
      "  _  ",
      " (v) ",
      "/-+-/",
      "  |  ",
      " / \\ "
    };
    const char S2[5][Len] =
    {
      "  _  ",
      " (v) ",
      "\\-+-\\",
      "  |  ",
      " / \\ "
    };
    const char LA1[5][Len] =
    {
      "  _      ",
      " (v)     ",
      "/-+-----o",
      "  |      ",
      " / \\     "
    };
    const char LA2[5][Len] =
    {
      "      _  ",
      "     (v) ",
      "o-----+-\\",
      "      |  ",
      "     / \\ "
    };
    const char SA1[5][Len] =
    {
      "  _    ",
      " (v)   ",
      "/-+---o",
      "  |    ",
      " / \\   "
    };
    const char SA2[5][Len] =
    {
      "    _  ",
      "   (v) ",
      "o---+-\\",
      "    |  ",
      "   / \\ "
    };
    const char D1[5][Len] =
    {
      "  _   ",
      " (v)  ",
      "/-+--)",
      "  |   ",
      " / \\  "
    };
    const char D2[5][Len] =
    {
      "   _  ",
      "  (v) ",
      "(--+-\\",
      "   |  ",
      "  / \\ "
    };
  public:
    Vampire(int);
    ~Vampire();
    int Attack() override;
    float hp_Steal() override;
    void showInfo() override;
    const char* _S(int, int) override;
    const char* _LA(int, int) override;
    const char* _SA(int, int) override;
    const char* _D(int, int) override;
};

#endif