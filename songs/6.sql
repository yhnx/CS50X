SELECT name FROM songs WHERE artist_id = (SELECT artists.id from artists WHERE name='Post Malone' );
