#include "mainwindow.h"
#include "iostream"
#include <qdebug.h>
#include <qobjectdefs.h>
#include <qwidget.h>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  _titleLabel = new QLabel("File Valid in Qt", this);
  _filenameLabel = new QLabel("Please select file", this);
  _fileEdit = new QLineEdit(this);
  _fileBtn = new QPushButton("Select File", this);
  _md5Label = new QLabel("Md5:", this);
  _md5Edit = new QLineEdit(this);
  _md5Edit->setDisabled(true);

  _fileEdit->setDisabled(true);

  mainLayout = new QVBoxLayout(this);
  mainLayout->setAlignment(Qt::AlignCenter);
  mainLayout->addWidget(_titleLabel);
  gridLayout = new QGridLayout(this);
  gridLayout->setSpacing(20);

  gridLayout->addWidget(_filenameLabel, 0, 0);
  gridLayout->addWidget(_fileEdit, 1, 0);
  gridLayout->addWidget(_fileBtn, 1, 1);
  gridLayout->addWidget(_md5Label, 3, 0);
  gridLayout->addWidget(_md5Edit, 4, 0);
  mainLayout->addItem(gridLayout);
  this->setLayout(mainLayout);

  connect(_fileBtn, SIGNAL(clicked()), this, SLOT(onSelectClicked()));
}

MainWindow::~MainWindow() {
  delete _titleLabel;
  delete _filenameLabel;
  delete _fileEdit;
  delete _fileBtn;
  delete _md5Label;
  delete _md5Edit;
  delete mainLayout;
  delete gridLayout;
  std::cout << "MainWindow Destoried" << std::endl;
}

void MainWindow::onSelectClicked() {
  selectedFilename = QFileDialog::getOpenFileName(this);
  this->_fileEdit->setText(selectedFilename);
  qDebug() << selectedFilename << Qt::endl;
}
