strconv = "(rsl::string) "

def replaceStr(y):
    h = y
    instr = True
    i = 0
    while (i < len(y)):
        x = y[i]
        if x == '"':
            instr = not instr
            if (not instr):
                h = h[:i] + strconv + h[i:]
                i+=len(strconv) 
        i+=1
    return h