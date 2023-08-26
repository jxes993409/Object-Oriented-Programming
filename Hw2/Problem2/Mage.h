#ifndef _MAGE_H_
#define _MAGE_H_

#include "Role.h"

class Mage: public Role
{
  private:
    int id;
    int magicAttack;
    const char S1[5][Len] =
    {
      " ^_^ ",
      " ( ) ",
      "/-+-/",
      "  |  ",
      " / \\ "
    };
    const char S2[5][Len] =
    {
      " ^_^ ",
      " ( ) ",
      "\\-+-\\",
      "  |  ",
      " / \\ "
    };
    const char LA1[5][Len] =
    {
      " ^_^     ",
      " ( )     ",
      "/-+-----o",
      "  |      ",
      " / \\     "
    };
    const char LA2[5][Len] =
    {
      "     ^_^ ",
      "     ( ) ",
      "o-----+-\\",
      "      |  ",
      "     / \\ "
    };
    const char SA1[5][Len] =
    {
      " ^_^   ",
      " ( )   ",
      "/-+---o",
      "  |    ",
      " / \\   "
    };
    const char SA2[5][Len] =
    {
      "   ^_^ ",
      "   ( ) ",
      "o---+-\\",
      "    |  ",
      "   / \\ "
    };
    const char D1[5][Len] =
    {
      " ^_^  ",
      " ( )  ",
      "/-+--)",
      "  |   ",
      " / \\  "
    };
    const char D2[5][Len] =
    {
      "  ^_^ ",
      "  ( ) ",
      "(--+-\\",
      "   |  ",
      "  / \\ "
    };
  public:
    Mage(int);
    ~Mage();
    int Attack() override;
    int magic_Attack() override;
    void showInfo() override;
    const char* _S(int, int) override;
    const char* _LA(int, int) override;
    const char* _SA(int, int) override;
    const char* _D(int, int) override;
};

#endif