import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

s = smtplib.SMTP('smtp.gmail.com',587)
s.starttls()

# Note : login requires gmail to accept to be accessed via this interface. 
# Manage your account 
# 	Security
#		Secure account
#			ThirdParty access  
#				turn on the 'less secure app access'
s.login("nasiconeus@gmail.com",input("Please enter the password"))

msg = MIMEMultipart()

msg['From'] = "nasiconeus@gmail.com"
msg['To'] = "daniele.trimarchi@iconeus.com"
msg['Subject'] = "test email from Python"

msg.attach(MIMEText("Text of the test email from Python"))

s.send_message(msg)