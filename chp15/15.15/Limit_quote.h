#pragma once

#include "Disc_quote.h"

class Limit_quote : public Disc_quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string& s, double p, std::size_t n, double disc) : Disc_quote(s, p, n, disc) {}
	virtual double net_price(std::size_t n) const override;
	virtual void debug() const override;

};