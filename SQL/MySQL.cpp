#include <mysql.h>
#include <iostream>

int main()
{
	MYSQL Conn;				// MySQL ������ ���� ����ü
	MYSQL* ConnPtr = NULL;	// MySQL �ڵ�
	MYSQL_RES* Result;		// ���������� ����� ��� ����ü ������
	MYSQL_ROW Row;			// ���������� ����� ���� ���� ������ ��� ����ü
	int Stat;				// ������û �� ���(����, ����)

	mysql_init(&Conn);		// MySQL ���� �ʱ�ȭ

	// �����ͺ��̽��� ����
	ConnPtr = mysql_real_connect(&Conn, "�����ͺ��̽������ּ�", "root", "��й�ȣ", "�����ҵ����ͺ��̽�", 3306, (char*)NULL, 0);

	if (ConnPtr == NULL)	// ���� ��� Ȯ��, NULL�� ��� ���� ������ ��
	{
		fprintf(stderr, "MySQL connection error : %s\n", mysql_error(&Conn));
		return 1;
	}

	// �����ͺ��̽��� �ѱ��� �ִٸ� �Ʒ� 3�� �߰�
	// MySQL���� ����ϴ� ���ڼ��� VS�� ����ϴ� ���ڼ��� euc-kr�� �������ִ� ���
	mysql_query(ConnPtr, "set session character_set_connection=euckr;");
	mysql_query(ConnPtr, "set session character_set_results=euckr;");
	mysql_query(ConnPtr, "set session character_set_client=euckr;");

	char* Query = (char*)"SELECT * FROM people";	// �����ݷ��� ������ ������ �ۼ�
	Stat = mysql_query(ConnPtr, Query);				// ���� ��û �� �������� �޾ƿ���
	if (Stat != 0)
	{
		fprintf(stderr, "MySQL query error : %s\n", mysql_error(&Conn));
		return 1;
	}

	Result = mysql_store_result(ConnPtr);			// ��� Ȯ���ϱ�
	while ((Row = mysql_fetch_row(Result)) != NULL)	// ��� ����ϱ�
	{
		std::cout << Row[0] << ' ' << Row[1] << ' ' << Row[2] << ' ' << Row[3] << ' ' << Row[4] <<  '\n';
	}
	mysql_free_result(Result);						// ��� ����

	// �����ͺ��̽��� ��������
	mysql_close(ConnPtr);

	return 0;
}