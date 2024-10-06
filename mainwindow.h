#ifndef H_MAIN_WINDOW
#define H_MAIN_WINDOW
#include <QtWidgets>
#include <qlabel.h>
#include <qobjectdefs.h>

class MainWindow : public QWidget {
  Q_OBJECT
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
public slots:
  void onSelectClicked();

private:
  QLabel *_titleLabel;
  QLabel *_filenameLabel;
  QLineEdit *_fileEdit;
  QPushButton *_fileBtn;
  QLabel *_md5Label;
  QLineEdit *_md5Edit;
  QVBoxLayout *mainLayout;
  QGridLayout *gridLayout;
  QString  selectedFilename;
};

#endif // !H_MAIN_WINDOW
