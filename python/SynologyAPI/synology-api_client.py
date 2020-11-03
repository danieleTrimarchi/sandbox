from shutil import move
import os 
from synology_api import filestation, downloadstation
fl = filestation.FileStation("192.168.119.24", "5000", "Daniele", "bob*DAU5turs")

print(fl.get_info())

#print(fl.get_list_share())
#for iShared in fl.get_list_share()['data']['shares']:
#	print("iShared :", iShared)
#	print(fl.get_file_list(iShared['path']))

#fl.get_file(path='/ThirdPartyPackages/KeyLock/KeyLock_cce909dc02729857df1c408401492288.zip', mode=r'download')
#fl.create_folder(folder_path = '/ThirdPartyPackages', name='testFolder')
#print(fl.get_file_info(path='/ThirdPartyPackages/testFolder/testFile.txt'))
#print(fl.get_file_list(folder_path='/ThirdPartyPackages/vtk_8_2a_git'))

def ls(remote_path) : 
	try: 

		fileList = []
		folderList = []
		allList = fl.get_file_list(folder_path=remote_path) 
		for i in allList['data']['files']: 
			if i['isdir'] :
				folderList.append(i['name']) 
			else : 
				fileList.append(i['name']) 

		d = {'files': fileList, 'folders' : folderList}
		print(d)
		return d

	except : 
		print("Path: \""+remote_path+"\" not found.")
		return {}
#ls('/homes')


def upload_file(local_file_path, remote_dest_path) : 
	if(len(ls(remote_dest_path))):
		fl.upload_file(remote_dest_path, local_file_path)
#upload_file('testFolderFromLocal/testFileFromLocal.txt','/ThirdPartyPackages/testFolderFromLocal')

def create_folder(remote_folder_path, remote_folder_name): 
	fl.create_folder(remote_folder_path, remote_folder_name)
#create_folder('/ThirdPartyPackages', 'testFolder') 	
#create_folder('/ThirdPartyPackages/testFolder', 'testFolder2') 	

def upload_folder(local_file_path, remote_dest_path): 
	for dirpath, dirs, files in os.walk(local_file_path):
		fixDirPath = dirpath.replace("\\","/")
		#print("creating remote folder : ", remote_dest_path + "/" + fixDirPath)
		create_folder(remote_dest_path, fixDirPath)
		for iFile in files : 
			print(	"sending local file : ", fixDirPath + "/" + iFile, " to : ", remote_dest_path + "/" + fixDirPath ) 
			upload_file(fixDirPath + "/" + iFile, remote_dest_path + "/" + fixDirPath ) 
#upload_folder('testFolderFromLocal', '/ThirdPartyPackages') 	

def delete(remote_dest_path): 
	if not len(ls(remote_dest_path)):
		return
	print(fl.start_delete_task(remote_dest_path))
	print(fl.get_delete_status(fl._delete_taskid))
delete('/ThirdPartyPackages/testFolderFromLocal') 
#delete('/ThirdPartyPackages/testFileFromNAS.txt') 


def download_file(RemoteFileAbsPath): 
	fl.get_file(fileAbsPath,'download')
#download_file('/ThirdPartyPackages/testFileFromNAS.txt') 

def download_folder(RemoteFileAbsPath, localDst): 

	if not os.path.isdir(localDst) : 
		os.mkdir(localDst)

	for iFile in fl.get_file_list(fileAbsPath)['data']['files']:
		if not(iFile['isdir']):
			print('downloading ', fileAbsPath + '/' + iFile['name'])
			download_file(fileAbsPath + '/' + iFile['name'])
			move(iFile['name'],localDst+"/"+iFile['name'])
		else:
			print('downloading folder', fileAbsPath + '/' + iFile['name'])
			download_folder(fileAbsPath + '/' + iFile['name'], localDst + '/' + iFile['name'])
#download_folder('/ThirdPartyPackages/testFolderFromNAS', 'testFolderFromNAS')
