
SELECT COUNT(title)
FROM movies
WHERE year = 2008;

SELECT birth AS Emma_birth
FROM people
WHERE name = 'Emma Stone';

SELECT COUNT(title)
FROM movies
WHERE year > 2017
ORDER BY title;

SELECT COUNT(movie_id) AS rating_10
FROM ratings
WHERE rating = 10.0;

SELECT title, year
FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year;

SELECT AVG(rating)
FROM ratings
WHERE movie_id IN (
    SELECT id
    FROM movies
    WHERE year = 2012);

SELECT COUNT(title), rating
FROM ratings
JOIN movies ON movies.id = ratings.movie_id
WHERE year = 2010
AND rating >= 1
ORDER BY rating DESC, title;

SELECT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM stars
    WHERE movie_id = (
        SELECT id
        FROM movies
        WHERE title = 'Toy Story'));

SELECT COUNT(name)
FROM people
WHERE id IN (
    SELECT DISTINCT person_id
    FROM stars
    WHERE movie_id IN (
        SELECT id
        FROM movies
        WHERE year = 2004
    )
)
ORDER BY birth;

SELECT COUNT(name)
FROM people
WHERE id IN (
    SELECT DISTINCT person_id
    FROM directors
    WHERE movie_id IN (
        SELECT movie_id
        FROM ratings
        WHERE rating >= 9
    )
);

SELECT title, rating
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id = (
        SELECT id
        FROM people
        WHERE name = 'Chadwick Boseman'
    )
)
ORDER BY rating DESC
LIMIT 5;

SELECT title
FROM movies
WHERE id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id IN (
        SELECT id
        FROM people
        WHERE name = 'Jennifer Lawrence'
    )
)
INTERSECT

SELECT title
FROM movies
WHERE id IN (
    SELECT movie_id
    FROM stars
    WHERE person_id IN (
        SELECT id
        FROM people
        WHERE name = 'Bradley Cooper'
    )
);

SELECT name
FROM people
WHERE id IN (
    SELECT person_id
    FROM stars
    WHERE movie_id IN (
        SELECT movie_id
        FROM stars
        WHERE person_id = (
            SELECT id
            FROM people
            WHERE name = 'Kevin Bacon'
            AND birth = 1958
        )
    )
)
AND NOT name = 'Kevin Bacon';
