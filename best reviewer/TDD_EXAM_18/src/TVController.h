#ifndef TVCONTROLLER_H_
#define TVCONTROLLER_H_

#include "RemoteKey.h"
#include "Tuner.h"
using namespace std;

class TVController
{
public:
	TVController(Tuner* tuner);
	void pushButton(remoteKey key);
	void setPrevCh(int ch);
	int getPrevCh();
    void addPreferChs(int ch);
	bool checkPreferCh(int ch);
	bool isPreferCh();
	void addSaveChs(int ch);
	bool checkSaveCh(int ch);
	bool isSaveCh();

private:
	void setTunerCh();
	Tuner* tuner_;
	std::string processingCH_;
	int prevCh_;
	int preferChs_[100];
	int preferChs_count;
	int saveChs_[100];
	int saveChs_count;

};

#endif
