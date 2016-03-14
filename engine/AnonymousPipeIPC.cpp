/*
 * AnonymousPipeIPC.cpp
 *
 *  Created on: 2016年3月11日
 *      Author: Administrator
 */

#include "AnonymousPipeIPC.h"
#include <string.h>
#include <stdio.h>		//BUFSIZE FILE	read_fp
#include <stdlib.h>
#include <unistd.h>		// POSIX.1 标准
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

	//初始化清空缓冲区
	memset(buffer, '\0', sizeof(buffer));
	//打开ls和grep进程
	read_fp = popen(readOrder, "r");
	write_fp = popen(writeOder, "w");
	//两个进程都打开成功
	if(read_fp && write_fp)
	{
		//读取一个数据块
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		while(chars_read > 0)
		{
			buffer[chars_read] = '\0';
			//把数据写入greap进程
			fwrite(buffer, sizeof(char), chars_read, write_fp);
			//还有数据可读
			chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		}
		//关闭文件流
		pclose(read_fp);
		pclose(write_fp);
		printf("====Success=====");
		return;
	}
	printf("======Error file not open!======");
	return;
}
