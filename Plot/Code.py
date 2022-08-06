import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('C:/Users/ADMIN/Desktop/Code/data.csv') #Make changes to address of data.csv file if needed

x = data["Year"]
y_Average = data["Average"]
plt.plot(x,y_Average, 'ro')


plt.axis([min(x), max(x), min(y_Average)-10, max(y_Average)+10])
plt.xlabel('Year') 
plt.ylabel('Degree fahrenheit') 

plt.plot([1878,2022], [56.6059, 62.343], label='Average temperature')

plt.legend()
plt.show()
