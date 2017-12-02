#pragma once

#include "Quote.h"

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& s, double p, std::size_t qty, double disc) : Quote(s, p), quantity(qty), discount(disc) {}
	virtual double net_price(std::size_t n) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};