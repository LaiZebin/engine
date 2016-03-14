/*
 * AnonymousPipeIPC.h
 *
 *  Created on: 2016Äê3ÔÂ11ÈÕ
 *      Author: Administrator
 */

#ifndef ANONYMOUSPIPEIPC_H_
#define ANONYMOUSPIPEIPC_H_

class AnonymousPipeIPC {
public:
	AnonymousPipeIPC();
	void ipcTest(char *readOrder, char *writeOder);
	virtual ~AnonymousPipeIPC();
};

#endif /* ANONYMOUSPIPEIPC_H_ */
