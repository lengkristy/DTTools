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
	//��ʼ�����������
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
	//�ͷ��ڴ�
	if (m_pQueryResult != NULL){
		free(m_pQueryResult);
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
	if (errmsg == NULL)
		return;
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
	return sqlite3_exec(this->m_pdb, sql, NULL, this, &errmsg);
}

/****************************************************************************
*     FUNCTION: ExcecuteQuery
*     PURPOSE:  ִ��һ����ѯSQL
*     PARAMS:
*     RETURNS:  int -
\****************************************************************************/
int SQLite3Opt::ExcecuteQuery(const char* sql)
{
	char* errmsg = NULL;
	m_lResultLength = 0;
	//��ս����
	memset(this->m_pQueryResult, 0, this->m_lResultTotalLength);
	//׼�������JSON
	strcat(this->m_pQueryResult, "{");
	this->m_lResultLength++;//��������ȼ�1
	int result = sqlite3_exec(this->m_pdb, sql, &SQLite3Opt::SQLite3CallBack, this, &errmsg);
	this->SetErrmsg(errmsg);
	//ȥ�����һ������
	this->m_pQueryResult[this->m_lResultLength - 1] = '}';
	return result;
}

/****************************************************************************
*     FUNCTION: SQLite3CallBackExecuteNonQuery
*     PURPOSE:  ִ�в�ѯ�Ļص���
*     PARAMS:
*     RETURNS:  int -
\****************************************************************************/
int SQLite3Opt::SQLite3CallBack(void * NotUsed, int argc, char ** argv, char ** szColName)
{
	SQLite3Opt* pSqlLiteOpt = static_cast<SQLite3Opt*>(NotUsed);
	if (pSqlLiteOpt != NULL)
	{
		//�ص����ຯ��
		return pSqlLiteOpt->CallBackQuery(argc, argv, szColName);
	}
	return 0;
}

/****************************************************************************
*     FUNCTION: CallBackExecuteNonQuery
*     PURPOSE:  ִ�в�ѯ�ص�
*     PARAMS:
*     RETURNS:  int - ����Ӱ������������Ϊ-1����ִ��ʧ��
\****************************************************************************/
int SQLite3Opt::CallBackQuery(int argc, char ** argv, char ** szColName)
{
	char tmpStr[QEURY_RESULT_GROWTH_SIZE] = { 0 };//��֤ÿ�η���ĳ����ܹ�װ��
	strcat(tmpStr, "{");
	for (int i = 0; i<argc; i++){
		strcat(tmpStr, "\"");
		strcat(tmpStr, szColName[i]);
		strcat(tmpStr, "\":");
		strcat(tmpStr, "\"");
		strcat(tmpStr, argv[i]);
		strcat(tmpStr, "\",");
	}
	//�����ַ�������
	int length = 0;
	while (tmpStr[length] != '\0')
		length++;
	tmpStr[length - 1] = '}';
	strcat(tmpStr, ",");
	length++;
	//�жϽ�����Ƿ��ܹ�����
	if (length >= this->m_lResultTotalLength - this->m_lResultLength)
	{
		//���·����ڴ�
		char* pOld = this->m_pQueryResult;
		this->m_lResultTotalLength = this->m_lResultTotalLength + QEURY_RESULT_GROWTH_SIZE;
		this->m_pQueryResult = (char*)malloc(this->m_lResultTotalLength);
		if (this->m_pQueryResult == NULL)
		{
			this->SetErrmsg("��������ʱ�������ڴ�ʧ��");
			free(pOld);
			return -1;
		}
		memset(this->m_pQueryResult, 0, this->m_lResultTotalLength);
		strcpy(this->m_pQueryResult, pOld);
		//�ͷ���ǰ���ڴ�
		free(pOld);
	}
	//��ʼ��������
	strcat(this->m_pQueryResult, tmpStr);
	this->m_lResultLength += length;
	return 0;
}