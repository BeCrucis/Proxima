import openpyxl 

excelWB = openpyxl.load_workbook("Datos i1.xlsx")
excelWS = excelWB.active

STARTROW = 5
STARTCOLUMN = 6
DATASIZE = 5

class RR():
    
    startRow = STARTROW
    startColumn = STARTCOLUMN
    finishRow = STARTROW + 4
    finishColumn = STARTCOLUMN + 2*(DATASIZE-1) + 1

    def __init__(self):

        equiLines = {}

        rowIndex = RR.startRow
        
        for row in excelWS.iter_rows(RR.startRow, RR.finishRow, RR.startColumn, RR.finishColumn):
            coords = []
            voltage = int(excelWS.cell(rowIndex, RR.startColumn-1).value)
            equiLines[voltage] = []
            rowIndex += 1 

            cellindex = 0
            for x,y in zip(row[::2], row[1::2]):

                equiLines[voltage].append((round(x.value,4),round(y.value,4)))
        
        self.equiLines = equiLines

        for line in equiLines:
            print(F"{line} : {equiLines[line]}")

class RC():
    
    startRow = STARTROW + 5
    startColumn = STARTCOLUMN
    finishRow = STARTROW + 4 + 5
    finishColumn = STARTCOLUMN + 2*(DATASIZE-1) + 1

    def __init__(self):

        equiLines = {}

        rowIndex = RC.startRow
        
        for row in excelWS.iter_rows(RC.startRow, RC.finishRow, RC.startColumn, RC.finishColumn):
            coords = []
            voltage = int(excelWS.cell(rowIndex, RC.startColumn-1).value)
            equiLines[voltage] = []
            rowIndex += 1 

            cellindex = 0
            for x,y in zip(row[::2], row[1::2]):

                equiLines[voltage].append((round(x.value,4),round(y.value,4)))
        
        self.equiLines = equiLines
        
        for line in equiLines:
            print(F"{line} : {equiLines[line]}")

class CC():
    
    startRow = STARTROW + 5 + 5
    startColumn = STARTCOLUMN
    finishRow = STARTROW + 5 + 5 + 2
    finishColumn = STARTCOLUMN + 2*(DATASIZE-1) + 1

    def __init__(self):

        equiLines = {}

        rowIndex = CC.startRow
        
        for row in excelWS.iter_rows(CC.startRow, CC.finishRow, CC.startColumn, CC.finishColumn):
            coords = []
            voltage = int(excelWS.cell(rowIndex, CC.startColumn-1).value)
            equiLines[voltage] = []
            rowIndex += 1 

            cellindex = 0
            for x,y in zip(row[::2], row[1::2]):

                equiLines[voltage].append((round(x.value,4),round(y.value,4)))
        
        self.equiLines = equiLines
        
        for line in equiLines:
            print(F"{line} : {equiLines[line]}")

if __name__ == "__main__":
    RR()