import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

data = pd.read_csv('C:/Users/ADMIN/Desktop/Code/data.csv') #Make changes to address of data.csv file if needed

x = data["Year"]
y_Average = data["Average"]

plt.plot(x,y_Average, 'ro')


plt.axis([min(x), max(x), min(y_Average)-10, max(y_Average)+10])
plt.xlabel('Year') 
plt.ylabel('Degree fahrenheit') 

plt.plot(np.unique(x), np.poly1d(np.polyfit(x,y_Average,1))(np.unique(x)), label='Average temperature plot')

plt.legend()
plt.show()
