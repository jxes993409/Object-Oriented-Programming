#ifndef _WARRIOR_H_
#define _WARRIOR_H_

#include "Role.h"

class Warrior: public Role
{
  private:
    int id;
    float critRate;
    const char S1[5][Len] =
    {
      "  _  ",
      " ( ) ",
      "/-+-/",
      " [|] ",
      " / \\ "
    };
    const char S2[5][Len] =
    {
      "  _  ",
      " ( ) ",
      "\\-+-\\",
      " [|] ",
      " / \\ "
    };
    const char LA1[5][Len] =
    {
      "  _      ",
      " ( )     ",
      "/-+-----0",
      " [|]     ",
      " / \\     "
    };
    const char LA2[5][Len] =
    {
      "      _  ",
      "     ( ) ",
      "0-----+-\\",
      "     [|] ",
      "     / \\ "
    };
    const char SA1[5][Len] =
    {
      "  _    ",
      " ( )   ",
      "/-+---0",
      " [|]   ",
      " / \\   "
    };
    const char SA2[5][Len] =
    {
      "    _  ",
      "   ( ) ",
      "0---+-\\",
      "   [|] ",
      "   / \\ "
    };
    const char D1[5][Len] =
    {
      "  _   ",
      " ( )  ",
      "/-+--)",
      " [|]  ",
      " / \\  "
    };
    const char D2[5][Len] =
    {
      "   _  ",
      "  ( ) ",
      "(--+-\\",
      "  [|] ",
      "  / \\ "
    };
  public:
    Warrior(int);
    ~Warrior();
    int Attack() override;
    void showInfo() override;
    const char* _S(int, int) override;
    const char* _LA(int, int) override;
    const char* _SA(int, int) override;
    const char* _D(int, int) override;
};

#endif