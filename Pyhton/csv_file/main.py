import sys


def anomalies(data, year1, year2):
    maximum = -1 * sys.float_info.max
    minimum = sys.float_info.max
    maxYear = 0
    minYear = 0

    if year1 < int(data[-1]["year"]) or year1 > int(data[0]["year"]):
        return f"Year {year1} not found!"
    elif year2 < int(data[-1]["year"]) or year2 > int(data[0]["year"]):
        return f"Year {year2} not found!"
    elif year1 > year2:
        return "year1 must be less than year2"

    for y in data:
        if float(y["year"]) >= year1 and float(y["year"]) <= year2:
            if(float(y["average"]) > maximum):
                maximum = float(y["average"])
                maxYear = int(y["year"])
            
            if(float(y["average"]) < minimum):
                minimum = float(y["average"])
                minYear = int(y["year"])

    return [{"max" : maximum, "year" : maxYear}, {"min" : minimum, "year" : minYear}]


def calculateAverage(data):
    dataAvg = []
    currentYear = int(data[0]["year"])
    som = 0
    cnt = 0

    for el in data:
        if el["year"] != str(currentYear):
            dataAvg.append({
                "year" : currentYear,
                "average" : som/cnt
            })

            currentYear -= 1
            som = 0
            cnt = 0

        som += float(el["mean"].split("\n")[0])
        cnt += 1

    dataAvg.append({
        "year"    : currentYear,
        "average" : som/cnt
    })

    return dataAvg


def readFile(path):
    data = []

    with open(path, "r") as file:
        for idx, line in enumerate(file):
            if idx > 0:
                data.append({
                    "source" : line.split(",")[0],
                    "year"   : line.split(",")[1],
                    "mean"   : line.split(",")[2]
                })

    return data


def main():
    data = readFile("ES10-/annual.csv")
    data = calculateAverage(data)

    print("AVERAGES:")
    for y in data:
        print(y)

    minYear = int(input("\nInsert the minimum year: "))
    maxYear = int(input("Insert the maximum year: "))

    data = print(f"\nMaximum and minimum anomaly between {minYear} and {maxYear}: {anomalies(data, minYear, maxYear)}")


if __name__ == "__main__":
    main()