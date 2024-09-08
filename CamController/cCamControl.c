#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cCamControl.h"

char* execute_command(const char* cmd) // 시스템 명령어를 실행하고 결과를 반환하는 함수
{
    FILE* pipe = popen(cmd, "r");
    if (!pipe) 
    {
        perror("popen 실패");
        return NULL;
    }

    char* result = malloc(1024);
    if (!result) 
    {
        perror("메모리 할당 실패");
        pclose(pipe);
        return NULL;
    }

    fgets(result, 1024, pipe);
    pclose(pipe);
    return result;
}

int check_cameras()                 // Wi-Fi 및 Bluetooth를 통해 연결된 카메라를 확인하는 함수
{
    char* wifi_devices = execute_command("nmcli dev wifi list | grep -i camera");    // 우분투에서 와이파이 장치 스캔 명령어
    char* bt_devices = execute_command("bluetoothctl devices | grep -i camera");    // 우분투에서 블루투스 장치 확인 명령어
    int camera_count = 0;

    if (wifi_devices && strstr(wifi_devices, "Camera")) camera_count++;

    if (bt_devices && strstr(bt_devices, "Camera")) camera_count++;

    free(wifi_devices);
    free(bt_devices);

    return camera_count;
}

void control_single_camera() // 단일 카메라를 제어하는 함수
{
    printf("하나의 카메라를 제어 중...\n");    // 카메라 제어를 위한 구체적인 로직 추가
}

void control_multiple_cameras(int camera_count) // 여러 대의 카메라를 제어하는 함수
{
    printf("%d개의 카메라를 제어 중...\n", camera_count);    // 여러 대의 카메라를 제어하는 로직 추가
}