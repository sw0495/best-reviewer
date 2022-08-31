#ifndef PAYMENTHISTORY_H
#define PAYMENTHISTORY_H

class PaymentHistory {
public:
    int getWeeksDelinquentInLastYear();
    void setWeeksDelinquentInLastYear(int);
    
private:
    int m_weeksDelinquentInLastYear;
};

inline int PaymentHistory::getWeeksDelinquentInLastYear() {
    return m_weeksDelinquentInLastYear;
}

inline void PaymentHistory::setWeeksDelinquentInLastYear(int weeksDelinquentInLastYear) {
    m_weeksDelinquentInLastYear = weeksDelinquentInLastYear;
}

#endif