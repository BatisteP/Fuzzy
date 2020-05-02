import pandas as pd
import matplotlib . pyplot as plt
dfm = pd.read_csv ('../../bin/mamdaniResult.csv ', header =0)
print (dfm)

x,y= dfm.iloc[:,0],dfm.iloc[:,1]
plt.title("mamdani Result before defuzzification")
plt . scatter (x, y , cmap ='rainbow')
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )

dfp = pd.read_csv ('../../bin/poorGaussian.csv ', header =0)

x,y= dfp.iloc[:,0],dfp.iloc[:,1]
plt . scatter (x, y , cmap ='rainbow')
plt.title("service is poor")
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )

dfe = pd.read_csv ('../../bin/excellentGaussian.csv ', header =0)

x,y= dfe.iloc[:,0],dfe.iloc[:,1]
plt . scatter (x, y , cmap ='rainbow')
plt.title("service is excellent")
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )

dfg = pd.read_csv ('../../bin/goodGaussian.csv ', header =0)

x,y= dfg.iloc[:,0],dfg.iloc[:,1]
plt . scatter (x, y , cmap ='rainbow')
plt.title("service is good")
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )

dfd = pd.read_csv ('../../bin/delicious.csv ', header =0)

x,y= dfd.iloc[:,0],dfd.iloc[:,1]
plt . scatter (x, y , cmap ='rainbow')
plt.title("food is delicious")
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )

dfd = pd.read_csv ('../../bin/rancid.csv ', header =0)

x,y= dfd.iloc[:,0],dfd.iloc[:,1]
plt . scatter (x, y , cmap ='rainbow')
plt.title("food is rancid")
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )

dfcheap = pd.read_csv ('../../bin/cheap.csv ', header =0)
print (dfcheap)
x,y= dfcheap.iloc[:,0],dfcheap.iloc[:,1]
plt . scatter (x, y , cmap ='rainbow')
plt.title("tip = cheap")
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )

dfgenerous = pd.read_csv ('../../bin/generous.csv ', header =0)
print (dfgenerous)
x,y= dfgenerous.iloc[:,0],dfgenerous.iloc[:,1]
plt . scatter (x, y , cmap ='rainbow')
plt.title("tip = generous")
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )

dfav = pd.read_csv ('../../bin/average.csv ', header =0)
print (dfav)
x,y= dfav.iloc[:,0],dfav.iloc[:,1]
plt . scatter (x, y , cmap ='rainbow')
plt.title("tip = average")
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )