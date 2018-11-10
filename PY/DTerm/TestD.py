import os, sys
import fractions as fs
import numpy as np
import pprint as pr
import FunctionHolder as fh
import configparser as cpr


config = cpr.ConfigParser()

if not os.path.exists("test.ini"):
    config["PARTE1"] = {"TESTBOOL" : 1, "TESTVAR" : "19", "TESTSTRING" : "Hola!"} 

    with open("test.ini", "w") as configfile:
        config.write(configfile)


config.read("test.ini")
print (config.sections())

config["PARTE1"]["TESTBOOL"] = "5"
print(config["PARTE1"]["TESTBOOL"])

with open("test.ini", "w") as configfile:
    config.write(configfile)

print(config["PARTE1"]["TESTVAR"])