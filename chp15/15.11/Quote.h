#pragma once

#include <string>
#include <iostream>

class Quote {
public:
	Quote() = default;
	Quote(const std::string& s, double sales_price) : bookNo(s), price(sales_price) {}
	virtual ~Quote() = default;
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual void debug() const {
		std::cout << "bookNo: " << bookNo << "price: " << price << std::endl;
	}
private:
	std::string bookNo;
protected:
	double price = 0.0;
};


