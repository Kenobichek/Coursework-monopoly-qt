#include <QtWidgets/QApplication>

#include "Components/Game/Menu.h"
#include "Components/Game/Monopoly.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu menu;
    menu.show();

    return a.exec();

}
