#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITTLE_MAX_LENGTH 100
#define DEADLINE_MAX_LENGTH 100

// cấu trúc nhiệm vụ
typedef struct Task {
    int id; // id nhiệm vụ
    char tittle[TITTLE_MAX_LENGTH]; // tên nhiệm vụ
    int priority; // mức độ ưu tiên của nhiệm vụ
    char deadline[DEADLINE_MAX_LENGTH]; // thời gian hoàn thành nhiệm vụ
} Task;

// khai báo danh sách liên kết đơn lưu các nhiệm vụ
typedef struct SingerNode {
    Task task;
    struct SingerNode *next;
} SingerNode;

// hàm khởi tạo
SingerNode* createNode(Task task) {
    SingerNode* newNode = (SingerNode*)malloc(sizeof(SingerNode));
    newNode->task = task;
    newNode->next = NULL;
    return newNode;
}

// hàm check trùng id
int checkId(SingerNode* head, int id) {
    SingerNode* temp = head;
    while (temp != NULL) {
        if (temp->task.id == id) {
            return 1; // trùng
        }
        temp = temp->next;
    }
    return 0;
}

// hàm thêm nhiệm vụ
SingerNode* createTask(SingerNode* head) {
    Task task;
    do {
        printf("Nhap id nhiem vu: ");
        scanf("%d", &task.id);
        if (task.id <= 0) {
            printf("Id phai la so nguyen duong, hay nhap lai\n");
        }else if (checkId(head, task.id)) {
            printf("Id da ton tai vui long chon id khac\n");
        }
    }while (task.id <= 0 || checkId(head, task.id));

    getchar();
    printf("Nhap tieu de nhiem vu: ");
    fgets(task.tittle, TITTLE_MAX_LENGTH, stdin);
    task.tittle[strcspn(task.tittle, "\n")] = '\0';

    printf("Nhap muc do uu tien nhiem vu: ");
    scanf("%d", &task.priority);

    getchar();
    printf("Nhap thoi gian hoan thanh nhiem vu: ");
    fgets(task.deadline, DEADLINE_MAX_LENGTH, stdin);
    task.deadline[strcspn(task.deadline, "\n")] = '\0';

    SingerNode* newNode = createNode(task);
    newNode->next = head;
    printf("Them nhiem vu thanh cong\n");
    return newNode;
}

// hàm in nhiệm vụ
void printfTask(SingerNode* head) {
    SingerNode* temp = head;
    printf("Danh sach nhiem vu\n");
    while (temp != NULL) {
        printf("Id: %d | Tittle: %s | Priority: %d | Deadline: %s\n", temp->task.id, temp->task.tittle, temp->task.priority, temp->task.deadline);
        temp = temp->next;
    }
}

// hàm xóa nhiệm vụ theo id
SingerNode* deleteNode(SingerNode* head) {
    int idDelete;
    printf("Nhap id nhiem vu ban muon xoa: ");
    scanf("%d", &idDelete);

    SingerNode* temp = head;
    SingerNode* prev = NULL;

    while (temp && temp->task.id != idDelete) {
        prev = temp;
        temp = prev->next;
    }

    if (!temp) {
        printf("Khong tim thay nhiem vu\n");
        return temp;
    }
    if (!prev) {
        head = temp->next;
    }else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Xoa nhiem vu thanh cong\n");
    return head;
}

// hàm cập nhật nhiệm vụ
void updateTask(SingerNode* head) {
    int idUpdate;
    printf("Nhap id nhiem vu can cap nhat: ");
    scanf("%d", &idUpdate);

    SingerNode* temp = head;

    while (temp && temp->task.id != idUpdate) {
        temp = temp->next;
    }

    if (!temp) {
        printf("Khong tim thay nhiem vu\n");
        return;
    }

    getchar();
    printf("Nhap ten nhiem vu moi: ");
    fgets(temp->task.tittle, TITTLE_MAX_LENGTH, stdin);
    temp->task.tittle[strcspn(temp->task.tittle, "\n")] = '\0';

    printf("Nhap muc do uu tien nhiem vu: ");
    scanf("%d", &temp->task.priority);

    getchar();
    printf("Nhap thoi gian hoan thanh nhiem vu: ");
    fgets(temp->task.deadline, DEADLINE_MAX_LENGTH, stdin);
    temp->task.deadline[strcspn(temp->task.deadline, "\n")] = '\0';

    printf("Cap nhat nhiem vu thanh cong\n");
}

// hàm sắp xếp nhiệm vụ theo mức độ ưu tiên tăng dần
void bubbleSortTask(SingerNode* head) {
    if (head == NULL) {
        printf("Danh sach nhiem vu rong\n");
        return;
    }

    SingerNode* i;
    SingerNode* j;
    for (i=head; i!=NULL; i=i->next) {
        for (j=i->next; j!=NULL; j=j->next) {
            if (i->task.priority > j->task.priority) {
                Task temp = i->task;
                i->task = j->task;
                j->task = temp;
            }
        }
    }
    printf("Sap xep thanh cong\n");
}

// hàm tìm kiếm nhiệm vụ
void searchtask(SingerNode* head) {
    char tittle[TITTLE_MAX_LENGTH];
    getchar();
    printf("Nhap ten nhiem vu ban muon tim: ");
    fgets(tittle, TITTLE_MAX_LENGTH, stdin);
    tittle[strcspn(tittle, "\n")] = '\0';

    int found = 0;
    SingerNode* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->task.tittle, tittle) == 0) {
            found = 1;
            printf("Id: %d | Tittle: %s | Priority: %d | Deadline: %s\n", temp->task.id, temp->task.tittle, temp->task.priority, temp->task.deadline);
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Khong tim thay nhiem vu\n");
    }
}

//=======================================================================
// khai báo danh sách liên kết đôi
typedef struct DoubleNode {
    Task task;
    struct DoubleNode* next;
    struct DoubleNode* prev;
} DoubleNode;

// hàm khởi tạo double node
DoubleNode* createDoubleNode(Task task) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->task = task;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// hàm đánh dấu khóa học đã hoàn thành
void completeTask(SingerNode** head, DoubleNode** headDouble) {
    int idComplete;
    printf("Nhap id can danh dau hoan thanh: ");
    scanf("%d", &idComplete);

    SingerNode* currentNode = *head;
    SingerNode* prev = NULL;

    while (currentNode != NULL && currentNode->task.id != idComplete) {
        prev = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        printf("Khong tim thay nhiem vu\n");
        return;
    }

    DoubleNode* completeNode = createDoubleNode(currentNode->task);
    completeNode->next = *headDouble;
    if ((*headDouble) != NULL) {
        (*headDouble)->prev = completeNode;
    }
    *headDouble = completeNode;

    if (prev == NULL) {
        *head = currentNode->next;
    }else {
        prev->next = currentNode->next;
    }
    free(currentNode);
    printf("Danh dau khoa hoc thanh cong\n");
}




//==============================================================================

// void hàm giải phóng bộ nhớ
void freeTask(SingerNode* head, DoubleNode* headDouble) {
    SingerNode* temp = head;
    while (temp != NULL) {
        SingerNode* currentNode = temp;
        temp = temp->next;
        free(currentNode);
    }

    // giải phóng danh sách liên kết đôi
    DoubleNode* tempDouble = headDouble;
    while (tempDouble != NULL) {
        DoubleNode* currentDoubleNode = tempDouble;
        tempDouble = tempDouble->next;
        free(currentDoubleNode);
    }
}

int main() {
    int choice;
    SingerNode* head = NULL;
    DoubleNode* headDouble = NULL;

    do {
        printf("=====TASK MANAGER=====\n");
        printf("1. Them nhiem vu cua ban\n");
        printf("2. Hien thi danh sach nhiem vu\n");
        printf("3. Xoa nhiem vu\n");
        printf("4. Cap nhat thong tin nhiem vu\n");
        printf("5. Danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep nhiem vu\n");
        printf("7. Tim kiem nhiem vu\n");
        printf("8. Thoat chuong trinh\n");
        printf("================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createTask(head);
                break;
            case 2:
                printfTask(head);
                break;
            case 3:
                head = deleteNode(head);
                break;
            case 4:
                updateTask(head);
                break;
            case 5:
                completeTask(&head, &headDouble);
                break;
            case 6:
                bubbleSortTask(head);
                break;
            case 7:
                searchtask(head);
                break;
            case 8:
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Lua chon khong hop le");
        }
    }while (choice != 8);

    freeTask(head, headDouble);
    return 0;
}
