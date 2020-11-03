# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'add.ui'
#
# Created by: PyQt5 UI code generator 5.14.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_addWindow(object):
    def setupUi(self, addWindow):
        addWindow.setObjectName("addWindow")
        addWindow.resize(800, 600)
        addWindow.setStyleSheet("background-color: rgb(254, 206, 114);")
        self.centralwidget = QtWidgets.QWidget(addWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.add = QtWidgets.QPushButton(self.centralwidget)
        self.add.setGeometry(QtCore.QRect(310, 440, 201, 71))
        self.add.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.add.setObjectName("add")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setGeometry(QtCore.QRect(10, 20, 161, 51))
        self.pushButton.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.pushButton.setObjectName("pushButton")
        self.lineEdit = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit.setGeometry(QtCore.QRect(270, 110, 281, 41))
        self.lineEdit.setObjectName("lineEdit")
        self.lineEdit_2 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_2.setGeometry(QtCore.QRect(270, 170, 281, 41))
        self.lineEdit_2.setObjectName("lineEdit_2")
        self.lineEdit_3 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_3.setGeometry(QtCore.QRect(270, 290, 281, 41))
        self.lineEdit_3.setObjectName("lineEdit_3")
        self.lineEdit_4 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_4.setGeometry(QtCore.QRect(270, 230, 281, 41))
        self.lineEdit_4.setObjectName("lineEdit_4")
        self.lineEdit_5 = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_5.setGeometry(QtCore.QRect(270, 350, 281, 41))
        self.lineEdit_5.setObjectName("lineEdit_5")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(40, 110, 221, 31))
        self.label.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(40, 170, 221, 31))
        self.label_2.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(40, 230, 211, 31))
        self.label_3.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(40, 290, 211, 31))
        self.label_4.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.label_4.setObjectName("label_4")
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(40, 350, 211, 31))
        self.label_5.setStyleSheet("font: 24pt \".AppleSystemUIFont\";")
        self.label_5.setObjectName("label_5")
        addWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(addWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        self.menubar.setObjectName("menubar")
        addWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(addWindow)
        self.statusbar.setObjectName("statusbar")
        addWindow.setStatusBar(self.statusbar)

        self.retranslateUi(addWindow)
        QtCore.QMetaObject.connectSlotsByName(addWindow)

    def retranslateUi(self, addWindow):
        _translate = QtCore.QCoreApplication.translate
        addWindow.setWindowTitle(_translate("addWindow", "MainWindow"))
        self.add.setText(_translate("addWindow", "Додати"))
        self.pushButton.setText(_translate("addWindow", "назад"))
        self.label.setText(_translate("addWindow", "Виберіть автора(ів) :"))
        self.label_2.setText(_translate("addWindow", "Виберіть видання :"))
        self.label_3.setText(_translate("addWindow", "Виберіть жанр :"))
        self.label_4.setText(_translate("addWindow", "Виберіть вид :"))
        self.label_5.setText(_translate("addWindow", "Виберіть місце:"))
