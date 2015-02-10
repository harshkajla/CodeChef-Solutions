x = raw_input().split()
if int(x[0])%5!=0 or float(int(x[0])+0.5) > float(x[1]):
	print x[1]
else:
	print float(x[1])-int(x[0])-0.5
