#ifndef _SQLITE3OPT_H
#define _SQLITE3OPT_H
#include <Windows.h>
#include "sqlite3.h"

/************************************************************
Copyright (C), 2018
FileName: SQLite3Opt.h
Author:����Ȼ
Version :1.0
Date:2018-04-06
Description: // ��װ�˶�SQLite3�Ĳ���
***********************************************************/

#ifndef BOOL
typedef int BOOL;
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

//�����ļ�·������
#define FILE_NAME_LENGH 512
//���������Ϣ����
#define ERROR_MESSAGE_LENGTH 1024

class SQLite3Opt{
public:
	/****************************************************************************
	*     FUNCTION: SQLite3Opt
	*     PURPOSE:  ���캯��
	*     PARAMS:   const char* fileName  - ���ݿ��ļ�·��
	\****************************************************************************/
	SQLite3Opt(const char* fileName);
	~SQLite3Opt();
private:
	sqlite3 *m_pdb;
	char m_fileName[FILE_NAME_LENGH];
	char m_strErrmsg[ERROR_MESSAGE_LENGTH];
public:
	/****************************************************************************
	*     FUNCTION: SQLite3CallBackExecuteNonQuery
	*     PURPOSE:  ִ�зǲ�ѯ�Ļص�
	*     PARAMS:
	*     RETURNS:  int - 
	\****************************************************************************/
	static int SQLite3CallBackExecuteNonQuery(void * NotUsed, int argc, char ** argv, char ** szColName);
public:
	/****************************************************************************
	*     FUNCTION: Connect
	*     PURPOSE:  �������ݿ�
	*     PARAMS:
	*     RETURNS:  BOOL - ���ӳɹ�����TRUE������ʧ�ܷ���FALSE
	\****************************************************************************/
	BOOL Connect();

	/****************************************************************************
	*     FUNCTION: GetErrmsg
	*     PURPOSE:  ��ȡ������Ϣ
	*     PARAMS:
	*     RETURNS:  const char* - ���ش�����Ϣ���ַ���
	\****************************************************************************/
	const char* GetErrmsg();

	/****************************************************************************
	*     FUNCTION: ExecuteNonQuery
	*     PURPOSE:  ִ��һ���ǲ�ѯSQL����insert��delete��update
	*     PARAMS:
	*     RETURNS:  int - ����Ӱ������������Ϊ-1����ִ��ʧ��
	\****************************************************************************/
	int ExecuteNonQuery(const char* sql);
private:
	/****************************************************************************
	*     FUNCTION: SetErrmsg
	*     PURPOSE:  ���ô�����Ϣ
	*     PARAMS:   const char* errmsg  -������Ϣ
	*     RETURNS:  BOOL - ���ӳɹ�����TRUE������ʧ�ܷ���FALSE
	\****************************************************************************/
	void SetErrmsg(const char* errmsg);
protected:
	/****************************************************************************
	*     FUNCTION: CallBackExecuteNonQuery
	*     PURPOSE:  ִ��һ���ǲ�ѯSQL���Ļص��麯������insert��delete��update
	*     PARAMS:
	*     RETURNS:  int - ����Ӱ������������Ϊ-1����ִ��ʧ��
	\****************************************************************************/
	virtual int CallBackExecuteNonQuery(int argc, char ** argv, char ** szColName);
};

#endif