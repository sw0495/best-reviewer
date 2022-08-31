#include "TVController.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TVController::TVController(Tuner* tuner)
{
	tuner_ = tuner;
	processingCH_ = "";
    prevCh_ = 0;
    preferChs_count = 0;
	saveChs_count = 0;

    for (int i = 0; i < 100; i++) {
        preferChs_[i] = 0;
	    saveChs_[i] = 0;
    }
}

void TVController::setPrevCh(int prevCH) {
    prevCh_ = prevCH;
}

int TVController::getPrevCh() {
    return prevCh_;
}

void TVController::addPreferChs(int ch) {
    preferChs_[ch] = 1;
    preferChs_count++;
}

bool TVController::checkPreferCh(int ch) {
    if (preferChs_[ch] == 1) {
        return true;
    } 

    return false;
}

bool TVController::isPreferCh() {
    if (preferChs_count > 0) {
        return true;
    } 

    return false;
}


void TVController::addSaveChs(int ch) {
    saveChs_[ch] = 1;
    saveChs_count++;
}

bool TVController::checkSaveCh(int ch) {
    if (saveChs_[ch] == 1) {
        return true;
    } 

    return false;
}

bool TVController::isSaveCh() {
    if (saveChs_count > 0) {
        return true;
    } 

    return false;
}


void TVController::pushButton(remoteKey key)
{
    int currentCh;
    bool findPreferCh;

    switch (key) {
        case remoteKey::KEY_1:
            processingCH_ += to_string(static_cast<int>(key));
            if (processingCH_.size() == 2) {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;
        case remoteKey::KEY_2:
            processingCH_ += to_string(static_cast<int>(key));
            if (processingCH_.size() == 2) {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;               
        case remoteKey::KEY_3:
            processingCH_ += to_string(static_cast<int>(key));
            if (processingCH_.size() == 2) {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;   
        case remoteKey::KEY_4:
            processingCH_ += to_string(static_cast<int>(key));
            if (processingCH_.size() == 2) {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;   
        case remoteKey::KEY_5:
            processingCH_ += to_string(static_cast<int>(key));
            if (processingCH_.size() == 2) {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;   
        case remoteKey::KEY_6:
            processingCH_ += to_string(static_cast<int>(key));
            if (processingCH_.size() == 2) {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;   
        case remoteKey::KEY_7:
            processingCH_ += to_string(static_cast<int>(key));
            if (processingCH_.size() == 2) {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;   
        case remoteKey::KEY_8:
            processingCH_ += to_string(static_cast<int>(key));
            if (processingCH_.size() == 2) {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;   
        case remoteKey::KEY_9:
            processingCH_ += to_string(static_cast<int>(key));
            if (processingCH_.size() == 2) {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;  
        case remoteKey::KEY_0:
            if (processingCH_ == "0") {
                processingCH_ += " pushed";
                setTunerCh();
            }
            else {
                processingCH_ += to_string(static_cast<int>(key));
                if (processingCH_.size() == 2 ) {
                    setPrevCh(tuner_->getCurrentCH());
                    setTunerCh();
                }               
            }            
            break;  
        case remoteKey::KEY_OK:
            if (processingCH_ == "0") {
                processingCH_ += " pushed";
                setTunerCh();
            }
            else {
                setPrevCh(tuner_->getCurrentCH());
                setTunerCh();
            }
            break;                          
        case remoteKey::KEY_UP:
            if (saveChs_count == 0) {
                int currentCh = tuner_->getCurrentCH();
                setPrevCh(currentCh);  
                currentCh = (currentCh + 1) % 100;
                processingCH_ = to_string(currentCh);
                setTunerCh();
            }
            else {
                currentCh = tuner_->getCurrentCH();
                setPrevCh(currentCh); 
                bool findSaveCh = false;
                while(!findSaveCh) { 
                    currentCh = (currentCh + 1) % 100;
                    if (saveChs_[currentCh] == 1) {
                        findSaveCh = true;
                        processingCH_ = to_string(currentCh);
                        setTunerCh();
                    }
                }
            }
            break;
        case remoteKey::KEY_DOWN:
            if (saveChs_count == 0) {
                currentCh = tuner_->getCurrentCH();
                setPrevCh(currentCh);  
                currentCh = (currentCh - 1 + 100) % 100;
                processingCH_ = to_string(currentCh);
                setTunerCh();
            }
            else {
                currentCh = tuner_->getCurrentCH();
                setPrevCh(currentCh); 
                bool findSaveCh = false;
                while(!findSaveCh) { 
                    currentCh = (currentCh - 1 + 100) % 100;
                    if (saveChs_[currentCh] == 1) {
                        findSaveCh = true;
                        processingCH_ = to_string(currentCh);
                        setTunerCh();
                    }
                }
            }
            break;
        case remoteKey::KEY_PREVIOUS:
            if (getPrevCh() != 0) {
                string curCh_ = to_string(getPrevCh());
                setPrevCh(tuner_->getCurrentCH());
                tuner_->setCH(curCh_);
            }
            break;
        case remoteKey::KEY_PREFER: 
            if(preferChs_[tuner_->getCurrentCH()] == 1) {
                preferChs_[tuner_->getCurrentCH()] = 0;
            }
            else {
                addPreferChs(tuner_->getCurrentCH());
            }
            break;
        case remoteKey::KEY_NEXTPREFER:
            currentCh = tuner_->getCurrentCH();
            setPrevCh(currentCh);
            findPreferCh = false;
            while(!findPreferCh) {
                currentCh = (currentCh + 1) % 100;
                if (preferChs_[currentCh] == 1) {
                    findPreferCh = true;
                    tuner_->setCH(to_string(currentCh)); 
                }
            }
            break; 
        case remoteKey::KEY_SEARCH:
            int currentCh = 0;
            bool find = false;   
            while(!find) { 
                string findCh = tuner_->seekCH();
                currentCh = stoi(findCh);
                if (saveChs_[currentCh] == 1) {
                    find = true;
                }
                else {
                    addSaveChs(currentCh);
                }                       
            }
            break;    

    }
}

void TVController::setTunerCh()
{
    //cout<<"현재 설정하는 채널 : "<< processingCH_ << endl;
    tuner_->setCH(processingCH_);    
}
