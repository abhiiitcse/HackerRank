#!/usr/bin/env python

import requests
import urllib
import re
from BeautifulSoup import BeautifulSoup

url1 = "http://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/infinite/"
response = requests.get(url1+'qds.html')
# parse html
page = str(BeautifulSoup(response.content))

def getSecretQuote(page):
    pass

def getURL(page):
    """

    :param page: html of web page (here: Python home page) 
    :return: urls in that page 
    """
    start_link = page.find("a href")
    if start_link == -1:
        return None, 0
    start_quote = page.find('"', start_link)
    end_quote = page.find('"', start_quote + 1)
    url = page[start_quote + 1: end_quote]
    return url, end_quote
ans = []
with open('ques3_ans.txt') as f:
    str1 = f.readlines()
    for str2 in str1:
        ans.append(str2.strip('\n'))
print ans
print len(ans)
ans.sort()
for str1 in ans:
    print str(str1)
input()
#tot_url=['qds.html', 'flhxd.html', 'eesjd.html', 'auspzk.html', 'oipauj.html', 'mcx.html', 'cvehb.html', 'tds.html', 'sevt.html', 'pkaza.html', 'nsj.html', 'zsuqwbi.html', 'mtoiz.html', 'dywfnxj.html', 'nhho.html', 'uliqos.html', 'qtyp.html', 'bbbtkix.html', 'brra.html', 'fohh.html', 'zdhref.html', 'ebf.html', 'qwa.html', 'vzo.html', 'cgrfpr.html', 'cjujsxu.html', 'rfwqhl.html', 'edrmzk.html', 'boqg.html', 'hjckse.html', 'hatgfp.html', 'gtv.html', 'minqwf.html', 'fmzxgu.html', 'bjqnxb.html', 'qlledj.html', 'mjcgs.html', 'yrsuugo.html', 'qsgzh.html', 'cmqbeew.html', 'rxwyw.html', 'huo.html', 'tlithpn.html', 'fitnwvs.html', 'khbppud.html', 'qmsfi.html', 'hoqvva.html', 'hgxnt.html', 'gaxma.html', 'fybrotn.html', 'bfm.html', 'hfel.html', 'bga.html', 'qoxi.html', 'erkpr.html', 'esx.html', 'xealylo.html', 'qsbl.html', 'byqzexy.html', 'set.html', 'gumsjbi.html', 'gsocp.html', 'ewgfxa.html', 'spv.html', 'bwrwxvw.html', 'frahk.html', 'ofp.html', 'yybarth.html', 'zeaj.html', 'coara.html', 'mmp.html', 'gatft.html', 'kpsgbkt.html', 'tasdsml.html', 'kaypuar.html']
tot_url=['qoxi.html', 'erkpr.html', 'esx.html', 'xealylo.html', 'qsbl.html', 'byqzexy.html', 'set.html', 'gumsjbi.html', 'gsocp.html', 'ewgfxa.html', 'spv.html', 'bwrwxvw.html', 'frahk.html', 'ofp.html', 'yybarth.html', 'zeaj.html', 'coara.html', 'mmp.html', 'gatft.html', 'kpsgbkt.html', 'tasdsml.html', 'kaypuar.html']
a=[]
for i in range(len(tot_url)):
    a.append(url1+tot_url[i])

for i in range(len(tot_url)):
    #f = urllib.urlopen(a[i])
    #s = f.read()
    #print s
    response = requests.get(a[i])
    page = BeautifulSoup(response.content)
    #print page
    test = page.findAll(text = re.compile('Secret Phrase:'))
    print "parsed",tot_url[i]
    if len(test)>0:
        print "yes"
        print str(page)
    else:
        print "no"
        #print test
    #raw_input()

#while len(a)>0:
#    temp_url = a.pop()
#    print "temp_url=",temp_url," len=",len(a)
#    response = requests.get(temp_url)
#    page = str(BeautifulSoup(response.content))
#    while True:
#        url, n = getURL(page)
#        page = page[n:]
#        if url:
#            #print url
#            if url not in tot_url:
#                tot_url.append(url)
#                print "tot=",tot_url
#                print "not in",url
#                a.append(url1+url)
#        else:
#            break
# 
#print "tot_url=",tot_url
