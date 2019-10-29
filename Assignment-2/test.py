import os
from os import listdir
import subprocess
from subprocess import call
import commands

program_files = ["P1/p1.cpp", "P2/p2.cpp", "P3/p3.cpp", "P4/p4.cpp", "P5/p5.cpp"]
# test_cases = os.listdir("P1/test")
# print test_cases
for i in range(0, 5) :
	subprocess.call("g++ " + program_file, shell=True)
	test_cases = os.listdir("P1/test")
	for f in test_cases :
		

