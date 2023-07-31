#ifndef _VM_H_
#define _VM_H_

#include <string>
#include <vector>

typedef struct
{
  int id;
  std::string name;
  int price;
} item;

class VM
{
  public:
    void start();
  private:
    std::vector<item> item_vec;
    std::string password;
    void add_item();
    void remove_item();
    void find_change(item, int, int, int, int);
    void purchase_item();
    void print_itemList();
    void print_optionList();
    std::string set_password();
};

#endif