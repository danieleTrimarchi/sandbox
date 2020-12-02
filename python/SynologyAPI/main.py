from shutil import move
import os 
from synology_api import filestation, downloadstation
fl = filestation.FileStation("192.168.119.24", "5000", "Daniele", "Dan21Maggio82#")

#fl.get_file(path="/Shared/errorNS.png", mode="download", chunkSize=None)
#fl.get_file(path="/Shared/errorNS.png", mode="download", chunkSize=None, dest_path="outDir/outDir2")
fl.get_file(path="/Shared/errorNS.png", mode="download", chunkSize=None, dest_path="C:/sandbox/python/SynologyAPI/absoutDir")
