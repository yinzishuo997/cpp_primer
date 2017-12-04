#pragma once

#include "Quote.h"

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& s, double p, std::size_t qty, double disc) : Quote(s, p), quantity(qty), discount(disc) {}
	Disc_quote(const Disc_quote& rhs) : Quote(rhs), quantity(rhs.quantity), discount(rhs.discount) {}
	Disc_quote& operator=(const Disc_quote& rhs) {
		if (this != &rhs) {
			Quote::operator=(rhs);
			quantity = rhs.quantity;
			discount = rhs.discount;
		}
		return *this;
	}
	Disc_quote(Disc_quote&& rhs) noexcept : Quote(std::move(rhs)), quantity(std::move(rhs.quantity)), discount(std::move(rhs.discount)) {}
	Disc_quote& operator=(Disc_quote&& rhs) noexcept {
		if (this != &rhs) {
			Quote::operator=(std::move(rhs));
			quantity = std::move(rhs.quantity);
			discount = std::move(rhs.discount);
		}
		return *this;
	}
	virtual double net_price(std::size_t n) const = 0;
	~Disc_quote() = default;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};