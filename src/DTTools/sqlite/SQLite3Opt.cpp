#include "SQLite3Opt.h"

/****************************************************************************
*     FUNCTION: SQLite3Opt
*     PURPOSE:  ���캯��
*     PARAMS:   const char* fileName  - ���ݿ��ļ�·��
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
*     PURPOSE:  �������ݿ�
*     PARAMS:   
*     RETURNS:  BOOL - ���ӳɹ�����TRUE������ʧ�ܷ���FALSE
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
*     PURPOSE:  ���ô�����Ϣ
*     PARAMS:   const char* errmsg  -������Ϣ
*     RETURNS:  BOOL - ���ӳɹ�����TRUE������ʧ�ܷ���FALSE
\****************************************************************************/
void SQLite3Opt::SetErrmsg(const char* errmsg)
{
	memset(this->m_strErrmsg, 0, ERROR_MESSAGE_LENGTH);
	memcpy(this->m_strErrmsg, errmsg, ERROR_MESSAGE_LENGTH);
}

/****************************************************************************
*     FUNCTION: GetErrmsg
*     PURPOSE:  ��ȡ������Ϣ
*     PARAMS:
*     RETURNS:  const char* - ���ش�����Ϣ���ַ���
\****************************************************************************/
const char* SQLite3Opt::GetErrmsg()
{
	return this->m_strErrmsg;
}

/****************************************************************************
*     FUNCTION: ExecuteNonQuery
*     PURPOSE:  ִ��һ���ǲ�ѯSQL����insert��delete��update
*     PARAMS:
*     RETURNS:  int - ����Ӱ������������Ϊ-1����ִ��ʧ��
\****************************************************************************/
int SQLite3Opt::ExecuteNonQuery(const char* sql)
{
	char* errmsg = NULL;
	return sqlite3_exec(this->m_pdb, sql, &SQLite3Opt::SQLite3CallBackExecuteNonQuery, this, &errmsg);
}

/****************************************************************************
*     FUNCTION: SQLite3CallBackExecuteNonQuery
*     PURPOSE:  ִ�зǲ�ѯ�Ļص�
*     PARAMS:
*     RETURNS:  int -
\****************************************************************************/
int SQLite3Opt::SQLite3CallBackExecuteNonQuery(void * NotUsed, int argc, char ** argv, char ** szColName)
{
	SQLite3Opt* pSqlLiteOpt = static_cast<SQLite3Opt*>(NotUsed);
	if (pSqlLiteOpt != NULL)
	{
		//�ص����ຯ��
		pSqlLiteOpt->CallBackExecuteNonQuery(argc, argv, szColName);
	}
	return 0;
}

/****************************************************************************
*     FUNCTION: CallBackExecuteNonQuery
*     PURPOSE:  ִ��һ���ǲ�ѯSQL���Ļص��麯������insert��delete��update
*     PARAMS:
*     RETURNS:  int - ����Ӱ������������Ϊ-1����ִ��ʧ��
\****************************************************************************/
int SQLite3Opt::CallBackExecuteNonQuery(int argc, char ** argv, char ** szColName)
{
	return 0;
}