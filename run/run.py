import sys
import os
import subprocess
import fparser

file = ""
debug = False
convertrsl = True

def sdebug(e):
    global debug
    if debug:
        print("\33[33m(DEBUG) " + e + "\033[0m\n")

def error(e,acterror = False,file = "",line: int = 0, linedata = "",prevline = "",nextline = "", tips = None):
    if not acterror:
        print("\033[91m(ERROR) " + e + "\nCompilation terminated\033[0m")
        sys.exit()
    print(f"\033[91m(ERROR)\n{file} on line: {line} \n\33[33m{line-1}| {prevline} \n\33[31m{line}| {linedata} \n\33[33m{line+1}| {nextline} \n{e}\033[0m")
    if tips:
        print(f"\33[4mTips: \n{tips}\033[0m\n")

commands = 0
compiler = ""
e = sys.argv[1:]
addsemicolon = True

i = 0
outname = ""
for item in e:
    if item.startswith("--"):
        if item == "--debug":
            debug = True
        elif item == "--NoConvert":
            convertrsl = False
        elif item == "--noAddSemicolon":
            addsemicolon = False
        else:
            error("No knowm configuration, called: " + item)
    elif item.startswith("-"):
        if item == "-o":
            """"""
            try:
                outname = e[i+1]
                if os.name == 'nt':
                    outname += ".exe"
                e.pop(i+1)
                
            except:
                error("Output name not entered")
        else:
            error("No none configuration: " + item)
    else:
        if commands > 1:
            error("To many commands")
        commands += 1
        file = item
    i += 1
        
if commands ==0:
    error("No input file entered.")
del commands
del i

sdebug("Arguments follow: " + str(e))

if not os.path.exists(os.path.abspath(file)):
    error("Cannot find file: " + os.path.abspath(file))

if not file.endswith(".run"):
    error("Invalid file")

if outname == "":
    outname = file[:-4]

fpath = os.path.abspath(file)

fpath = fpath[:-len(file)]

sdebug("Filepath is: " + fpath)

sdebug("Reading from file: " + fpath + file)

data = []
f = open(fpath + file, "r")

for x in f:
    data.append(x)

f.close()
del f

sdebug("Processing file...")

fwrite = []

for x in data:
    write = x.rstrip()
    if convertrsl:
        write = fparser.replaceStr(write)
    if addsemicolon:
        write += ";"
    write += "\n"
    fwrite.append(write)

filetowrite = file[:-4]
filetowrite += ".cpp"

filetowrite = fpath + ".__RUNCACHE__" + filetowrite

sdebug("Writing to file: " + filetowrite)

try:
    os.remove(filetowrite)
except:
    """"""

f = open(filetowrite, "w")

cachePath = os.path.dirname(os.path.abspath(__file__))
cachePath = cachePath.replace("\\","/")

f.write("#include \""+ cachePath + "/rsl/rsl.h" + "\"\n")

for x in fwrite:
    f.write(x)

f.close()

if os.name == 'nt' and not debug:
    subprocess.check_call(["attrib","+H",filetowrite])

sdebug("Detecting Compiler..")
if compiler == "":
    try:
        proc = subprocess.run(
            ["cl"],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        compiler = "cl"
    except:
        try:
            proc = subprocess.run(
                ["g++"],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )
            compiler = "g++"
        except:
            try:
                proc = subprocess.run(
                ["clang++"],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
                )
            except:
                error("No compiler found on system. ")

sdebug("Compiler detected: " + compiler)

sdebug("Compiling!")

if compiler == "cl":
    proc = subprocess.run(
        ["cl",filetowrite,"/EHsc","/std:c++20","/link","/out:" + outname],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    objfile = filetowrite.split("\\")
    objfile = objfile[len(objfile) - 1]
    objfile = objfile[:-4] + ".obj"
    if not proc.stdout.rstrip().endswith(objfile):
        ferror = proc.stdout.split("\n")
        i = 0
        try:
            for item in ferror:
                if i == 0:
                    i+=1
                    pass
                line = item.split("(")[1]
                line = int(item.split(")")[0])
                efile = item.split("(")[0]
                error =item.split(":",1)[1]
                if efile == filetowrite:
                    """"""
                    prevline = "Placeholder"
                    nextline = "Placeholder"
                    linedata = "Placholder"
                    line -=1
                    if line ==1:
                        """"""
                        prevline = ""
                    elif line == len(data):
                        """"""
                    
                else:
                    """"""
                i+=1
        except:
            error(proc.stdout)

elif compiler == "g++":
    proc = subprocess.run(
        ["g++","-std=c++20","-o", outname, filetowrite],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    sdebug(" ".join(["g++","-std=c++20","-o", outname, filetowrite]))
    if proc.stderr != "":
        error(proc.stderr)
if not debug:
    os.remove(filetowrite)
    if compiler == "cl":
        try:
            os.remove(filetowrite[:-4] + ".obj")
        except:
            """Do nothing"""