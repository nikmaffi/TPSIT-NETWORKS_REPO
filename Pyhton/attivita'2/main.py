from matplotlib import pyplot as plt
import csv

def readCSVs():
    CSVsData = [
        {
            'Year': [],
            'Total': [],
            'Gas Fuel': [],
            'Liquid Fuel': [],
            'Solid Fuel': [],
            'Cement': [],
            'Gas Flaring': [],
            'Per Capita': [],
        },

        {
            'Year': [],
            'Values': []
        }
    ]

    dataFile1 = open('./CO2_emissions.csv')
    dataReader1 = csv.reader(dataFile1, delimiter=',')
    next(dataReader1)
    for row in dataReader1:
        CSVsData[0]['Year'].append(int(row[0]))
        CSVsData[0]['Total'].append(float(row[1]))
        CSVsData[0]['Gas Fuel'].append(float(row[2]))
        CSVsData[0]['Liquid Fuel'].append(float(row[3]))
        CSVsData[0]['Solid Fuel'].append(float(row[4]))
        CSVsData[0]['Cement'].append(float(row[5]))
        CSVsData[0]['Gas Flaring'].append(float(row[6]))
        if row[7] != '':
            CSVsData[0]['Per Capita'].append(float(row[7]))
        else:
            CSVsData[0]['Per Capita'].append(0)

    dataFile2 = open('./Temperature_anomaly.csv')
    dataReader2 = csv.reader(dataFile2, delimiter=',')
    for i in range(5):
        next(dataReader2)
    for row in dataReader2:
        CSVsData[1]['Year'].append(int(row[0]))
        CSVsData[1]['Values'].append(float(row[1]))

    return CSVsData

def drawPlots(CSVsData):
    _, (axEmissions, axTemp) = plt.subplots(2, 1)

    x1 = CSVsData[0]['Year']
    y1A = CSVsData[0]['Total']
    y1B = CSVsData[0]['Gas Fuel']
    y1C = CSVsData[0]['Liquid Fuel']
    y1D = CSVsData[0]['Solid Fuel']
    y1E = CSVsData[0]['Cement']
    y1F = CSVsData[0]['Gas Flaring']
    y1G = CSVsData[0]['Per Capita']
    ################################
    x2 = CSVsData[1]['Year']
    y2 = CSVsData[1]['Values']

    axEmissions.plot(x1, y1A, '-b', label='Total')
    axEmissions.plot(x1, y1B, '-g', label='Gas Fuel')
    axEmissions.plot(x1, y1C, '-r', label='Liquid Fuel')
    axEmissions.plot(x1, y1D, '-c', label='Solid Fuel')
    axEmissions.plot(x1, y1E, '-m', label='Cement')
    axEmissions.plot(x1, y1F, '-y', label='Gas Flaring')
    axEmissions.plot(x1, y1G, '-k', label='Per Capita')
    #########################################################
    axTemp.plot(x2, y2, '-r', label='Temperatures Anomalies')

    axEmissions.set_xlabel('Years (y)')
    axEmissions.set_ylabel('CO2 Emissions (Mt)')
    ################################################
    axTemp.set_xlabel('Years (y)')
    axTemp.set_ylabel('Temperatures Anomalies (°C)')
    
    axEmissions.legend()
    ####################
    axTemp.legend()

    plt.show()

def main():
    drawPlots(readCSVs())

if __name__ == "__main__":
    main()