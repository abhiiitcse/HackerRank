from urllib2 import urlopen
import re

urlpath =urlopen('https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/secret_json')
string = urlpath.read().decode('utf-8')

pattern = re.compile('[A-Za-z0-9]*.json')

filelist = pattern.findall(string)
print(filelist)

for filename in filelist:
    filename=filename[:-1]
    remotefile = urlopen('https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/secret_json/' + filename)
    localfile = open(filename,'wb')
    localfile.write(remotefile.read())
    localfile.close()
    remotefile.close()
