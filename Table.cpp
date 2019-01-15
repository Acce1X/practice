//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>

Table::Table() {
    tableArr = new Employee *[ARR_SIZE];    //总表
    deleteArr = new Employee *[ARR_SIZE];    //逻辑删除表
    size = ARR_SIZE;
    rear = 0;
    if (!readFromFile("RegStaffInf.txt"))
        cout << "can not read data correctly";
    if (!readFromFile("TmpStaffInf.txt"))
        cout << "can not read data correctly";
}

//只统计某数额的工资人数
void Table::statData() {
    float wageSum = 0, wageAvg = 0;
    int l = Table::length();
    for (int i = 0; i < l; i++) {
        wageSum += Table::tableArr[i]->getBaseWage;
    }
    wageAvg = wageSum / l;
}

bool Table::readFromFile(string fileName, bool tableType) {

    ifstream infile(fileName);
    if (!infile.is_open())
        return false;
    else {
        bool type;
        infile >> type;
        if (type) {
            RegularEmployee *p;
            while (!infile.eof() {//update:使用push_back后不需要i
                double tmpAllowance, tmpProvidentFund, tmpPension,
                        tmpTax, tmpInsurance, tmpBaseWage, tmpRealWage;
                int tmpId, tmpAge;
                bool tmpSex;
                string tmpName, tmpAddress;
                infile >> tmpId >> tmpName >> tmpSex >> tmpAge >> tmpAddress >> tmpBaseWage >> tmpAllowance >>
                       tmpProvidentFund >> tmpPension >> tmpTax >> tmpInsurance >> tmpRealWage;
                p = new RegularEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpAllowance,
                                        tmpProvidentFund, tmpPension, tmpTax, tmpInsurance);
                //内存重新分配
                //update:直接使用push_back函数添加新项
                push_back(p);
            }
            else{
                TemporaryEmployee *q;
                while (!infile.eof() {//update:使用push_back后不需要i
                    double tmpBaseWage, tmpRealWage, tmpTax, tmpBonus;
                    int tmpId, tmpAge;
                    bool tmpSex;
                    string tmpName, tmpAddress;
                    infile >> tmpId >> tmpName >> tmpSex >> tmpAge >> tmpAddress
                           >> tmpBaseWage >> tmpBonus >> tmpTax >> tmpRealWage;
                    q = new TemporaryEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpBonus,
                                              tmpTax);
                    //update:直接使用push_back函数添加新项
                    push_back(p);
                }

            }
            infile.close();
            return true;
        }
    }
}

bool Table::memExtension() {
    Employee **desMem = new Employee *[size + ARR_INCREMENT];
    if (!desMem)
        return false;
    else
        for (int i = 0; i < size; i++)
            desMem[i] = tableArr[i];
    delete[] tableArr;
    tableArr = desMem;
    size += ARR_INCREMENT;
    return true;
}

bool Table::readFromScreen() {
    bool type;
    cout << "请输入要添加的职工种类(1表示正式职工 0表示临时职工):";
    while (!(cin >> type)) {
        cout << "\n输入错误！请重新输入";
        cin.clear();
        while (cin.get() != '\n') {
        }
    }
    cout << "\n输入成功";
    while (cin.get() != '\n') {
    }
    Employee *p;
    if (type) {
        p = new RegularEmployee();
        p->readInfo();
    } else {
        p = new TemporaryEmployee();
        p->readInfo();
    }
	//插入表中
    //this.push
}

void Table::push_back(Employee *employee) {
    if (rear == size)
        if (!memExtension()) {
            cout << "memory error";
            return;
        }
    tableArr[rear] = employee;
    rear++;
}

Employee **Table::searchEmployee(int id = 0, string name = "", double realWage = 0.0,bool tableType) {
		Employee **p = new Employee[ARR_SIZE];
		int j = 0;
		if (tableType) {
			for (int i = 0; i < apacity; i++) {
				if (tableArr[i]->getId == id || tableArr[i]->getName == name || tableArr[i]->getRealWage== realWage) {
					p[j] = tableArr[i];
					j++;
				}
			}
			return p;
		}
		else{
			for (int i = 0; i < deleteApacity; i++) {
				if (deleteArr[i]->getId == id || deleteArr[i]->getName = name || deleteArr[i]->getRealWage = realWage) {
					p[j] = deleteArr[i];
					j++;
				}
			}
	}
}

bool **Table::updateEmployee(Employee *employee) {
	int c;
	if (employee->type) {
		cout << "输入要修改的项目\n";
		cout << "1.编号  2.姓名  3.性别  4.年龄  5.家庭住址 6.基本职务工资\n" <<
			"7.岗位津贴  8.住房公积金  9.养老金  10.所得税  11.医疗保险\n";
		cin >> c;
		switch (c) {
		case 1:
			cout << "输入修改后的编号\n";
			int tmpId;
			cin >> tmpId;
			employee->setId(tmpId);
			break;
		case 2:
			cout << "输入修改后的姓名\n";
			string tmpName;
			cin >> tmpName;
			employee->setId(tmpName);
			break;
		case 3:
			cout << "修改后的性别：男生为：TRUE 女生为：FALUSE";
			int tmpSex;
			cin >> tmpSex;
			employee->setSex(tmpSex);
			break;
		case 4:
			cout << "修改后的年龄\n";
			int tmpAge;
			cin >> tmpAge;
			employee->setAge(tmpAge);
			break;
		case 5:
			cout << "修改后的家庭住址\n";
			string tmpAddress;
			cin >> tmpAddress;
			employee->setAddress(tmpAddress);
			break;
		case 6:
			cout << "修改后的基本职务工资\n";
			double tmpBaseWage;
			cin >> tmpBaseWage;
			employee->setBaseWage(tmpBaseWage);
			break;
		case 7:
			cout << "修改后的岗位津贴\n";
			double tmpAllowance;
			cin >> tmpAllowance;
			employee->setAllowance(tmpAllowance);
			break;
		case 8:
			cout << "修改后的住房公积金\n";
			doule tmpProvidentFund;
			cin >> tmpProvidentFund;
			employee->setProvidentFund(tmpProvidentFund);
			break;
		case 9:
			cout << "修改后的养老金\n";
			double tmpPension;
			cin >> tmpPension;
			employee->setPension(tmpPension);
			break;
		case 10:
			cout << "修改后的所得税\n";
			double tmpTax;
			cin >> tmpTax;
			employee->setTax(tmpTax);
			break;
		case 11:
			cout << "修改后的医疗保险\n";
			double tmpInsurance;
			cin >> tmpInsurance;
			employee->setInsurance(tmpInsurance);
			break;
		}
	else {
		cout << "输入要修改的项目\n";
		cout << "1.编号  2.姓名  3.性别  4.年龄  5.家庭住址 6.基本职务工资\n" <<
			"7.奖金  8.所得税\n";
		cin >> c;
		switch (c) {
		case 1:
			cout << "输入修改后的编号\n";
			int tmpId;
			cin >> tmpId;
			employee->setId(tmpId);
			break;
		case 2:
			cout << "输入修改后的姓名\n";
			string tmpName;
			cin >> tmpName;
			employee->setId(tmpName);
			break;
		case 3:
			cout << "修改后的性别：男生为：TRUE 女生为：FALUSE";
			int tmpSex;
			cin >> tmpSex;
			employee->setSex(tmpSex);
			break;
		case 4:
			cout << "修改后的年龄\n";
			int tmpAge;
			cin >> tmpAge;
			employee->setAge(tmpAge);
			break;
		case 5:
			cout << "修改后的家庭住址\n";
			string tmpAddress;
			cin >> tmpAddress;
			employee->setAddress(tmpAddress);
			break;
		case 6:
			cout << "修改后的基本职务工资\n";
			double tmpBaseWage;
			cin >> tmpBaseWage;
			employee->setBaseWage(tmpBaseWage);
			break;
		case 7:
			cout << "修改后的奖金\n";
			double tmpBonus;
			cin >> tmpBonus;
			employee->setBonus(tmpBonus);
			break;
		case 8:
			cout << "修改后的所得税\n";
			double tmpRealWage;
			cin >> tmpRealWage;
			employee->setRealWage(tmpRealWage);
			break;
		}
	}
	cout << "修改成功\n";
	}
}

void Table::sortByRealWage() {                                         //将总表按实发工资进行排序
    for (int i = 0; i < this->size; i++) {
        if (*(*tableArr + i) != NULL) {
            for (int j = i + 1; j < this->size; j++) {
                if (*(*tableArr + j) != NULL) {
                    if (*(*tableArr + i).realwage < *(*tableArr + j).realwage) {
                        double t = (*tableArr + i);
                        (*tableArr + i) = (*tableArr + j);
                        (*tableArr + j) = t;
                    }
                }
            }
        }
    }
}

Table:: int search(int id) {
    for (int i = 0; i < length; i++)
        if (tableArr[i]->id == id)
            return i;
    cout << "can not find the object";
    return -1;
}

Table:: bool physicalDeleteEmployee(int id) {

    bool Table::saveInFile(string fileName, bool tableType) {
        ofstream out;
        out.open(fileName);
        for (int i = 0; i < apacity; ++i) {
            if (tableArr[i] != nullptr) {
                out << tableArr[i] << endl;
            }
        }
        out.close();
        return true;
    }


}

Table:: bool logicalDeleteEmployee(int id) {
    int pos = search(id);
    if (pos = -1);
    {
        employee *p = tableArr[pos];
        saveInFile("DeletedStaffInfo.txt");
        tableArr[pos] = NULL;
        return TRUE;
    }
    else
    return FALSE;
}







