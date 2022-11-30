#include "widget.h"
#include <QDebug>
#include <QApplication>

/// @brief Main fuction
/// @param argc Argument count
/// @param argv Argument vector
/// @return Error code
int main(int argc, char *argv[]) {
  QApplication application(argc, argv);
  Widget widget;
  widget.show();
  return application.exec();
}
