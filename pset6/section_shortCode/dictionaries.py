import csv

#with as handles the opening and closing
#of the file automatically, reducing bolierplate code

with open(FILENAME) as file:
    file_reader = csv.DictReader(file)
    for row in file_reader:
        print(row)
