-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE year = 2025 AND month = 7 AND day = 28 AND street = "Humphrey Street"; --Check for reports on cs50 duck theft on given time and place
SELECT name, transcript FROM interviews WHERE year = 2025 AND month = 7 AND day = 28; --Find out who was interviewed on the day of the crime, and what they said.

