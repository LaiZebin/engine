/*
 * AnonymousPipeIPC.cpp
 *
 *  Created on: 2016��3��11��
 *      Author: Administrator
 */

#include "AnonymousPipeIPC.h"
#include <string.h>
#include <stdio.h>		//BUFSIZE FILE	read_fp
#include <stdlib.h>
#include <unistd.h>		// POSIX.1 ��׼
AnonymousPipeIPC::AnonymousPipeIPC() {
	// TODO Auto-generated constructor stub

}

AnonymousPipeIPC::~AnonymousPipeIPC() {
	// TODO Auto-generated destructor stub
}

void AnonymousPipeIPC::ipcTest(char *readOrder, char *writeOder)
{
	FILE *read_fp = NULL;
	FILE *write_fp = NULL;
	char buffer[BUFSIZ +1];
	int chars_read = 0;

	//��ʼ����ջ�����
	memset(buffer, '\0', sizeof(buffer));
	//��ls��grep����
	read_fp = popen(readOrder, "r");
	write_fp = popen(writeOder, "w");
	//�������̶��򿪳ɹ�
	if(read_fp && write_fp)
	{
		//��ȡһ�����ݿ�
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		while(chars_read > 0)
		{
			buffer[chars_read] = '\0';
			//������д��greap����
			fwrite(buffer, sizeof(char), chars_read, write_fp);
			//�������ݿɶ�
			chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		}
		//�ر��ļ���
		pclose(read_fp);
		pclose(write_fp);
		printf("====Success=====");
		return;
	}
	printf("======Error file not open!======");
	return;
}
