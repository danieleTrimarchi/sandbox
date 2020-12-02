from PySide2.QtWidgets import (QLineEdit, QPushButton, QApplication, QMessageBox,
                                   QVBoxLayout, QGroupBox, QHBoxLayout, QDialog, QDialogButtonBox,
                                   QLabel, QFileDialog,QComboBox,QWidget)
from PySide2.QtGui import QIcon,QPixmap
from PySide2.QtCore import QEvent
import sys

print("hello, wordl!")


class Form(QDialog):

    def __init__(self, parent=None):
        super(Form, self).__init__(parent)
        self.setWindowTitle("My Form")


if __name__ == '__main__':
    # Create the Qt Application
    app = QApplication(sys.argv)
    # Create and show the form
    form = Form()
    form.show()
    # Run the main Qt loop
    sys.exit(app.exec_())