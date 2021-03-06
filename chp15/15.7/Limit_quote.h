#pragma once

#include "Quote.h"

class Limit_quote : public Quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string &s, double p, const std::size_t n, double disc) : Quote(s, p), max_qty(n), discount(disc) {}
	virtual double net_price(std::size_t n) const override;

private:
	std::size_t max_qty;
	double discount = 0.0;
};