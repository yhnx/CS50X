SELECT distinct title from movies
join stars on stars.movie_id=movies.id
join people on stars.person_id=people.id
join ratings on movies.id = ratings.movie_id
where people.name='Chadwick Boseman'
order by ratings.rating DESC
limit 5;
