// OrderManager.cpp

#include <algorithm> 
#include "Item.h"
#include "CustomerOrder.h"
#include "ItemManager.h"
#include "OrderManager.h"

void OrderManager::push_back(CustomerOrder&& customerOrder)
{
    customerOrders.push_back(std::move(customerOrder));
}

CustomerOrder&& OrderManager::extract() 
{
	return std::move(*customerOrders.end());
}

void OrderManager::pop() 
{
	customerOrders.pop_back();
}

bool OrderManager::empty() const 
{
	return customerOrders.empty();
}

std::vector<CustomerOrder>::iterator OrderManager::begin() 
{
    return customerOrders.begin();
}

std::vector<CustomerOrder>::iterator OrderManager::end()
{
    return customerOrders.end();
}

const std::vector<CustomerOrder>::const_iterator OrderManager::cbegin() const
{
    return customerOrders.cbegin();
}

const std::vector<CustomerOrder>::const_iterator OrderManager::cend() const 
{
    return customerOrders.cend();
}

void OrderManager::display(std::ostream& os) const 
{
  for (size_t s = 0; s < customerOrders.size(); s++) 
  {
    customerOrders[s].display(os);
  }
}

void validate(const OrderManager& orderManager, const ItemManager& itemManager, std::ostream& os) 
{
    for (auto itm = orderManager.cbegin(); itm != orderManager.cend(); itm++) 
	{
        const auto& customerOrder = *itm;
        for (int i = 0; i < customerOrder.noOrders(); i++) 
		{
            auto available = [&] (const Item& item) 
			{
                return !item.getName().compare(customerOrder[i]);
            };

            if (std::find_if (itemManager.cbegin(), itemManager.cend(), available) == itemManager.cend()) 
			{
                os << customerOrder[i] << " is unavailable" << std::endl;
            }
        }
    }
}