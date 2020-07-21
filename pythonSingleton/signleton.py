class fakeNasClient:

    thirdPartySrcFolder_OnNAS = "iconeus/ThirdPartySources"
    # Path of the third party packages on the NAS
    thirdPartyPkgFolder_OnNAS = "iconeus/ThirdPartyPackages"
    # Path of the distribution software packages on the NAS
    softwareBuildsFolder_OnNAS = "iconeus/SoftwareBuilds"
    # Path of the Test_data folder on the NAS
    testDataFolder_OnNAS = "iconeus/Test_data"

    class __fakeNasClient:
        def __init__(self, arg):
            self.val = arg

    _instance = None
    
    def __init__(self, arg):
    
        if not fakeNasClient._instance:
            print ("== Instantiating new _instance...")
            fakeNasClient._instance = fakeNasClient.__fakeNasClient(arg)
        else:
            print ("=== NOT instantiating new _instance...")
            fakeNasClient._instance.val = arg
            
#    def __getattr__(self, name):
#        return getattr(self._instance, name)
   

x = fakeNasClient('foo')
y = fakeNasClient('eggs')

