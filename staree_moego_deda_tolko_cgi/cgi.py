#!/usr/bin/python

import cgi, cgitb 

form = cgi.FieldStorage() 

len_arr = form.getvalue('len_arr')
first_arr = form.getvalue('first_arr')
second_arr  = form.getvalue('second_arr')

th_arr = sum(p*q for p,q in zip(first_arr, second_arr))
print ("Content-type:text/html\r\n\r\n")
print ("<html>")
print ("<head>")
print ("<title>Hello - This skalar array Program</title>")
print ("</head>")
print ("<body>")
print ("<h2>First arr %s</h2>" % (first_arr))
print ("<h2>Second arr %s</h2>" % (second_arr))
print ("<h2>Sum arr %s</h2>" % (th_arr))
print ("</body>")
print ("</html>")