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
	//初始化结果集长度
	m_pQueryResult = (CHAR*)malloc(QUERY_RESULT_INITIAL_LENGTH);
	if (!m_pQueryResult)
	{
		this->SetErrmsg("malloc query result falied");
	}
	m_lResultLength = 0;
	m_lResultTotalLength = QUERY_RESULT_INITIAL_LENGTH;
	memset(this->m_pQueryResult, 0, this->m_lResultTotalLength);
}

SQLite3Opt::~SQLite3Opt()
{
	if (this->m_pdb != NULL)
	{
		sqlite3_close(this->m_pdb);
	}
	//释放内存
	if (m_pQueryResult != NULL){
		free(m_pQueryResult);
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
	if (errmsg == NULL)
		return;
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
	return sqlite3_exec(this->m_pdb, sql, NULL, this, &errmsg);
}

/****************************************************************************
*     FUNCTION: ExcecuteQuery
*     PURPOSE:  执行一个查询SQL
*     PARAMS:
*     RETURNS:  int -
\****************************************************************************/
int SQLite3Opt::ExcecuteQuery(const char* sql)
{
	char* errmsg = NULL;
	m_lResultLength = 0;
	//清空结果集
	memset(this->m_pQueryResult, 0, this->m_lResultTotalLength);
	//准备结果集JSON
	strcat(this->m_pQueryResult, "{");
	this->m_lResultLength++;//结果集长度加1
	int result = sqlite3_exec(this->m_pdb, sql, &SQLite3Opt::SQLite3CallBack, this, &errmsg);
	this->SetErrmsg(errmsg);
	//去掉最后一个逗号
	this->m_pQueryResult[this->m_lResultLength - 1] = '}';
	return result;
}

/****************************************************************************
*     FUNCTION: SQLite3CallBackExecuteNonQuery
*     PURPOSE:  执行查询的回调，
*     PARAMS:
*     RETURNS:  int -
\****************************************************************************/
int SQLite3Opt::SQLite3CallBack(void * NotUsed, int argc, char ** argv, char ** szColName)
{
	SQLite3Opt* pSqlLiteOpt = static_cast<SQLite3Opt*>(NotUsed);
	if (pSqlLiteOpt != NULL)
	{
		//回调子类函数
		return pSqlLiteOpt->CallBackQuery(argc, argv, szColName);
	}
	return 0;
}

/****************************************************************************
*     FUNCTION: CallBackExecuteNonQuery
*     PURPOSE:  执行查询回调
*     PARAMS:
*     RETURNS:  int - 返回影响的行数，如果为-1则函数执行失败
\****************************************************************************/
int SQLite3Opt::CallBackQuery(int argc, char ** argv, char ** szColName)
{
	char tmpStr[QEURY_RESULT_GROWTH_SIZE] = { 0 };//保证每次分配的长度能够装下
	strcat(tmpStr, "{");
	for (int i = 0; i<argc; i++){
		strcat(tmpStr, "\"");
		strcat(tmpStr, szColName[i]);
		strcat(tmpStr, "\":");
		strcat(tmpStr, "\"");
		strcat(tmpStr, argv[i]);
		strcat(tmpStr, "\",");
	}
	//计算字符串长度
	int length = 0;
	while (tmpStr[length] != '\0')
		length++;
	tmpStr[length - 1] = '}';
	strcat(tmpStr, ",");
	length++;
	//判断结果集是否能够存下
	if (length >= this->m_lResultTotalLength - this->m_lResultLength)
	{
		//重新分配内存
		char* pOld = this->m_pQueryResult;
		this->m_lResultTotalLength = this->m_lResultTotalLength + QEURY_RESULT_GROWTH_SIZE;
		this->m_pQueryResult = (char*)malloc(this->m_lResultTotalLength);
		if (this->m_pQueryResult == NULL)
		{
			this->SetErrmsg("保存结果集时，分配内存失败");
			free(pOld);
			return -1;
		}
		memset(this->m_pQueryResult, 0, this->m_lResultTotalLength);
		strcpy(this->m_pQueryResult, pOld);
		//释放以前的内存
		free(pOld);
	}
	//开始保存结果集
	strcat(this->m_pQueryResult, tmpStr);
	this->m_lResultLength += length;
	return 0;
}