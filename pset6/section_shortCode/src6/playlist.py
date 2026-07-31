from cs50 import get_int
import csv


def main():
    min_tempo = get_int("Minimum tempo: ")
    max_tempo = get_int("Maximum tempo: ")

    filename = "2018_top100.csv"
    playlist = []
    
    with open(filename) as file:
        reader = csv.DictReader(file)
        for row in reader:
            if min_tempo <= float(row["tempo"]) <= max_tempo:
                playlist.append(row["name"])


        for song in playlist:
            print(song)


main()
