#ifndef QLEDLABEL_H
#define QLEDLABEL_H

#include <QLabel>

/// @brief Widget that pretends to be a led
class QLedLabel : public QLabel {
  Q_OBJECT
 public:
  /// @brief Led builders
  /// @param parent Pointer to the main panel
  explicit QLedLabel(QWidget* parent = 0);
  /// @brief Enumeration with the colours of the led
  enum State{
    StateOk,
    StateOkBlue,
    StateWarning,
    StateError
  };
 signals:
 public slots:
  /// @brief Assign a color to the led object
  /// @param state Selected colour type
  void setState(State state);
};
#endif // QLEDLABEL_H
