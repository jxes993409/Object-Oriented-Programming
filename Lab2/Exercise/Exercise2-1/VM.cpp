#include <iostream>
#include <algorithm>
#include "VM.h"

bool sorted_byID(item x, item y)
{
  return (x.id < y.id);
}

void VM::start()
{
  password = VM::set_password();
  print_optionList();
}

void VM::add_item()
{
  item item_temp;
  std::cout << "Please enter the information of the item." << std::endl;
  std::cout << "ID: ";
  std::cin >> item_temp.id;
  std::cout << "Name: ";
  std::cin >> item_temp.name;
  std::cout << "Price: ";
  std::cin >> item_temp.price;
  item_vec.push_back(item_temp);
}

void VM::remove_item()
{
  bool flag = false;
  std::string input_item;
  std::cout << "The name of the item you want to remove: ";
  std::cin >> input_item;
  std::vector<item>::iterator iter;
  for (iter = item_vec.begin(); iter != item_vec.end(); iter++)
  {
    auto n = *iter;
    if(n.name == input_item)
    {
      flag = true;
      break;
    }
  }
  if (flag)
  {
    item_vec.erase(iter);
  }
  else
  {
    std::cout << "No item found!" << std::endl;
  }
}

void VM::find_change(item i, int one, int five, int ten, int fifty)
{
  int total = fifty * 50 + ten * 10 + five * 5 + one * 1;
  int change = total - i.price;
  int change_fifty, change_ten, change_five, change_one;
  // 50
  change_fifty = change / 50;
  change %= 50;
  // 10
  change_ten = change / 10;
  change %= 10;
  // 5
  change_five = change / 5;
  change %= 5;
  // 1
  change_one = change;
  if (change_one || change_five || change_ten || change_fifty)
  {
    std::cout << "Your change" << std::endl;
    std::cout << "One dollar: " << change_one << std::endl;
    std::cout << "Five dollar: " << change_five << std::endl;
    std::cout << "Ten dollar: " << change_ten << std::endl;
    std::cout << "Fifty dollar: " << change_fifty << std::endl;
  }
  else
  {
    std::cout << "No change should be given." << std::endl;
  }
  std::cout << "Thank you for your purchase!" << std::endl;
}

void VM::purchase_item()
{
  std::cout << "Welcome! Here is the item list." << std::endl;
  print_itemList();
  std::cout << "Which item do you want to buy?" << std::endl;
  std::string input_item;
  std::cin >> input_item;
  bool flag = false;
  std::vector<item>::iterator iter;
  for (iter = item_vec.begin(); iter != item_vec.end(); iter++)
  {
    auto n = *iter;
    if(n.name == input_item)
    {
      flag = true;
      break;
    }
  }
  if (flag)
  {
    auto n = *iter;
    int one, five, ten, fifty;
    std::cout << "The price is " << n.price << " dollars" << std::endl;
    std::cout << "Please insert coins." << std::endl;
    std::cout << "One dollar: ";
    std::cin >> one;
    std::cout << "Five dollar: ";
    std::cin >> five;
    std::cout << "Ten dollar: ";
    std::cin >> ten;
    std::cout << "Fifty dollar: ";
    std::cin >> fifty;
    find_change(n, one, five, ten, fifty);
    item_vec.erase(iter);
  }
  else
  {
    std::cout << "Out of stock!" << std::endl;
  }
}

void VM::print_itemList()
{
  if (item_vec.empty())
  {
    std::cout << "There is no item right now!!!" << std::endl;
  }
  else
  {
    std::sort(item_vec.begin(), item_vec.end(), sorted_byID);
    std::cout << "ID\tName\tPrice" << std::endl;
    for (auto i: item_vec)
    {
      std::cout << i.id << "\t" << i.name << "\t" << i.price << std::endl;
    }
  }
}

void VM::print_optionList()
{
  int input_option;
  std::string input_password;
  std::cout << "Enter 1 for owner mode, 2 for customer mode: ";
  while (std::cin >> input_option)
  {
    switch (input_option)
    {
    case 1: // owner_mode
      enter_password:
      std::cout << "Please enter your password: ";
      std::cin >> input_password;
      if(input_password != password)
      {
        int password_option;
        std::cout << "Wrong password!" << std::endl;
        std::cout << "Enter 1 for type again, 2 for going back to last step: ";
        std::cin >> password_option;
        switch (password_option)
        {
        case 1: // type again
          goto enter_password;
          break;

        case 2: // go to last step
          goto option;
          break;
        default:
          std::cout << "Invalid input!" << std::endl;
          break;
        }
      }

      int owner_option;
      std::cout << "Welcome to owner mode!" << std::endl;
      std::cout << "1. Add item" << std::endl;
      std::cout << "2. Remove item" << std::endl;
      std::cout << "3. Print item list" << std::endl;
      std::cin >> owner_option;
      switch (owner_option)
      {
      case 1:
        add_item();
        break;

      case 2:
        remove_item();
        break;

      case 3:
        print_itemList();
        break;

      default:
        std::cout << "Invalid input!" << std::endl;
        break;
      }
      break;

    case 2: // costumer_mode
      if(item_vec.empty())
      {
        std::cout << "Sorry! There is no item right now." << std::endl;
      }
      else
      {
        purchase_item();
      }
      break;

    default:
      std::cout << "Invalid input!" << std::endl;
      break;
    }
    option:
    std::cout << "Enter 1 for owner mode, 2 for customer mode: ";
  }
}

std::string VM::set_password()
{
  std::string check_password;
  std::string input_password;
  while (true)
  {
    std::cout << "Enter a password for your vending machine: ";
    std::cin >> input_password;
    std::cout << "Enter your password again: ";
    std::cin >> check_password;
    if (input_password != check_password)
    {
      std::cout << "It's different from the first password! Please set the password again!" << std::endl;
    }
    else
    {
      break;
    }
  }
  return input_password;
}