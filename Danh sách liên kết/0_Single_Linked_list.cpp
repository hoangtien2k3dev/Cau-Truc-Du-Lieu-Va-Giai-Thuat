
// Link: https://topdev.vn/blog/danh-sach-lien-ket-don-trong-c/

/*
    Danh sách liên kết đơn (Single Linked List) là một cấu trúc dữ liệu động, nó là một danh sách 
    mà mỗi phần tử đều liên kết với phần tử đúng sau nó trong danh sách. Mỗi phần tử 
    (được gọi là một node hay nút) trong danh sách liên kết đơn là một cấu trúc có hai thành phần:

        + Thành phần dữ liệu: lưu thông tin về bản thân phần tử đó.
        + Thành phần liên kết: lưu địa chỉ phần tử đứng sau trong danh sách, nếu phần tử đó là phần tử cuối cùng thì thành phần này bằng NULL.



    ! Đặc điểm của danh sách liên kết đơn:
        * Do danh sách liên kết đơn là một cấu trúc dữ liệu động, được tạo nên nhờ việc cấp phát động nên nó có một số đặc điểm sau đây:

        + Được cấp phát bộ nhớ khi chạy chương trình.
        + Có thể thay đổi kích thước qua việc thêm, xóa phần tử.
        + Kích thước tối đa phụ thuộc vào bộ nhớ khả dụng của RAM.
        + Các phần tử được lưu trữ ngẫu nhiên (không liên tiếp) trong RAM.


        * Và do tính liên kết của phần tử đầu và phần tử đứng sau nó trong danh sách liên kết đơn, nó có các đặc điểm sau:

        + Chỉ cần nắm được phần tử đầu và cuối là có thể quản lý được danh sách.
        + Truy cập tới phần tử ngẫu nhiên phải duyệt từ đầu đến vị trí đó.
        + Chỉ có thể tìm kiếm tuyến tính một phần tử.


*/

/*
    !Tạo Node:
        Danh sách liên kết đơn được tạo thành từ nhiều node
        * Một node gồm hai thành phần: là 
            + thành phần dữ liệu.
            + thành phần liên kết.

        Ex: 
            struct Node
            {
                int data;
                Node* next;
            };

        * Để tạo một node mới, ta thực hiện cấp phát động cho node mới, khởi tạo giá trị ban đầu và trả về địa chỉ của node mới được cấp phát.

            Node* CreateNode(int init_data)
            {
                Node* node = new Node;
                node->data = init_data;
                node->next = NULL;      //  node vừa tạo chưa thêm vào danh sách nên chưa liên 
                                            kết với phần tử nào cả nên phần liên kết gán bằng NULL
                return node;
            }
*/

/*
    ! Tạo danh sách liên kết đơn:
        

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

typedef struct Node* node;

Node *makeNode(int x) {
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

bool empty(Node *a) {
    return a == NULL;
}

int size(node a) {
    int count = 0;
    while(a != NULL) {
        ++count;
        a = a->next; // cho node hiện tại nhảy sang node tiếp theo // (giống như i++)
    }
    return count;
}


// thêm phần tử vào đầu danh sách:
void addHead(node &a, int x) {
    node temp = makeNode(x);
    if (a == NULL) {
        a = temp; // gán luôn a cho node ta thêm vào( vì a là phần tử đầu danh sách liên kết)
    } else {
        temp->next = a; // liên kết temp với danh sách liên kết
        a = temp; // a nhảy về phần tử đầu tiên.
    }
}

// thêm phần tử vào cuối danh sách:
void addTail(node &a, int x) {
    node temp = makeNode(x);
    if (a == NULL) {
        a = temp;
    } else {
        node p = a; // để danh sách không bị biến đổi
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}


// thêm một phâng tử vào giữa:
void addMiddle(node &a, int x, int pos) {
    int n = size(a);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri chen khong hop le!" << endl;
    } else if (n == 1) {
        addHead(a, x); 
        return;
    } else if (n == pos + 1) {
        addTail(a, x);
        return;
    } else {
        node p = a;
        for(int i = 1; i < pos - 1; i++) {
            p = p->next;
        }
        node temp = makeNode(x);
        temp->next = p->next;
        p->next = temp;
    }
}


// xóa phần tử ở đầu:
void deleteHead(node &a) {
    if (a == NULL) return;
    a = a->next;
}


// xóa phần tử ở cuối:
void deleteTail(node &a) {
    if (a == NULL) return;
    node truoc = NULL, sau = a;
    while(sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        a = NULL;
    } else {
        truoc->next = NULL;
    }
}
    

// xóa phần tử ở giữa:
void deleteMiddle(node &a, int pos) {
    if (pos <= 0 || pos > size(a)) return;
    node truoc = NULL, sau = a;
    for(int i = 1; i < pos; i++) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        a = a->next;
    } else {
        truoc->next = sau->next;
    }
}

// sắp xếp theo thứ tự tăng dần trong danh sách liên kết:
void sapxep(node &a) { // selection sort
    for(node p = a; p->next != NULL; p = p->next) {
        node min = p;
        for(node q = p->next; q != NULL; q = q->next) {
            if (q->data < min->data) {
                min = q;
            }
        }
        int temp = min->data;
        min->data = p->data;
        p->data = temp;
    }
}


// in danh sach:
void in_danh_sach(node a) {
    cout << "\n____________________________\n";
    while(a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n____________________________\n";
}


int main() {
    node head = NULL; // node đầu tiên bằng NULL
    while(1) {
        cout << "____________Menu__________\n";
        cout << "1. chen phan tu o dau danh sach\n";
        cout << "2. chen phan tu o cuoi danh sach\n";
        cout << "3. chen phan tu o giua danh sach\n";
        cout << "4. xoa phan tu o dau\n";
        cout << "5. xoa phan tu o cuoi\n";
        cout << "6. xoa phan tu o giua\n";
        cout << "7. duyet danh sach lien ket\n";
        cout << "8. sap xep phan tu tang dan\n";
        cout << "0. KET THUC CHUONG TRINH\n";
        cout << "___________________________\n";
        cout << "---Nhap lua chon---: ";
        int lc; cin >> lc;
        if (lc == 1) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            addHead(head, x);
        } else if (lc == 2) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            addTail(head, x);
        } else if (lc == 3) {
            int x; cout << "Nhap gia tri can chen: "; cin >> x;
            int pos; cout << "Nhap vi tri can chen: "; cin >> pos;
            addMiddle(head, x, pos);
        } else if (lc == 4) {
            deleteHead(head);
        } else if (lc == 5) {
            deleteTail(head);
        } else if (lc == 6) {
            int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
            deleteMiddle(head, pos); 
        } else if (lc == 7) {
            in_danh_sach(head);
        } else if (lc == 8){
            sapxep(head);
        } else if (lc == 0) {
            break;
        }
    }   
}




