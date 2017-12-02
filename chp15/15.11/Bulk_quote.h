#pragma once

#include "Quote.h"
#include <string>

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &s, double p, const std::size_t qty, double disc) : Quote(s, p), min_qty(qty), discount(disc) {}
	virtual double net_price(std::size_t n) const override;
	virtual void debug() const {
		Quote::debug();
		std::cout << " min_qyt: " << min_qty << " discount: " << discount << std::endl;
	}

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};