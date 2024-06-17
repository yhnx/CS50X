SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT artists.id from artists WHERE name='Drake' );
