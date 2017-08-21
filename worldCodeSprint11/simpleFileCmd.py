#!/usr/bin/python

trie = dict()
def createFile(filename):
    ls = list(filename)
    new_dict = trie
    ret_val = filename
    for j in range(len(ls)):
        if ls[j] in new_dict:
            new_dict = new_dict[ls[j]]
            if j==len(ls)-1:
                new_name = new_dict['next']
                if new_name==0:
                    new_dict['next'] += 1
                else:
                    voidshell = new_dict['void']
                    if len(voidshell)>0 and min(voidshell)<new_name:
                        new_name = min(voidshell)
                        new_dict['void'].remove(new_name)
                    else:
                        new_dict['next'] += 1
                    if new_name != 0:
                        ret_val += '('+str(new_name)+')'
        else:
            new_dict[ls[j]] = {'void':[],'next':0}
            new_dict = new_dict[ls[j]]
            if j==len(ls)-1:
                new_dict['next'] += 1
    return ret_val

def deleteFile(filename):
    ls = list(filename)
    appendedFile = False
    new_file_name = 0
    if ls[-1]==')':
        appendedFile = True
        init_val = -2;
        while(ls[init_val]!='('):
            init_val -= 1
        for i in range(init_val+1,-1):
            new_file_name = 10*new_file_name + int(ls[i])
        ls=ls[:init_val]
        
    new_dict = trie
    ret_val = filename
    for j in range(len(ls)):
        if ls[j] in new_dict:
            new_dict = new_dict[ls[j]]
            if j==len(ls)-1:
                if appendedFile:
                    new_dict['void'].append(new_file_name)
                else:
                    new_dict['void'].append(0)
                
    return ret_val


def run():
    tt = int(raw_input())
    for i in range(tt):
        inp = raw_input().strip().split()
        print_val=""
        if inp[0]=='crt':
            newfile = createFile(inp[1])
            print_val = print_val+"+ "+newfile
        elif inp[0]=='del':
            delfile=deleteFile(inp[1])
            print_val = print_val+"- "+delfile
        elif inp[0]=='rnm':
            delfile = deleteFile(inp[1])
            newfile = createFile(inp[2])
            print_val = 'r '+delfile+' -> '+newfile
        print print_val
        #print trie

        
if __name__ == '__main__':
    run()

