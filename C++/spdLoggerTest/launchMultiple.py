import os, subprocess, re

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


execute("Build\\Debug\\test.exe.exe log1",wait=False) 

