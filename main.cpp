#include <iostream>
#include <Windows.h>

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
    MONITORINFOEX monitorInfo;
    monitorInfo.cbSize = sizeof(MONITORINFOEX);
    GetMonitorInfo(hMonitor, &monitorInfo);

    std::cout << "Monitor Name: " << monitorInfo.szDevice << std::endl;
    std::cout << "Position: (" << monitorInfo.rcMonitor.left << ", " << monitorInfo.rcMonitor.top << ")" << std::endl;
    std::cout << "Size: " << monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left << " x " << monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top << std::endl;
    std::cout << std::endl;

    return TRUE;
}

int main() {
    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, 0);
    
    return 0;
}

    // int coordinatesX [9] = {0, 2560, 6400, 2560, 6400, 
    //                         2560, 6400, 2560, 6400};
    // int coordinatesY [9] = {0,0, 2160, 2160, 
    //                         4320, 4320, 6480, 6480};

