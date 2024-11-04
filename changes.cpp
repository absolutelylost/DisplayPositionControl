#include <windows.h>
#include <iostream>

int main() {
    // Get all display devices
    DISPLAY_DEVICE dd;
    dd.cb = sizeof(DISPLAY_DEVICE);
    
    int numOfDisplays = 0;
    // hold coordinates for positional pairing of monitors
    int coordinatesX [9] = {0, 2560, 6400, 2560, 6400,
                            2560, 6400, 2560, 6400};
    int coordinatesY [9] = {0, 4320, 4320, 6480, 6480,
                            0, 0, 2160, 2160};


    // get data for displays in system
    for (DWORD i = 0; EnumDisplayDevices(NULL, i, &dd, 0); i++) {
        if (dd.StateFlags & DISPLAY_DEVICE_ACTIVE) {
            DEVMODE dm;
            dm.dmSize = sizeof(DEVMODE);
            EnumDisplaySettings(dd.DeviceName, ENUM_CURRENT_SETTINGS, &dm);

            // Set new monitor coordinates
            dm.dmPosition.x = coordinatesX[numOfDisplays];
            dm.dmPosition.y = coordinatesY[numOfDisplays];
            
            //show locations moved to
            std::cout << "display: " << numOfDisplays 
                    << "dimensions: " << coordinatesX[numOfDisplays]
                    << " x " << coordinatesY[numOfDisplays]<< std::endl;

            dm.dmFields = DM_POSITION;
            numOfDisplays++;
            // Apply changes
            LONG result = ChangeDisplaySettingsEx(dd.DeviceName, &dm, NULL, CDS_UPDATEREGISTRY, NULL);

            if (result == DISP_CHANGE_SUCCESSFUL) {
                // Success
            } else {
                // Handle error
            }
        }
    }

    return 0;
}
