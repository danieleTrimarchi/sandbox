import os 

'''Join a path. Uses python-style separators : "/". To be transformed for Windows into \\'''
def pathJoin( *args ) :

    ret = ""

    it = (x for x in args)
    for index, item in enumerate(it) :
        if index != 0 :
             ret+= "/"
        ret += item

    return ret


'''
Patch a given file : srcFileName using the function passed as an argument : replaceFunctor
replaceFunctor can be a function, lambda, or functor taking a line and returning the modified line
'''
def patchWithFunctor(replaceFunctor, srcFilePathName) :

    # open the srcFile
    fin = open(srcFilePathName, 'r')

    # open a tmp file and write
    tmpFileName = pathJoin(os.path.dirname(os.path.abspath(srcFilePathName)), "tmpFile")
    tmpFile = open(tmpFileName, 'w')

    # Process the lines of the src file and write the
    # results to the tmpFile
    for line in fin:
        tmpFile.write(replaceFunctor(line))

    # close both files
    tmpFile.close()
    fin.close()

    # Replace tmpFile with the srcFile
    #os.remove(srcFilePathName)
    #os.rename(tmpFileName, srcFilePathName)



#def replaceDebugToRelease(appFile):
#    import re
#    file = open(appFile, "r")
#    data = file.read()
#    file.close()
#    patternDebug = "(\s)to_debug transition((.)+)\n(\s+)condition value_boolean((.)+)\strue"
#    findDebug = re.search(patternDebug, data)
#    if findDebug is not None:
#        replaceDebug =  findDebug[1] + "to_debug transition"    + findDebug[2] + "\n" + \
#                        findDebug[4] + "condition value_boolean"+ findDebug[5] + " false"
#        data = re.sub(patternDebug, replaceDebug, data)
#        
#    patternRelease = "(\s)to_release transition((.)+)\n(\s+)condition value_boolean((.)+)\sfalse"
#    findRelease = re.search(patternRelease, data)
#    if findRelease is not None:
#        replaceRelease = findRelease[1] + "to_release transition"  + findRelease[2] + "\n" + \
#                         findRelease[4] + "condition value_boolean"+ findRelease[5] + " true"
#        data = re.sub(patternRelease, replaceRelease, data)
#    file = open("tmpFile.app", "w")
#    file.write(data)
#    file.close()
#
#replaceDebugToRelease("viewer.app")


# patch the Viewer to set the user algos autorun to true
def setCheckLicense(line):
    import re
    pattern = "(\s+)checkLicense\s((.)+)\sfalse"
    match = re.match(pattern, line)
    if match is not None:
        replace = match[1] + "checkLicense " + match[2] + " true"
        return re.sub(pattern, replace, line)
    return line
patchWithFunctor(setCheckLicense,"viewer.app" )

