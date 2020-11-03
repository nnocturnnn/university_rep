# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'menu.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        MainWindow.setStyleSheet("background-color: rgb(254, 206, 114);")
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.addButton = QtWidgets.QPushButton(self.centralwidget)
        self.addButton.setGeometry(QtCore.QRect(230, 80, 351, 81))
        self.addButton.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.addButton.setObjectName("addButton")
        self.deleteButton = QtWidgets.QPushButton(self.centralwidget)
        self.deleteButton.setGeometry(QtCore.QRect(230, 180, 351, 81))
        self.deleteButton.setAutoFillBackground(False)
        self.deleteButton.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.deleteButton.setObjectName("deleteButton")
        self.redButton = QtWidgets.QPushButton(self.centralwidget)
        self.redButton.setGeometry(QtCore.QRect(230, 280, 351, 81))
        self.redButton.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.redButton.setObjectName("redButton")
        self.searchButton = QtWidgets.QPushButton(self.centralwidget)
        self.searchButton.setGeometry(QtCore.QRect(230, 380, 351, 81))
        self.searchButton.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.searchButton.setObjectName("searchButton")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Library"))
        self.addButton.setText(_translate("MainWindow", "Додати книжку"))
        self.deleteButton.setText(_translate("MainWindow", "Видалити книжку"))
        self.redButton.setText(_translate("MainWindow", "Редагування"))
        self.searchButton.setText(_translate("MainWindow", "Пошук книжки"))

