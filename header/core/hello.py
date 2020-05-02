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

dfpoor = pd.read_csv ('../../bin/cheap.csv ', header =0)
print (dfpoor)
x,y= dfpoor.iloc[:,0],dfpoor.iloc[:,1]
plt . scatter (x, y , cmap ='rainbow')
plt.title("service : cheap")
plt.xlabel('x')
plt.ylabel('y')
plt . show ( )


