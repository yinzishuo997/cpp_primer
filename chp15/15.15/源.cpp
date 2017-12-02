#include "Bulk_quote.h"
#include "Limit_quote.h"
#include "Quote.h"
#include <iostream>

double print_total(std::ostream& os, const Quote& item, size_t n);

int main()
{
	Quote q("aaa", 10.60);
	Bulk_quote bq("bbb", 111, 10, 0.3);
	Limit_quote lq("ccc", 222, 10, 0.3);

	print_total(std::cout, q, 10);
	print_total(std::cout, bq, 15);
	print_total(std::cout, lq, 15);
	
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