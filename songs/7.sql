SELECT AVG(energy) AS Energy_Drake
FROM songs
WHERE artist_id = (
    SELECT id
    FROM artists
    WHERE name = 'Drake');

