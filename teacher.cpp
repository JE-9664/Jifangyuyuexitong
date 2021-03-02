#include "teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	this->empId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼!" << endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         1.�鿴ԤԼ          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         2.���ԤԼ          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|         0.ע����¼          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t -----------------------------\n";
	cout << "����������ѡ��";
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ǰ��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i+1 << "��";
		cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		cout << " ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ������ţ�" << of.m_orderData[i]["roomId"];
		string status = " ״̬��";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��,���δͨ��";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ǰ��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "�����ԤԼ��¼���£�" << endl;
	
	int index = 0;
	vector<int>v;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
			cout << " ������" << of.m_orderData[i]["stuName"];
			cout << " ԤԼ���ڣ�" << of.m_orderData[i]["date"];
			cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������ţ�" << of.m_orderData[i]["roomId"];
			string status = "״̬�������";
			cout << status << endl;
		}
	}

	cout << "��ѡ��Ҫ��˵ļ�¼��0 �������أ�" << endl;
	int select = 0;
	int ret = 0;

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽����" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//ͨ�����
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					//��ͨ�����
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();//����ԤԼ��¼
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;

	}
	system("pause");
	system("cls");
}