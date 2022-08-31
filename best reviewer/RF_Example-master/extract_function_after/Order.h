#ifndef _ORDER_H_
#define _ORDER_H_

class Order {
public:
    
    Order(double amount);

    double getAmount();

private:
    int m_amount = 0;
    
};

#endif
