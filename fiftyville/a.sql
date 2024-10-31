SELECT *
FROM crime_scene_reports
WHERE day = 28
AND month = 7
AND year = 2023
AND street = 'Humphrey Street'
AND description LIKE '%duck%';

SELECT *
FROM interviews
WHERE day = 28
AND month = 7
AND year = 2023
AND transcript LIKE '%bakery%';

SELECT city AS ESCAPED_TO
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE day = 29
    ORDER BY hour);

SELECT name AS THIEF
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25)

INTERSECT

SELECT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'))

INTERSECT

SELECT name
FROM people
WHERE phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE day = 28
    AND duration < 60)

INTERSECT

SELECT name
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = (
        SELECT id
        FROM flights
        WHERE day = 29
        ORDER BY hour));

SELECT name AS ACCOMPLICE
FROM people
WHERE phone_number IN (
    SELECT receiver
    FROM phone_calls
    WHERE day = 28
    AND duration < 60
    AND caller = (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
);
