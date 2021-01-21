from shutil import move
import os 

# disable the unsecure request warning: 
# C:\Users\danie\AppData\Local\Programs\Python\Python38\lib\site-packages\urllib3\connectionpool.py:997: 
# InsecureRequestWarning: Unverified HTTPS request is being made to host '10.37.0.103'. 
# Adding certificate verification is strongly advised. 
# See: https://urllib3.readthedocs.io/en/latest/advanced-usage.html#ssl-warnings
from requests.packages import urllib3
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

from synology_api import filestation, downloadstation
fl = filestation.FileStation("10.37.0.103", "5001", "Daniele", "Dan21Maggio82#", secure=True)

#fl.get_file(path="/Shared/errorNS.png", mode="download", chunkSize=None)
#fl.get_file(path="/Shared/errorNS.png", mode="download", chunkSize=None, dest_path="outDir/outDir2")
fl.get_file(path="/Shared/errorNS.png", mode="download", chunk_size=None, dest_path="C:/sandbox/python/SynologyAPI/absoutDir")
