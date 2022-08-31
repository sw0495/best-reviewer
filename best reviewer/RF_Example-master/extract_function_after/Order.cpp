#include "Order.h"

Order::Order(double amount)
	: m_amount(amount)
{
}


double Order::getAmount()
{
    return m_amount;
}
