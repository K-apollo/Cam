#include <stdio.h>
#include "cCamControl.h"

int main() 
{
    int camera_count = check_cameras();    // 카메라 수 체크

    // 카메라 수에 따른 제어
    if (camera_count == 1)     control_single_camera();
    else if (camera_count > 1) control_multiple_cameras(camera_count);
    else                       printf("카메라가 감지되지 않았습니다.\n");

    return 0;
}