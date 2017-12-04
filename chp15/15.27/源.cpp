#include "Bulk_quote.h"
#include "Quote.h"
#include <iostream>

double print_total(std::ostream& os, const Quote& item, size_t n);

int main()
{
	Quote q("aaa", 10.60);
	Quote q2(q);
	Quote q3;
	q3 = q2;
	Quote q4(std::move(q3));
	Quote q5;
	q5 = std::move(q4);
	
	Bulk_quote bq("bbb", 111, 10, 0.3);
	Bulk_quote bq2(bq);
	Bulk_quote bq3;
	bq3 = bq2;
	Bulk_quote bq4(std::move(bq3));
	Bulk_quote bq5;
	bq5 = std::move(bq4);

	print_total(std::cout, q5, 10);
	print_total(std::cout, bq5, 15);
	
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