
fileName = "assembly-code.txt"
currentMacro = []
macroFound = False
macroDefinition = False
MDT = {}
MNT = {}
file = open(fileName)
for line in file:
	newLine = line.replace("\n", "")
	if newLine == "MACRO":
		macroFound = True
		macroDefinition = False
		continue
	if macroFound:
		name = newLine.split(" ")
		MDT[name[0]] = []
		MNT[name[0]] = [param.replace(",", " ") for param in name[1:]]
		currentMacro.append(name[0])
		macroFound = False
		continue
	if len(currentMacro) != 0:
		MDT[currentMacro[-1]].append(newLine)
	if newLine == "MEND":
		currentMacro.pop(-1)

print(MDT)
print(MNT)
