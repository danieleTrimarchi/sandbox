from synology_dsm import SynologyDSM

api = SynologyDSM("192.168.119.24", "5000", "Daniele", "bob*DAU5turs")


#print("=== Information ===")
#api.information.update()
#print("Model:           " + str(api.information.model))
#print("RAM:             " + str(api.information.ram) + " MB")
#print("Serial number:   " + str(api.information.serial))
#print("Temperature:     " + str(api.information.temperature) + " °C")
#print("Temp. warning:   " + str(api.information.temperature_warn))
#print("Uptime:          " + str(api.information.uptime))
#print("Full DSM version:" + str(api.information.version_string))
#print("--")#

#print("=== Utilisation ===")
#api.utilisation.update()
#print("CPU Load:        " + str(api.utilisation.cpu_total_load) + " %")
#print("Memory Use:      " + str(api.utilisation.memory_real_usage) + " %")
#print("Net Up:          " + str(api.utilisation.network_up()))
#print("Net Down:        " + str(api.utilisation.network_down()))
#print("--")#

#print("=== Storage ===")
#api.storage.update()
#for volume_id in api.storage.volumes_ids:
#    print("ID:          " + str(volume_id))
#    print("Status:      " + str(api.storage.volume_status(volume_id)))
#    print("% Used:      " + str(api.storage.volume_percentage_used(volume_id)) + " %")
#print("--")#

#for disk_id in api.storage.disks_ids:
#    print("ID:          " + str(disk_id))
#    print("Name:        " + str(api.storage.disk_name(disk_id)))
#    print("S-Status:    " + str(api.storage.disk_smart_status(disk_id)))
#    print("Status:      " + str(api.storage.disk_status(disk_id)))
#    print("Temp:        " + str(api.storage.disk_temp(disk_id)))
#print("--")#

print("=== Shared Folders ===")
api.share.update()
for share_uuid in api.share.shares_uuids:
    print("Share name:        " + str(api.share.share_name(share_uuid)))
    print("Share path:        " + str(api.share.share_path(share_uuid)))
    print("Space used:        " + str(api.share.share_size(share_uuid, human_readable=True)))
    print("Recycle Bin Enabled: " + str(api.share.share_recycle_bin(share_uuid)))



#if "SYNO.DownloadStation.Info" in api.apis:#
#    api.download_station.get_info()
#    api.download_station.get_config()

#    # The download list will be updated after each of the following functions:
#    # You should have the right on the (default) directory that the download will be saved, or you will get a 403 or 406 error
#    api.download_station.create("http://commondatastorage.googleapis.com/gtv-videos-bucket/sample/BigBuckBunny.mp4")
#    api.download_station.pause("dbid_1")
#    # Like the other function, you can eather pass a str or a list
#    api.download_station.resume(["dbid_1", "dbid_2"])
#    api.download_station.delete("dbid_3")

#    # Manual update
#    api.download_station.update()



