#pragma once

#include "Disc_quote.h"
#include <string>

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &s, double p, const std::size_t qty, double disc) : Disc_quote(s, p, qty, disc) {}
	Bulk_quote(const Bulk_quote& rhs) : Disc_quote(rhs) {}
	Bulk_quote& operator=(const Bulk_quote& rhs) {
		if (this != &rhs) {
			Disc_quote::operator=(rhs);
		}
		return *this;
	}
	Bulk_quote(Bulk_quote&& rhs) noexcept : Disc_quote(std::move(rhs)) {}
	Bulk_quote& operator=(Bulk_quote&& rhs) noexcept {
		if (this != &rhs) {
			Disc_quote::operator=(std::move(rhs));
		}
		return *this;

	}
	
	~Bulk_quote() = default;
	virtual double net_price(std::size_t n) const override;
	virtual void debug() const {
		Quote::debug();
		std::cout << " min_qyt: " << quantity << " discount: " << discount << std::endl;
	}
};