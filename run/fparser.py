strconv = "(rsl::string) "

def replaceStr(y):
    h = y
    instr = True
    i = 0
    for x in h:
        l = h[0]
        if l == '"':
            instr = not instr
            if (instr):
                h.replace(i,1,strconv + "\"")
                i+=len(strconv) 
    
    return h