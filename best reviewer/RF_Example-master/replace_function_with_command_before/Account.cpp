#include "Account.h"

int Account::gamma(int inputVal, int quantity, int yearToDate) {
    int importantValue1 = (inputVal * quantity) +delta();
    int importantValue2 = (inputVal * yearToDate) + 100;

    //doImportantThing
    if((yearToDate - importantValue1) > 100){
        importantValue2 -= 20;
    }

    int importantValue3 = importantValue2 * 7;
    //and so on

    return importantValue3  - 2*importantValue1;
}

int Account::delta() {
    return 20;
}

