#ifndef CCAMCONTROL_H
#define CCAMCONTROL_H

int check_cameras();                                // 카메라 수를 체크하는 함수 선언
void control_single_camera();                       // 단일 카메라 제어 함수 선언
void control_multiple_cameras(int camera_count);    // 다중 카메라 제어 함수 선언
char* execute_command(const char* cmd);             // 시스템 명령어 실행 및 결과 반환 함수 선언

#endif                                              // CCAMCONTROL_H