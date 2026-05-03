#include "Dialog.h"
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Dialog dialog;
    dialog.Execute();

    return 0;
}
