#include "Bulk_quote.h"
#include "Quote.h"
#include <iostream>
#include <vector>
#include <memory>

double print_total(std::ostream& os, const Quote& item, size_t n);

int main()
{
	std::vector<std::shared_ptr<Quote>> v;
	Bulk_quote bq("yinzishuo", 10.0, 2, 0.2);
	v.push_back(std::make_shared<Bulk_quote>(bq));
	std::cout << v.back()->net_price(5) << std::endl;
	getchar();
	return 0;
}

double print_total(std::ostream& os, const Quote& item, size_t n)
{
	item.debug();
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}