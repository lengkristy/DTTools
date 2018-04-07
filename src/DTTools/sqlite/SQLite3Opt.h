#ifndef _SQLITE3OPT_H
#define _SQLITE3OPT_H
#include <Windows.h>
#include "sqlite3.h"

/************************************************************
Copyright (C), 2018
FileName: SQLite3Opt.h
Author:代浩然
Version :1.0
Date:2018-04-06
Description: // 封装了对SQLite3的操作
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

//定义文件路径长度
#define FILE_NAME_LENGH 512
//定义错误消息长度
#define ERROR_MESSAGE_LENGTH 1024
//定义结果集的初始长度
#define QUERY_RESULT_INITIAL_LENGTH 1024
//定义结果集的每次增长的长度
#define QEURY_RESULT_GROWTH_SIZE 1024

class SQLite3Opt{
public:
	/****************************************************************************
	*     FUNCTION: SQLite3Opt
	*     PURPOSE:  构造函数
	*     PARAMS:   const char* fileName  - 数据库文件路径
	\****************************************************************************/
	SQLite3Opt(const char* fileName);
	~SQLite3Opt();
private:
	sqlite3 *m_pdb;
	char m_fileName[FILE_NAME_LENGH];//数据库文件名
	char m_strErrmsg[ERROR_MESSAGE_LENGTH];//错误信息
	char* m_pQueryResult;//查询结果集
	long m_lResultLength;//结果集字符串长度
	long m_lResultTotalLength;//结果集总分配长度
public:
	/****************************************************************************
	*     FUNCTION: SQLite3CallBackExecuteNonQuery
	*     PURPOSE:  执行查询的回调，
	*     PARAMS:
	*     RETURNS:  int - 
	\****************************************************************************/
	static int SQLite3CallBack(void * NotUsed, int argc, char ** argv, char ** szColName);
public:
	/****************************************************************************
	*     FUNCTION: Connect
	*     PURPOSE:  连接数据库
	*     PARAMS:
	*     RETURNS:  BOOL - 连接成功返回TRUE，连接失败返回FALSE
	\****************************************************************************/
	BOOL Connect();

	/****************************************************************************
	*     FUNCTION: GetErrmsg
	*     PURPOSE:  获取错误信息
	*     PARAMS:
	*     RETURNS:  const char* - 返回错误信息的字符串
	\****************************************************************************/
	const char* GetErrmsg();

	/****************************************************************************
	*     FUNCTION: ExecuteNonQuery
	*     PURPOSE:  执行一个非查询SQL，如insert、delete、update
	*     PARAMS:
	*     RETURNS:  int - 返回影响的行数，如果为-1则函数执行失败
	\****************************************************************************/
	int ExecuteNonQuery(const char* sql);

	/****************************************************************************
	*     FUNCTION: ExcecuteQuery
	*     PURPOSE:  执行一个查询SQL
	*     PARAMS:
	*     RETURNS:  int - 
	\****************************************************************************/
	int ExcecuteQuery(const char* sql);
private:
	/****************************************************************************
	*     FUNCTION: SetErrmsg
	*     PURPOSE:  设置错误信息
	*     PARAMS:   const char* errmsg  -错误信息
	*     RETURNS:  BOOL - 连接成功返回TRUE，连接失败返回FALSE
	\****************************************************************************/
	void SetErrmsg(const char* errmsg);
protected:
	/****************************************************************************
	*     FUNCTION: CallBackExecuteNonQuery
	*     PURPOSE:  执行查询回调
	*     PARAMS:
	*     RETURNS:  int - 返回影响的行数，如果为-1则函数执行失败
	\****************************************************************************/
	virtual int CallBackQuery(int argc, char ** argv, char ** szColName);
};

#endif