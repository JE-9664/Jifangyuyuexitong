#pragma once
#include<iostream>
#include<fstream>
#include"globalFile.h"
#include<map>
#include<string>
using namespace std;


class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������ key����¼����  value: �����¼��ֵ����Ϣ
	map<int, map<string, string>> m_orderData;


};