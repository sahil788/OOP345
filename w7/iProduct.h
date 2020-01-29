#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_
#include <iostream>
#include <fstream>

namespace w7 
{
	class iProduct 
	{
		public:
			virtual double getCharge() const = 0;
			virtual void display(std::ostream&) const = 0;
	};

	class Product : public iProduct
	{
		private:
			int id;
			double price;
		public:
			Product(const int i, const double p);
			double getCharge() const;
			void display(std::ostream&) const;
	};

	class TaxableProduct : public iProduct 
	{
		private:
			int id;
			double price;
			char tax;
		public:
		  TaxableProduct(const int i, const double p, const char t);
		  double getCharge() const;
		  void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readProduct(std::ifstream& is);
}

#endif