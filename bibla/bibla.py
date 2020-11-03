import sqlite3
from PyQt5 import QtWidgets
import menu
import add
import delwin
import red
import search
import sys


conn = sqlite3.connect("mydatabase.db")
cursor = conn.cursor()
cursor.execute("""CREATE TABLE IF NOT EXISTS bibl
                  (avtor text, vidanna text,
                   janr text, vid text, place text)
               """)

class addWindow(QtWidgets.QMainWindow, add.Ui_addWindow):
        def __init__(self):
            super().__init__()
            self.setupUi(self)
            self.pushButton.clicked.connect(self.returny)
            self.add.clicked.connect(self.on_click)

        def returny(self):
            self.close()
            self.twoWindow = MainWind()
            self.twoWindow.show()
 
        def on_click(self):
            vidanna = self.lineEdit_2.text()
            avtor = self.lineEdit.text()
            janr = self.lineEdit_3.text()
            vid = self.lineEdit_4.text()
            place = self.lineEdit_5.text()
            values = (avtor, vidanna, janr, vid, place)
            cursor.executemany("INSERT INTO bibl VALUES(?, ?, ?, ?, ?)", (values,))
            conn.commit()

            
 

class delWindow(QtWidgets.QMainWindow, delwin.Ui_delWindow):
        def __init__(self):
            super().__init__()
            self.setupUi(self)
            self.pushButton.clicked.connect(self.returny)
            self.add.clicked.connect(self.on_click)

        def returny(self):
            self.close()
            self.twoWindow = MainWind()
            self.twoWindow.show()
        
        def on_click(self):
            vidanna = self.lineEdit_2.text()
            if vidanna:
                cursor.execute("DELETE FROM bibl WHERE vidanna = '%s'" % vidanna
            )
            avtor = self.lineEdit.text()
            if avtor:
                cursor.execute("DELETE FROM bibl WHERE avtor = '%s'" % avtor
            )
            janr = self.lineEdit_3.text()
            if janr:
                cursor.execute("DELETE FROM bibl WHERE janr = '%s'" % janr
            )
            vid = self.lineEdit_4.text()
            if vid:
                cursor.execute("DELETE FROM bibl WHERE vid = '%s'" % vid
            )
            place = self.lineEdit_5.text()
            if place:
                cursor.execute("DELETE FROM bibl WHERE place = '%s'" % place
            )
            conn.commit()


class redWindow(QtWidgets.QMainWindow, red.Ui_redWindow):
        def __init__(self):
            super().__init__()
            self.setupUi(self)
            self.pushButton.clicked.connect(self.returny)
        
        def returny(self):
            self.close()
            self.twoWindow = MainWind()
            self.twoWindow.show()

        def on_click(self):
            vidanna = self.lineEdit_2.text()
            avtor = self.lineEdit.text()
            janr = self.lineEdit_3.text()
            vid = self.lineEdit_4.text()
            place = self.lineEdit_5.text()
            revidanna = self.lineEdit_7.text()
            reavtor = self.lineEdit6.text()
            rejanr = self.lineEdit_8.text()
            revid = self.lineEdit_9.text()
            replace = self.lineEdit_10.text() 
            if avtor:
                cursor.execute("""
                                UPDATE bibl 
                                SET avtor = '%s' 
                                WHERE avtor = '%s'
                                """ % (avtor, reavtor))
            
            if vidanna :
                cursor.execute("""
                                UPDATE bibl 
                                SET vidanna = '%s' 
                                WHERE vidanna = '%s'
                                """ % (vidanna, revidanna))

            if janr :
                cursor.execute("""
                                UPDATE bibl 
                                SET janr = '%s' 
                                WHERE janr = '%s'
                                """ % (janr, rejanr))
            if vid :
                cursor.execute("""
                                UPDATE bibl 
                                SET vid = '%s' 
                                WHERE vid = '%s'
                                """ % (vid, revid))

            if place :
                cursor.execute("""
                                UPDATE bibl 
                                SET place = '%s' 
                                WHERE place = '%s'
                                """ % (place, replace))


class searchWindow(QtWidgets.QMainWindow, search.Ui_MainWindow):
        def __init__(self):
            super().__init__()
            self.setupUi(self)
            self.pushButton_2.clicked.connect(self.returny)
            self.add.clicked.connect(self.on_click)
        
        def returny(self):
            self.close()
            self.twoWindow = MainWind()
            self.twoWindow.show()

        def on_click(self):
            text = self.lineEdit.text()
            listy = []
            cursor.execute("SELECT * FROM bibl where avtor='%s'" % text)
            need = list(cursor.fetchall()[0])
            needval = ','.join(need)
            listy.append(needval)
            for file_name in listy: 
                self.listWidget.addItem(file_name)


class MainWind(QtWidgets.QMainWindow, menu.Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.addButton.clicked.connect(self.addWin)
        self.redButton.clicked.connect(self.reddWin)
        self.searchButton.clicked.connect(self.searchWin)
        self.deleteButton.clicked.connect(self.delWin)

    def addWin(self):
        self.close()
        self.twoWindow = addWindow()
        self.twoWindow.show()

    def reddWin(self):
        self.close()
        self.twoWindow = redWindow()
        self.twoWindow.show()

    def searchWin(self):
        self.close()
        self.twoWindow = searchWindow()
        self.twoWindow.show()

    def delWin(self):
        self.close()
        self.twoWindow = delWindow()
        self.twoWindow.show()
        

def main():
    app = QtWidgets.QApplication(sys.argv)
    window = MainWind()
    window.show()
    app.exec_()
    cursor.close()





if __name__ == '__main__':
    main() 