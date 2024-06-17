-- Keep a log of any SQL queries you execute as you solve the mystery.

--reading the crime report
SELECT description
FROM crime_scene_reports
WHERE month=7 AND day=28
AND street ='Humphrey Street';

--checking the 3 witnesses
SELECT name, transcript
FROM interviews
WHERE month=7 AND day=28 AND transcript LIKE '%bakery%';

--found that there was a car leaving from the parking lot with the theif and he was at the leggett street to withdraw money and they are leaving tomorrow from fiftyville where the friend is booking the flight

--checking atm transcation records to see the account number, person id and person id for suspects
SELECT atm_transactions.account_number,bank_accounts.person_id, people.name, people.licensce_plate FROM atm_transactions
JOIN bank_accounts ON bank_accounts.account_number=atm_transactions.account_number
JOIN people ON people.id=bank_accounts.person_id
WHERE year=2023 AND month=7 AND day=28 AND atm_location='Leggett Street' AND transaction_type='withdraw';

--checking the security logs to narrow down our search
SELECT DISTINCT people.name, people.id from bakery_security_logs
JOIN people ON people.license_plate=bakery_security_logs.license_plate
WHERE people.license_plate =(
    SELECT people.license_plate FROM people
    JOIN bank_accounts ON people.id=bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
    WHERE atm_transactions.year=2023 AND atm_transactions.month=7 AND atm_transactions.day=28 AND atm_transactions.atm_location='Leggett Street' AND atm_transactions.transaction_type='withdraw'
);

--Theif found as bruce now finding who the phone number of the receiver called to from call logs
SELECT receiver FROM phone_calls
WHERE phone_calls.caller=(SELECT DISTINCT people.phone_number from bakery_security_logs
JOIN people ON people.license_plate=bakery_security_logs.license_plate
WHERE people.license_plate =(
    SELECT people.license_plate FROM people
    JOIN bank_accounts ON people.id=bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
    WHERE atm_transactions.year=2023 AND atm_transactions.month=7 AND atm_transactions.day=28 AND atm_transactions.atm_location='Leggett Street' AND atm_transactions.transaction_type='withdraw'
))
AND year=2023 AND month=7 AND day=28 and duration <60;

--name of the friend who helped bruce
SELECT people.name FROM people
WHERE people.phone_number=(
    SELECT receiver FROM phone_calls
WHERE phone_calls.caller=(SELECT DISTINCT people.phone_number from bakery_security_logs
JOIN people ON people.license_plate=bakery_security_logs.license_plate
WHERE people.license_plate =(
    SELECT people.license_plate FROM people
    JOIN bank_accounts ON people.id=bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
    WHERE atm_transactions.year=2023 AND atm_transactions.month=7 AND atm_transactions.day=28 AND atm_transactions.atm_location='Leggett Street' AND atm_transactions.transaction_type='withdraw'
))
AND year=2023 AND month=7 AND day=28 and duration <60
);

--finding the passport id of the theif
SELECT people.passport_number FROM people
WHERE people.id = (
    SELECT DISTINCT people.id from bakery_security_logs
JOIN people ON people.license_plate=bakery_security_logs.license_plate
WHERE people.license_plate =(
    SELECT people.license_plate FROM people
    JOIN bank_accounts ON people.id=bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
    WHERE atm_transactions.year=2023 AND atm_transactions.month=7 AND atm_transactions.day=28 AND atm_transactions.atm_location='Leggett Street' AND atm_transactions.transaction_type='withdraw'
));

--finding the flight_id of the plane

SELECT passengers.flight_id from passengers
WHERE passengers.passport_number=(SELECT people.passport_number FROM people
WHERE people.id = (
    SELECT DISTINCT people.id from bakery_security_logs
JOIN people ON people.license_plate=bakery_security_logs.license_plate
WHERE people.license_plate =(
    SELECT people.license_plate FROM people
    JOIN bank_accounts ON people.id=bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
    WHERE atm_transactions.year=2023 AND atm_transactions.month=7 AND atm_transactions.day=28 AND atm_transactions.atm_location='Leggett Street' AND atm_transactions.transaction_type='withdraw'
)));

--finding where that plane with id =36 went on the 29/07/2023
SELECT destination_airport_id FROM flights
WHERE id=(
    SELECT passengers.flight_id from passengers
WHERE passengers.passport_number=(SELECT people.passport_number FROM people
WHERE people.id = (
    SELECT DISTINCT people.id from bakery_security_logs
JOIN people ON people.license_plate=bakery_security_logs.license_plate
WHERE people.license_plate =(
    SELECT people.license_plate FROM people
    JOIN bank_accounts ON people.id=bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
    WHERE atm_transactions.year=2023 AND atm_transactions.month=7 AND atm_transactions.day=28 AND atm_transactions.atm_location='Leggett Street' AND atm_transactions.transaction_type='withdraw'
)))
);

SELECT full_name, city from airports
WHERE id=(
    SELECT destination_airport_id FROM flights
WHERE id=(
    SELECT passengers.flight_id from passengers
WHERE passengers.passport_number=(SELECT people.passport_number FROM people
WHERE people.id = (
    SELECT DISTINCT people.id from bakery_security_logs
JOIN people ON people.license_plate=bakery_security_logs.license_plate
WHERE people.license_plate =(
    SELECT people.license_plate FROM people
    JOIN bank_accounts ON people.id=bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
    WHERE atm_transactions.year=2023 AND atm_transactions.month=7 AND atm_transactions.day=28 AND atm_transactions.atm_location='Leggett Street' AND atm_transactions.transaction_type='withdraw'
)))));
