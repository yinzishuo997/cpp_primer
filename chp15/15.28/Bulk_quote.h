#pragma once

#include "Disc_quote.h"
#include <string>

class Bulk_quote : public Disc_quote {
	using Disc_quote::Disc_quote;
public:
	Bulk_quote() = default;
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