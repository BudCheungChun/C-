#include<iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct staff {
	char name[50];
	char lib_name[50];
	int staff_num;

	struct staff* next;
}STAFF;

void help_msg();
STAFF* insert_node(STAFF *head,STAFF tmp);
void print_all_node(STAFF *head);

int main() {
	help_msg();
	STAFF* head = NULL;
	char cmd[10] = {0};
	while (1) {
		cout << "Please enter command : " << endl;
		cin >> cmd;
		if (0 == strcmp(cmd,"help")) {
			help_msg();
		}
		else if (0 == strcmp(cmd,"insert")) {
			STAFF tmp;
			cout << "Please enter name,library_name,staff_number" << endl;
			cin >> tmp.name >> tmp.lib_name >> tmp.staff_num;
			head = insert_node(head,tmp);
		}
		else if (0 == strcmp(cmd, "print")) {
			print_all_node(head);
		}
		else if (0 == strcmp(cmd, "search")) {
			cout << "---- search ----" << endl;
		}
		else if (0 == strcmp(cmd, "del")) {
			cout << "---- del ----" << endl;
		}
		else if (0 == strcmp(cmd, "free")) {
			cout << "---- free ----" << endl;
		}
		else if (0 == strcmp(cmd, "quit")) {
			break;
		}
		else {
			cout << "wrong command." << endl;
		}
	}
}

void help_msg() {
	cout << "###########################################" << endl;
	cout << "# command list                            #" << endl;
	cout << "# help : help message                     #" << endl;
	cout << "# insert : insert node                    #" << endl;
	cout << "# print : print all noode                 #" << endl;
	cout << "# search : search node                    #" << endl;
	cout << "# del : delete node                       #" << endl;
	cout << "# free : free node                        #" << endl;
	cout << "# quit : quit                             #" << endl;
	cout << "###########################################" << endl;
}

STAFF* insert_node(STAFF *head,STAFF tmp) {
	STAFF* p = new STAFF();
	*p = tmp;
	if (NULL == head) {
		head = p;
		p->next = NULL;
		return head;
	}
	else if (NULL != head) {
		STAFF* pf = head; STAFF* pb = head;//一開始pb跟pf都指向head
		while ((p->staff_num > pb->staff_num) && (pb->next != NULL)) {
			pf = pb;//pf保存前pb狀態
			pb = pb->next;//pb前行一步
		}//當while運行至條件不滿足時,就會停下,並運行以下代碼

		//用if 判斷p停下的位置,pb->staff_num與p->staff_num誰大誰小,
		//從而決停之後怎麼做
		if (p->staff_num <= pb->staff_num) {//p停在一個p比pb小的位置
			if (head == pb) {//p停在head的前面
				p -> next = pb;//屬於p比pb小的位置
				head = p;
				return head;
			}
			else if (head != pb) {//p並不停在head的前面,而是停在中間
				p->next = pb;//屬於p比pb小的位置
				pf->next = p;
				return head;
			}
		}
		else if (p->staff_num >= pb->staff_num) {//p停在一個p比pb大的位置
			pf->next = p;
			p->next = NULL;
			return head;
		}
	}
}

void print_all_node(STAFF *head) {
	if (NULL == head) {
		cout << "There is no node." << endl;
	}
	else if (NULL != head) {
		STAFF* pb = head;//設置一個能讀取節點的STAFF *pb
		while (NULL != pb) {
			cout <<"Name : " << pb->name << endl
				 <<"Library_name : " << pb->lib_name <<endl
				 << "Staff_number : " << pb->staff_num << endl;
			pb = pb->next;
		}
	}
}
