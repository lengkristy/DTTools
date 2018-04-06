#include "SQLite3Opt.h"

/****************************************************************************
*     FUNCTION: SQLite3Opt
*     PURPOSE:  构造函数
*     PARAMS:   const char* fileName  - 数据库文件路径
\****************************************************************************/
SQLite3Opt::SQLite3Opt(const char* fileName)
{
	this->m_pdb = NULL;
	memset(m_strErrmsg, 0, ERROR_MESSAGE_LENGTH);
	if (fileName != NULL)
	{
		memcpy(m_fileName, fileName, FILE_NAME_LENGH);
	}
}

SQLite3Opt::~SQLite3Opt()
{
	if (this->m_pdb != NULL)
	{
		sqlite3_close(this->m_pdb);
	}
}


/****************************************************************************
*     FUNCTION: Connect
*     PURPOSE:  连接数据库
*     PARAMS:   
*     RETURNS:  BOOL - 连接成功返回TRUE，连接失败返回FALSE
\****************************************************************************/
BOOL SQLite3Opt::Connect()
{
	if (SQLITE_OK != sqlite3_open_v2(this->m_fileName, &this->m_pdb, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
	{
		this->SetErrmsg(sqlite3_errmsg(this->m_pdb));
		return FALSE;
	}
	return TRUE;
}


/****************************************************************************
*     FUNCTION: SetErrmsg
*     PURPOSE:  设置错误信息
*     PARAMS:   const char* errmsg  -错误信息
*     RETURNS:  BOOL - 连接成功返回TRUE，连接失败返回FALSE
\****************************************************************************/
void SQLite3Opt::SetErrmsg(const char* errmsg)
{
	memset(this->m_strErrmsg, 0, ERROR_MESSAGE_LENGTH);
	memcpy(this->m_strErrmsg, errmsg, ERROR_MESSAGE_LENGTH);
}

/****************************************************************************
*     FUNCTION: GetErrmsg
*     PURPOSE:  获取错误信息
*     PARAMS:
*     RETURNS:  const char* - 返回错误信息的字符串
\****************************************************************************/
const char* SQLite3Opt::GetErrmsg()
{
	return this->m_strErrmsg;
}

/****************************************************************************
*     FUNCTION: ExecuteNonQuery
*     PURPOSE:  执行一个非查询SQL，如insert、delete、update
*     PARAMS:
*     RETURNS:  int - 返回影响的行数，如果为-1则函数执行失败
\****************************************************************************/
int SQLite3Opt::ExecuteNonQuery(const char* sql)
{
	char* errmsg = NULL;
	return sqlite3_exec(this->m_pdb, sql, &SQLite3Opt::SQLite3CallBackExecuteNonQuery, this, &errmsg);
}

/****************************************************************************
*     FUNCTION: SQLite3CallBackExecuteNonQuery
*     PURPOSE:  执行非查询的回调
*     PARAMS:
*     RETURNS:  int -
\****************************************************************************/
int SQLite3Opt::SQLite3CallBackExecuteNonQuery(void * NotUsed, int argc, char ** argv, char ** szColName)
{
	SQLite3Opt* pSqlLiteOpt = static_cast<SQLite3Opt*>(NotUsed);
	if (pSqlLiteOpt != NULL)
	{
		//回调子类函数
		pSqlLiteOpt->CallBackExecuteNonQuery(argc, argv, szColName);
	}
	return 0;
}

/****************************************************************************
*     FUNCTION: CallBackExecuteNonQuery
*     PURPOSE:  执行一个非查询SQL，的回调虚函数，如insert、delete、update
*     PARAMS:
*     RETURNS:  int - 返回影响的行数，如果为-1则函数执行失败
\****************************************************************************/
int SQLite3Opt::CallBackExecuteNonQuery(int argc, char ** argv, char ** szColName)
{
	return 0;
}