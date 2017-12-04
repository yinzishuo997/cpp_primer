#pragma once

#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include <vector>
#include <memory>
#include <iostream>
#include <set>

class Basket {
public:
	void add_item(const Quote& sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
	void add_item(Quote&& sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) {
		return lhs->isbn() < rhs->isbn();
	}
private:
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};