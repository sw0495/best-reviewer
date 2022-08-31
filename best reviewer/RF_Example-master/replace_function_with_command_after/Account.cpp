#include "Account.h"

int Account::gamma(int inputVal, int quantity, int yearToDate) {
    return Gamma(inputVal, quantity, yearToDate).execute();    
}

int Gamma::execute() {
    
    //int importantValue1 = (m_inputVal * m_quantity) + delta();
    //int importantValue2 = (m_inputVal * m_yearToDate) + 100;

    importantValue1 = (m_inputVal * m_quantity) + delta();
    importantValue2 = (m_inputVal * m_yearToDate) + 100;
    
    doImportantThing();
    
    //int importantValue3 = importantValue2 * 7;
    importantValue3 = importantValue2 * 7;
    //and so on

    return importantValue3  - 2*importantValue1;
}

int Gamma::delta() {
    return 20;
}

void Gamma::doImportantThing() {
    if((m_yearToDate - importantValue1) > 100){
        importantValue2 -= 20;
    }
}

