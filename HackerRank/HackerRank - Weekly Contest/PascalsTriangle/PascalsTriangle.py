P=[[0 for x in range(31)]for y in range(31)];P[0][0]=P[1][0]=P[1][1]=1;s=""
for x in range(31):
    for y in range(x+1):
        if x>1: P[x][y]=P[x-1][y-1]+P[x-1][y]
        s+=str(P[x][y])+' '
    s+='\n'
print s