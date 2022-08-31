#include <gtest/gtest.h>
#include "RPNCalculator.h"
#include <stack>
#include <cmath>
#include <algorithm>

int RPNCalculator::calculator(vector<string> stringForCalculate) {
    int num1, num2;
    int stringSize = stringForCalculate.size();
    stack<int> st;

    for(int i = 0; i < stringSize; i++) {

        if(stringForCalculate[i] == "+")
        {
            num2 = st.top();
            st.pop();

            num1 = st.top();
            st.pop();

            st.push(num1 + num2);
        }
        else if(stringForCalculate[i] == "-")
        {
            num2 = st.top();
            st.pop();

            num1 = st.top();
            st.pop();

            st.push(num1 - num2);
        }
        else if(stringForCalculate[i] == "*")
        {
            num2 = st.top();
            st.pop();

            num1 = st.top();
            st.pop();

            st.push(num1 * num2);
        }
        else if(stringForCalculate[i] == "/")
        {
            num2 = st.top();
            st.pop();

            num1 = st.top();
            st.pop();

            string deviedTestByZeroException = "deviedTestByZeroException";   
            if (num1 == 0 || num2 == 0) {
                throw deviedTestByZeroException;
            }

            st.push(num1 / num2);
        }
        else if(stringForCalculate[i] == "SQRT")
        {
            num1 = st.top();
            st.pop();

            st.push(sqrt(num1));
        }
        else if(stringForCalculate[i] == "MAX")
        {
            vector<int> maxCheck;

            while(st.empty())
            {
                maxCheck.push_back(st.top());
                st.pop();
            }    
            num1 = *max_element(maxCheck.begin(), maxCheck.end());

            st.push(sqrt(num1));
        }
        else
        {
            int pushNum = stoi(stringForCalculate[i]);
            st.push(pushNum);
        }
    }   
    
    return st.top();

} 