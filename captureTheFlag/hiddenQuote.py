import urllib
import string
first_str = string.lowercase[:]
second_str = string.uppercase[:]
url='https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/secret_json/'
tot =0
for ch in first_str:
    new_str = url+ch
    for ch1 in first_str:
        new_str1 = new_str+ch1
        for ch2 in first_str:
            new_str2 = new_str1+ch2
            f = urllib.urlopen(new_str2+'.json')
            s = f.read().strip()
            if len(s)>0:
                if s[0]=='{':
                    print "yes"
                    print new_str2
                    tot+=1

print "end"
print "tot=",tot

