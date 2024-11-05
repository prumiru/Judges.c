#include <stdio.h>
#include <stdlib.h>

int main() {
    int MAX_JUDGES, SELECTED_JUDGES;
    char project_name[100];
    
    // 프로젝트 이름 입력
    printf("참여 프로젝트: ");
    fgets(project_name, sizeof(project_name), stdin);
    // 개행 문자 제거
    for(int i = 0; project_name[i]; i++) {
        if (project_name[i] == '\n') {
            project_name[i] = '\0';
        }
    }
    
    // 심사 풀 인원과 선발 멤버 수 입력
    printf("심사 풀 인원 수를 입력하세요: ");
    scanf_s("%d", &MAX_JUDGES);
    printf("선발 멤버 수를 입력하세요: ");
    scanf_s("%d", &SELECTED_JUDGES);
    getchar(); // 버퍼 비우기

    // 심사자 정보 입력
    struct Judge {
        char name[50];
        char gender[10];
        char affiliation[100];
        char title[100];
        char expertise[100];
        char email[100];
        char phone[15];
    };

    struct Judge judges_array[MAX_JUDGES];
    int judge_count = 0;

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%s 프로젝트의 심사자 정보 입력을 시작합니다.\n", project_name);
    printf("++++++++++++++++++++++++++++++++++++\n");

    while (judge_count < MAX_JUDGES) {
        printf("* 심사자 %d: ", judge_count + 1);

        // 심사자 정보 입력 (JSON 형태로)
        printf("이름: ");
        fgets(judges_array[judge_count].name, sizeof(judges_array[judge_count].name), stdin);
        printf("성별: ");
        fgets(judges_array[judge_count].gender, sizeof(judges_array[judge_count].gender), stdin);
        printf("소속: ");
        fgets(judges_array[judge_count].affiliation, sizeof(judges_array[judge_count].affiliation), stdin);
        printf("직함: ");
        fgets(judges_array[judge_count].title, sizeof(judges_array[judge_count].title), stdin);
        printf("전문 분야: ");
        fgets(judges_array[judge_count].expertise, sizeof(judges_array[judge_count].expertise), stdin);
        printf("메일: ");
        fgets(judges_array[judge_count].email, sizeof(judges_array[judge_count].email), stdin);
        printf("전화: ");
        fgets(judges_array[judge_count].phone, sizeof(judges_array[judge_count].phone), stdin);

        // 개행 문자 제거
        for(int i = 0; judges_array[judge_count].name[i]; i++) {
            if (judges_array[judge_count].name[i] == '\n') {
                judges_array[judge_count].name[i] = '\0';
            }
        }
        for(int i = 0; judges_array[judge_count].gender[i]; i++) {
            if (judges_array[judge_count].gender[i] == '\n') {
                judges_array[judge_count].gender[i] = '\0';
            }
        }
        for(int i = 0; judges_array[judge_count].affiliation[i]; i++) {
            if (judges_array[judge_count].affiliation[i] == '\n') {
                judges_array[judge_count].affiliation[i] = '\0';
            }
        }
        for(int i = 0; judges_array[judge_count].title[i]; i++) {
            if (judges_array[judge_count].title[i] == '\n') {
                judges_array[judge_count].title[i] = '\0';
            }
        }
        for(int i = 0; judges_array[judge_count].expertise[i]; i++) {
            if (judges_array[judge_count].expertise[i] == '\n') {
                judges_array[judge_count].expertise[i] = '\0';
            }
        }
        for(int i = 0; judges_array[judge_count].email[i]; i++) {
            if (judges_array[judge_count].email[i] == '\n') {
                judges_array[judge_count].email[i] = '\0';
            }
        }
        for(int i = 0; judges_array[judge_count].phone[i]; i++) {
            if (judges_array[judge_count].phone[i] == '\n') {
                judges_array[judge_count].phone[i] = '\0';
            }
        }

        judge_count++;
    }

    printf("\n++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀 확인 여부
    char confirm;
    printf("[%s] 심사자 풀을 확인할까요? (Y/N): ", project_name);
    scanf_s(" %c", &confirm);
    getchar(); // 버퍼 비우기

    if (confirm == 'Y' || confirm == 'y') {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");

        for (int i = 0; i < MAX_JUDGES; i++) {
            printf("[심사자 %d]\n", i + 1);
            printf("이름: %s\n", judges_array[i].name);
            printf("성별: %s\n", judges_array[i].gender);
            printf("소속: %s\n", judges_array[i].affiliation);
            printf("직함: %s\n", judges_array[i].title);
            printf("전문 분야: %s\n", judges_array[i].expertise);
            printf("메일: %s\n", judges_array[i].email);
            printf("전화: %s\n", judges_array[i].phone);
            printf("-----------------------------------\n");
        }
    }
    else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}
