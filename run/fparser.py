"""
    Runlang. A programming language that brings the ease of python to the speed to c++
    Copyright (C) 2023  Nuaym Syed

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

"""
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

def generate_tips(error):
    parse = error.split()
    tips = []
    if parse[0] == "expected":
        if len(parse) >2:
            if parse[2] == "before":
                tips.append(f"You might have forgotten to put a {parse[1]} before the {parse[3]}")
        else:
            tips.append(f"You might have forgotten to put a {parse[1]} ")

    elif parse[0] == "invalid":
        if parse[1] == "cast":
            tips.append("What happened is an invalid type conversion. The type you are converting to has no valid constructor for the type you are converting from. You can look at places (such as stackoverflow) in order to properly learn how to typecast the two types")
    return tips