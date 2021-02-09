import subprocess 
import os 


'''Wraps a call to subprocess and the required diagnostics'''
def execute(command, myEnv=os.environ, wait=True,shell=True,detach=False):

    # This will spawn a new terminal and execute the cmd there
    if detach:
        command = "start " + command

    print("Executing cmd : {}".format(command))
    print("          pwd= ",os.getcwd())
    p = subprocess.Popen(command, shell=shell, env=myEnv)
    if wait and p.wait():
        raise ValueError('\n\nSomething went wrong when trying to execute: {}\n\n'.format(command))
    return p

# implemented for child classes, launch me!
def launch(cmdLineArgs="",wait=True,shell=True) :
    
    # Set the environment by hand
    execute(
    	"C:/ThirdPartyPackages/matlab_R2020a_f203ca4ee26419debd2707bca59a2780/bin/win64/matlab.exe {}".format(cmdLineArgs),
 		wait=wait,
        shell=shell)


matlabFileName= "createCascadeBindings.m"

fin = open(matlabFileName, 'w')
fin.write(r'''
disp("waiting 10 secs...")
pause(10)
exit''')
fin.close()

# Execute the script. This generates the bindings : Cascade_thunk_pcwin64.dll/.exp/.lib/.obj
# We only need the .dll
# Shell=False to make sure we control the lifespan of the process
launch(cmdLineArgs="-r run(\'{}\') -nojvm -nosplash".format(matlabFileName))

print("And now keep going!")

