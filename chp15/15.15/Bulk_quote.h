#pragma once

#include "Disc_quote.h"
#include <string>

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &s, double p, const std::size_t qty, double disc) : Disc_quote(s, p, qty, disc) {}
	virtual double net_price(std::size_t n) const override;
	virtual void debug() const {
		Quote::debug();
		std::cout << " min_qyt: " << quantity << " discount: " << discount << std::endl;
	}
};