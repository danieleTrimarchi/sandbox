import sys
from PySide2.QtWidgets import (QLineEdit, QPushButton, QApplication, QMessageBox,
                                   QHBoxLayout, QVBoxLayout, QGroupBox, QDialog, QDialogButtonBox,
                                   QLabel, QFileDialog, QComboBox,QCheckBox,QWidget,QFormLayout,
                               QTextEdit)
from PySide2.QtGui import QIcon,QPixmap
from PySide2.QtCore import QEvent
#
# app = QApplication(sys.argv)
# widget = QWidget()
# layout = QVBoxLayout()
# buttons = [QPushButton(str(x)) for x in range(5)]
#
# for i in buttons:
#     layout.addWidget(i)
# print("adding widgets")
#
# # def deleteButton():
# #     b = layout.takeAt(2)
# #     buttons.pop(2)
# #     del b
# # def deleteButton():
# #     b = layout.takeAt(2)
# #     buttons.pop(2)
# #     b.widget().deleteLater()
# def hideButton(checked = False):
#     print("hidebutton")
#     buttons[1].hide()
# buttons[1].clicked.connect(hideButton)
#
# def showButton(checked = False):
#     print("showbutton")
#     buttons[1].show()
# buttons[2].clicked.connect(showButton)
#
# widget.setLayout(layout)
# widget.show()
# app.exec_()

def char_range(c1, c2):
    """Generates the characters from `c1` to `c2`, inclusive."""
    for c in range(ord(c1), ord(c2)+1):
        yield chr(c)

class MainWindow(QWidget):

    def __init__(self):

        QWidget.__init__(self)

        self.layout= QVBoxLayout()
        self.setLayout(self.layout)

        self.__comboBox__ = QComboBox()
        self.__comboBox__.addItem("one")
        self.__comboBox__.addItem("two")
        self.layout.addWidget(self.__comboBox__)

        # --

        self.widget1=QWidget()
        self.layout.addWidget(self.widget1)

        self.vlayout1 = QVBoxLayout()
        self.widget1.setLayout(self.vlayout1)

        self.hlayout =  QHBoxLayout()
        self.buttons1 = [QPushButton(str(x)) for x in range(5)]
        for i in self.buttons1:
            self.hlayout.addWidget(i)

        self.vlayout1.addLayout(self.hlayout)

        # --

        self.widget2 = QWidget()
        self.layout.addWidget(self.widget2)

        self.vlayout2 = QVBoxLayout()
        self.widget2.setLayout(self.vlayout2)

        self.buttons2 = [QPushButton(str(x)) for x in char_range('a','e')]
        for i in self.buttons2:
            self.vlayout2.addWidget(i)

        # --

        self.__comboBox__.currentIndexChanged.connect(self.combobox_toggled)
        self.combobox_toggled(0)

        self.show()

    def combobox_toggled(self, index):
        # hide both not to loose space - we want the outer widget to be at the min possible size
        self.widget1.setVisible(False)
        self.widget2.setVisible(False)

        if index:
            self.widget1.setVisible(True)
        else:
            self.widget2.setVisible(True)

        self.adjustSize()

app=QApplication([])
mw=MainWindow()
app.exec_()

#
# class MainWindow(QWidget):
#     def __init__(self):
#         QWidget.__init__(self)
#
#         self.layout=QVBoxLayout()
#         self.setLayout(self.layout)
#
#         self.checkbox=QCheckBox("Layouts")
#         self.layout.addWidget(self.checkbox)
#
#         self.widget1=QWidget()
#         self.layout.addWidget(self.widget1)
#
#         self.layout1=QVBoxLayout()
#         self.widget1.setLayout(self.layout1)
#
#         self.layout1.addWidget(QLabel("First layout"))
#
#         self.layout1.addWidget(QTextEdit())
#
#         self.widget2=QWidget()
#         self.layout.addWidget(self.widget2)
#
#         self.layout2=QHBoxLayout()
#         self.widget2.setLayout(self.layout2)
#
#         self.layout2.addWidget(QTextEdit("Second layout"))
#
#         self.layout2.addWidget(QTextEdit())
#
#
#         self.checkbox.toggled.connect(self.checkbox_toggled)
#         self.checkbox.toggle()
#
#         self.show()
#
#     def checkbox_toggled(self, state):
#         self.widget1.setVisible(state)
#         self.widget2.setVisible(not state)
#
# app=QApplication([])
# mw=MainWindow()
# app.exec_()
