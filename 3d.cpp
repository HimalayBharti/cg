#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

int main() {
    int window1 = initwindow(800, 800);
    bar3d(270, 200, 370, 300, 50, 5); // Initial 3D bar

    int ch;
    cout << "Select Your Choice for 3D Transformation\n";
    cout << "1. Translate\n2. Scale\n3. Rotation along x-axis\n4. Shearing\n";
    cin >> ch;
    cleardevice(); // Clear the screen for transformation

    switch (ch) {
        case 1: {
            int tx, ty;
            cout << "Enter the translation factor for x,y axis: ";
            cin >> tx >> ty;
            bar3d(270 + tx, 200 + ty, 370 + tx, 300 + ty, 50, 5); // Translated bar
            delay(7000);
            cleardevice();
            outtextxy(10, 20, "Parallel projection side view");
            bar3d(0, 200 + ty, 0, 300 + ty, 50, 5); // Side view after translation
            delay(7000);
            break;
        }
        case 2: {
            int sx, sy;
            cout << "Enter the scaling factor for x,y axis: ";
            cin >> sx >> sy;
            bar3d(270 * sx, 200 * sy, 370 * sx, 300 * sy, 50, 5); // Scaled bar
            delay(7000);
            cleardevice();
            outtextxy(10, 20, "Parallel projection side view");
            bar3d(0, 200 * sy, 0, 300 * sy, 50, 5); // Side view after scaling
            delay(7000);
            break;
        }
        case 4: {
            int shx, shy;
            cout << "Enter the shearing factor for x,y axis: ";
            cin >> shx >> shy;
            bar3d(270 + (shx * 270), 
                   200 + (shy * 270), 
                   370 + (shx * 370), 
                   300 + (shy * 300), 
                   50 + (shx * 50), 
                   5); // Sheared bar
            delay(7000);
            break;
        }
        case 3: {
            int ang;
            cout << "Enter the rotation angle: ";
            cin >> ang;
            
            // Convert angle from degrees to radians
            ang = (ang * M_PI) / 180; 

            // Calculate new coordinates after rotation
            int x1 = static_cast<int>(200 * cos(ang) - 50 * sin(ang));
            int y1 = static_cast<int>(50 * cos(ang) + 200 * sin(ang));
            int x2 = static_cast<int>(300 * cos(ang) - 500 * sin(ang));
            int y2 = static_cast<int>(50 * cos(ang) + 300 * sin(ang));

            bar3d(x1, y1, x2, y2, 50, 5); // Rotated bar
            delay(7000);
            break;
        }
        default:
            cout << "Invalid choice!" << endl; // Handle invalid input
    }

    return 0;
}
