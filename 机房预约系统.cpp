#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//����ѧ���Ӳ˵�����
void studentMenu(Identity* &student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();

		//������ָ��ǿתΪ����ָ�룬������������������ӿ�
		Student *stu = (Student*)student;

		int select = 0;
		while (true)
		{
			cin >> select;

			if (select==1)//����ԤԼ
			{
				stu->applyOrder();
				break;
			}
			else if (select == 2)//�鿴�ҵ�ԤԼ
			{
				stu->showMyOrder();
				break;
			}
			else if (select == 3)//�鿴����ԤԼ
			{
				stu->showAllOrder();
				break;
			}
			else if (select == 4)//ȡ��ԤԼ
			{
				stu->cancelOrder();
				break;
			}
			else if (select == 0)//ע����¼
			{
				delete student;
				system("pause");
				system("cls");
				return;
			}

			cout << "������������������." << endl;
		}

	}
}

//�����ʦ�Ӳ˵�����
void teacherMenu(Identity * &teacher)
{
	while (true)
	{
		//���ý�ʦ�Ӳ˵�
		teacher->operMenu();

		//������ָ��תΪ����ָ��  ���������������ӿ�
		Teacher * tea = (Teacher*)teacher;

		int select = 0;

		while (true)
		{
			cin >> select;

			if (select == 1)
			{
				tea->showAllOrder();
				break;
			}
			else if (select == 2)
			{
				tea->validOrder();
				break;
			}
			else if (select==0)
			{
				delete teacher;
				cout << "ע���ɹ�" << endl;
				system("pause");
				system("cls");
				return;
			}

			cout << "�����������������룡" << endl;

		}
	}
}


//�������Ա�Ӳ˵�����
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		Manager * man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1)//����˺�
		{
			//cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			//ע��
			delete manager;//ע������������
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//��¼���� ����1 �����ļ��� ����2 �����������
void LoginIn(string fileName, int type)
{
	//����ָ�� ָ���������
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)//ѧ�����
	{
		cout << "������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ���
	{
		cout << "������ְ���ţ�" << endl;
		cin >> id;
	}
	
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;//���ļ��ж�ȡ��ID��
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���Դ��룬���ԡ�ifs >> ���Ķ�ȡЧ��
			/*cout << fId << endl;
			cout << fName << endl;
			cout << fPwd << endl;*/

			//���û��������Ϣ���жԱ�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����¼��֤�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);

				return;

			}
		}
		
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;//���ļ��ж�ȡ��ID��
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���жԱ�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��¼��֤�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//������ʦ��ݵ��Ӳ˵�
				teacherMenu(person);

				return;

			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������
		while (ifs >> fName && ifs >> fPwd)
		{
			//���û��������Ϣ���жԱ�
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��¼��֤�ɹ�!" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);

				return;
			}
		}
	}

	cout << "��¼��֤ʧ�ܣ�" << endl;

	system("pause");
	system("cls");
	return;

}

int main()
{
	int select = 0;

	while (true)
	{
		cout << "=====================��ӭ�����ϲ���ѧ����ԤԼϵͳ======================="
			<< endl;
		cout << endl << "������������ݣ�" << endl;
		cout << "\t\t -----------------------------\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         1.ѧ������          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         2.��    ʦ          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         3.�� �� Ա          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|         0.��    ��          |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t -----------------------------\n";
		cout << "����������ѡ��";
		
		cin >> select;//�����û�ѡ��

		switch (select)//������û�ѡ��ʵ�ֲ�ͬ�ӿ�
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	


	system("pause");
	return 0;
}