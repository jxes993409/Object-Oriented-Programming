#include <iostream>
#include "Stock.h"

const double Stock::init_price = 57.88;
const double Stock::limit_ratio = 0.1;
double Stock::cur_price = init_price;
bool Stock::trade_available = false;

Stock::Stock(): owner_name("")
{
	ticket_num = 0;
	avg_buy_price = 0.0;
}

Stock::Stock(string name): owner_name(name)
{
	ticket_num = 0;
	avg_buy_price = 0.0;
}

Stock::Stock(string name, int n1): owner_name(name)
{
	ticket_num = n1;
	avg_buy_price = cur_price;
}

void Stock::operator +(const Stock& buy_stock)
{
	this->avg_buy_price = (this->avg_buy_price * this->ticket_num + buy_stock.cur_price * buy_stock.ticket_num) / (this->ticket_num + buy_stock.ticket_num);
	this->ticket_num += buy_stock.ticket_num;
}

void Stock::operator -(const Stock& sell_stock)
{
	cout << this->ticket_num << " " << sell_stock.ticket_num << endl;
	cout << this->avg_buy_price << " " << sell_stock.avg_buy_price << endl;
	this->avg_buy_price = (this->avg_buy_price * this->ticket_num - sell_stock.cur_price * sell_stock.ticket_num) / (this->ticket_num - sell_stock.ticket_num);
	this->ticket_num -= sell_stock.ticket_num;
}

void Stock::buy()
{
	if (trade_available)
	{
		int buy_ticket_num;
		cout << "How many tickets do you want to buy: ";
		cin >> buy_ticket_num;
		Stock buy_stock(owner_name, buy_ticket_num);
		this->operator +(buy_stock);
	}
	else
	{
		cout << "The trade is not available today." << endl;
	}
}

void Stock::sell()
{
	if (trade_available)
	{
		int sell_ticket_num;
		cout << "How many tickets do you want to sell: ";
		cin >> sell_ticket_num;
		Stock sell_stock(owner_name, sell_ticket_num);
		if (this->ticket_num >= sell_ticket_num) {this->operator -(sell_stock);}
	}
	else
	{
		cout << "The trade is not available today." << endl;
	}
}

void Stock::show_stock()
{
	cout << owner_name << ", you have " << ticket_num << " stocks and the average price is " << avg_buy_price << endl;
}

string Stock::get_owner_name() const
{
	return owner_name;
}

void Stock::show_current_price()
{
	cout << "------------------------------------------" << endl;
	cout << "current price of the stock: " << cur_price << endl;
}

void Stock::check_trade_is_available()
{
	if (abs(cur_price - init_price) / cur_price <= limit_ratio)
	{
		trade_available = true;
	}
	else
	{
		trade_available = false;
		cout << "trade is not available anymore" << endl;
	}
}

void Stock::refresh_current_price()
{
	cur_price = cur_price + (rand() % 500 / 100) - 2.5;
	show_current_price();
}