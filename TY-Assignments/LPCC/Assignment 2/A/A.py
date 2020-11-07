
fileName = "assembly-code.txt"
currentMacro =""
macroFound = False
macroDefinition = False
MDT = {}
MNT = {}
file = open(fileName)
for line in file:
	newLine = line.replace("\n", "")
	if newLine == "MACRO":
		macroFound = True
		continue
	if macroFound and not macroDefinition:
		name = newLine.split(" ")
		MDT[name[0]] = []
		MNT[name[0]] = [param.replace(",", " ") for param in name[1:]]
		currentMacro = name[0]
		macroDefinition = True
		continue
	if macroFound and macroDefinition:
		MDT[currentMacro].append(newLine)
	if newLine == "MEND":
		macroDefinition = False
		macroFound = False
		currentMacro = ""

print(MDT)
print(MNT)
