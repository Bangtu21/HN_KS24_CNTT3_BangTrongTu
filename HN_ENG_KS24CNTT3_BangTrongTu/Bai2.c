#include <stdio.h>

int main() {
    int choice;

    do {
        printf("=====TEXT EDITOR=====\n");
        printf("1. INSERT x - them ky tu x vao cuoi van ban\n");
        printf("2. UNDO - hoan tac thao tac gan nhat(xoa ky tu cuoi)\n");
        printf("3. REDO - Phuc hoi thao tac vua undo\n");
        printf("4. HIEN THI - in van ban hien tai\n");
        printf("5. THOAT\n");
        printf("===============\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }while (choice != 5);
}
